#pragma once

namespace ufio
{

namespace details
{

template <typename FromIter, typename ToIter>
struct bytes_copy_punning_result
{
	FromIter fromiter;
	ToIter toiter;
};

template <typename FromItbg, typename FromIted, typename ToIter>
inline constexpr bytes_copy_punning_result<FromItbg, ToIter>
bytes_copy_punning_impl(FromItbg fromfirst, FromIted fromlast, ToIter tofirst, ToIter tolast)
{
	using fromvaluetype = ::std::iter_value_t<FromItbg>;
	using tovaluetype = ::std::iter_value_t<ToIter>;
	while (fromfirst != fromlast && tofirst != tolast)
	{
		if constexpr (sizeof(fromvaluetype) == sizeof(tovaluetype))
		{
			*tofirst = ::std::bit_cast<tovaluetype>(*fromfirst);
			++tofirst;
		}
		else
		{
			constexpr ::std::size_t quoti{sizeof(fromvaluetype) / sizeof(tovaluetype)};
#if __cpp_if_consteval >= 202106L || __cpp_lib_is_constant_evaluated >= 201811L
#if __cpp_if_consteval >= 202106L
			if consteval
#elif __cpp_lib_is_constant_evaluated >= 201811L
			if (__builtin_is_constant_evaluated())
#endif
			{
				auto arr{::std::bit_cast<::ufio::freestanding::array<fromvaluetype, quoti>>(*fromfirst)};
				::ufio::details::non_overlapped_copy(arr.data(), arr.data() + arr.size(), tofirst);
			}
			else
#endif
			{
				::ufio::freestanding::bytes_copy_n(reinterpret_cast<::std::byte const *>(fromfirst),
													  sizeof(fromvaluetype), reinterpret_cast<::std::byte *>(tofirst));
			}
			tofirst += quoti;
		}
		++fromfirst;
	}
	return {fromfirst, tofirst};
}

template <::std::size_t blocksize, typename outstmtype, typename T1, typename T>
constexpr void write_all_iterator_decay_multiblock_common_impl(outstmtype outsm, T1 **controller_first,
															   T const *firstblock_curr, T const *firstblock_end,
															   T1 **controller_last, T const *lastblock_first,
															   T const *lastblock_curr)
{
	using output_char_type = typename outstmtype::output_char_type;
	using nocref = ::std::remove_cvref_t<T>;
	constexpr bool hasbytesop{
		ufio::operations::decay::defines::has_any_of_write_or_seek_pwrite_bytes_operations<outstmtype>};
	if constexpr (::std::same_as<nocref, output_char_type> || ::std::same_as<nocref, ::std::byte>)
	{
		if (controller_first == controller_last)
		{
			::ufio::operations::decay::write_all_decay(outsm, firstblock_curr, lastblock_curr);
			return;
		}
		using scattertype = ::std::conditional_t<hasbytesop, io_scatter_t, basic_io_scatter_t<output_char_type>>;
		constexpr ::std::size_t multiplier{hasbytesop ? sizeof(nocref) : sizeof(nocref) / sizeof(output_char_type)};
		constexpr ::std::size_t scatternum{64};
		static_assert(1 < scatternum);
		constexpr ::std::size_t blockszbytes{blocksize * multiplier};
		scattertype scatters[scatternum];
		*scatters =
			scattertype{firstblock_curr, static_cast<::std::size_t>(firstblock_end - firstblock_curr) * multiplier};
		scattertype *scatterit{scatters + 1}, *scattered{scatters + scatternum};
		for (++controller_first; controller_first != controller_last; ++controller_first)
		{
			*scatterit = {*controller_first, blockszbytes};
			++scatterit;
			if (scatterit == scattered)
			{
				if constexpr (hasbytesop)
				{
					::ufio::operations::decay::scatter_write_all_bytes_decay(outsm, scatters, scatternum);
				}
				else
				{
					::ufio::operations::decay::scatter_write_all_decay(outsm, scatters, scatternum);
				}
				scatterit = scatters;
			}
		}
		*scatterit =
			scattertype{lastblock_first, static_cast<::std::size_t>(lastblock_curr - lastblock_first) * multiplier};
		++scatterit;
		if constexpr (hasbytesop)
		{
			::ufio::operations::decay::scatter_write_all_bytes_decay(
				outsm, scatters, static_cast<::std::size_t>(scatterit - scatters));
		}
		else
		{
			::ufio::operations::decay::scatter_write_all_decay(outsm, scatters,
																  static_cast<::std::size_t>(scatterit - scatters));
		}
	}
	else
	{
		using type_ptr_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= ::std::conditional_t<hasbytesop, ::std::byte, output_char_type> **;
		using type_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= ::std::conditional_t<hasbytesop, ::std::byte, output_char_type> const *;
		using type_const_ptr_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= type_const_ptr *;
		write_all_iterator_decay_multiblock_common_impl<blocksize>(
			outsm, const_cast<type_const_ptr_ptr>(reinterpret_cast<type_ptr_ptr>(controller_first)),
			reinterpret_cast<type_const_ptr>(firstblock_curr), reinterpret_cast<type_const_ptr>(firstblock_end),
			const_cast<type_const_ptr_ptr>(reinterpret_cast<type_ptr_ptr>(controller_last)),
			reinterpret_cast<type_const_ptr>(lastblock_first), reinterpret_cast<type_const_ptr>(lastblock_curr));
	}
}

template <typename outstmtype, typename Iter, typename Iterlast>
inline constexpr void write_all_iterator_decay_impl(outstmtype outsm, Iter first, Iterlast last)
{
	if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_mutex_ref_define<outstmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::output_stream_mutex_ref_decay(outsm)};
		return ::ufio::details::write_all_iterator_decay_impl(
			::ufio::operations::decay::output_stream_unlocked_ref_decay(outsm), first, last);
	}
	else
	{
		using output_char_type = typename outstmtype::output_char_type;
		using itvt = ::std::iter_value_t<Iter>;
		if constexpr (::ufio::multiblock_view_iterator<Iter>) // Optimize for ::std::deque
		{
			auto firstvit{multiblock_iterator_view_ref_define(first)};
			auto lastvit{multiblock_iterator_view_ref_define(last)};
			::ufio::details::write_all_iterator_decay_multiblock_common_impl<decltype(firstvit)::block_size>(
				outsm, firstvit.controller_ptr, firstvit.block_curr_ptr, firstvit.block_end_ptr, lastvit.controller_ptr,
				lastvit.block_begin_ptr, lastvit.block_curr_ptr);
		}
		else
		{
			constexpr ::std::size_t bfsz{(::std::numeric_limits<::std::size_t>::digits <= 16u ? 64u : 512u) /
										 sizeof(output_char_type)};
			if constexpr (sizeof(output_char_type) * bfsz < sizeof(itvt))
			{
				output_char_type buffer[bfsz];
				for (; first != last;)
				{
					auto [fromiter, toiter] =
						::ufio::details::bytes_copy_punning_impl(first, last, buffer, buffer + bfsz);
					::ufio::operations::decay::write_all_decay(outsm, buffer, toiter);
					first = fromiter;
				}
			}
			else
			{
				for (; first != last; ++first)
				{
					decltype(::std::addressof(*first)) firstaddr;
					if constexpr (::std::contiguous_iterator<Iter>)
					{
						firstaddr = ::std::to_address(first);
					}
					else
					{
						firstaddr = ::std::addressof(*first);
					}
					if constexpr (::std::same_as<output_char_type, itvt>)
					{
						::ufio::operations::decay::write_all_decay(outsm, firstaddr, firstaddr + 1);
					}
					else
					{
						using type_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
							[[__gnu__::__may_alias__]]
#endif
							= output_char_type const *;
						::ufio::operations::decay::write_all_decay(outsm,
																	  reinterpret_cast<type_const_ptr>(firstaddr),
																	  reinterpret_cast<type_const_ptr>(firstaddr + 1));
					}
				}
			}
		}
	}
}

} // namespace details

namespace operations::decay
{

template <typename outstmtype, ::std::ranges::input_range rg>
	requires((::ufio::operations::decay::defines::has_any_of_write_or_seek_pwrite_bytes_operations<outstmtype> ||
			  (::ufio::operations::decay::defines::has_any_of_write_or_seek_pwrite_operations<outstmtype> &&
			   (sizeof(::std::ranges::range_value_t<rg>) % sizeof(typename outstmtype::output_char_type) == 0))) &&
			 ::ufio::freestanding::is_trivially_relocatable_v<::std::ranges::range_value_t<rg>>)
inline constexpr void write_all_range_decay(outstmtype outsm, rg &&r)
{
	using output_char_type = typename outstmtype::output_char_type;
	using rgvlt = ::std::ranges::range_value_t<rg>;
	if constexpr (::std::ranges::contiguous_range<rg>)
	{
		auto firstptr{::std::ranges::cdata(r)};
		auto lastptr{::std::to_address(::std::ranges::cend(r))};
		if constexpr (::ufio::operations::decay::defines::has_any_of_write_or_seek_pwrite_operations<outstmtype> &&
					  (sizeof(rgvlt) % sizeof(output_char_type) == 0))
		{
			if constexpr (::std::same_as<rgvlt, output_char_type>)
			{
				::ufio::operations::decay::write_all_decay(outsm, firstptr, lastptr);
			}
			else
			{
				using type_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
					[[__gnu__::__may_alias__]]
#endif
					= output_char_type const *;
				auto firstptrbt{reinterpret_cast<type_const_ptr>(firstptr)};
				auto lastptrbt{reinterpret_cast<type_const_ptr>(lastptr)};
				::ufio::operations::decay::write_all_decay(outsm, firstptrbt, lastptrbt);
			}
		}
		else
		{
			auto firstptrbt{reinterpret_cast<::std::byte const *>(firstptr)};
			auto lastptrbt{reinterpret_cast<::std::byte const *>(lastptr)};
			::ufio::operations::decay::write_all_bytes_decay(outsm, firstptrbt, lastptrbt);
		}
	}
	else
	{
		::ufio::details::write_all_iterator_decay_impl(outsm, ::std::ranges::cbegin(r), ::std::ranges::cend(r));
	}
}

} // namespace operations::decay

namespace operations
{

template <typename outstmtype, ::std::ranges::input_range R>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void write_all_range(outstmtype &&outstm, R &&r)
{
	::ufio::operations::decay::write_all_range_decay(::ufio::operations::output_stream_ref(outstm),
														::std::forward<R>(r));
}

} // namespace operations

} // namespace ufio
