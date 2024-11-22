#pragma once

namespace ufio
{
namespace details
{

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr typename instmtype::input_char_type *
pread_some_cold_impl(instmtype insm, typename instmtype::input_char_type *first,
					 typename instmtype::input_char_type *last, ::ufio::intfpos_t off)
{
	using char_type = typename instmtype::input_char_type;
	if constexpr (::ufio::operations::decay::defines::has_pread_some_underflow_define<instmtype>)
	{
		return pread_some_underflow_define(insm, first, last, off);
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_pread_some_underflow_define<instmtype>)
	{
		::std::size_t len{static_cast<::std::size_t>(last - first)};
		basic_io_scatter_t<char_type> sc{first, len};
		auto status{scatter_pread_some_underflow_define(insm, __builtin_addressof(sc), 1, off)};
		if (!status.position)
		{
			return first + status.position_in_scatter;
		}
		return last;
	}
	else if constexpr (::ufio::operations::decay::defines::has_pread_all_underflow_define<instmtype>)
	{
		pread_all_underflow_define(insm, first, last, off);
		return last;
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_pread_all_underflow_define<instmtype>)
	{
		::std::size_t len{static_cast<::std::size_t>(last - first)};
		basic_io_scatter_t<char_type> sc{first, len};
		return ::ufio::scatter_status_one_size(
				   scatter_pread_all_underflow_define(insm, __builtin_addressof(sc), 1, off), len) +
			   first;
	}
	else if constexpr (::ufio::operations::decay::defines::has_any_of_pread_bytes_operations<instmtype>)
	{
		if constexpr (sizeof(typename instmtype::input_char_type) == 1)
		{
			::std::byte *firstptr{reinterpret_cast<::std::byte *>(first)};
			::std::byte *ptr{pread_some_bytes_cold_impl(insm, firstptr, reinterpret_cast<::std::byte *>(last), off)};
			return ptr - firstptr + first;
		}
		else
		{
			::std::byte *firstptr{reinterpret_cast<::std::byte *>(first)};
			::std::byte *ptr{pread_some_bytes_cold_impl(insm, firstptr, reinterpret_cast<::std::byte *>(last), off)};
			::std::ptrdiff_t ptdf{ptr - firstptr};
			::std::size_t diff{static_cast<::std::size_t>(ptdf)};
			::std::size_t v{diff / sizeof(char_type)};
			::std::size_t remain{diff % sizeof(char_type)};
			if (remain != 0)
			{
				off = ::ufio::fposoffadd_nonegative(off, ptdf);
				auto ptred{ptr + remain};
				auto ptrit{::ufio::operations::decay::pread_some_bytes_decay(insm, ptr, ptred, off)};
				if (ptrit == ptred)
				{
					++v;
				}
				//				pread_all_bytes_cold_impl(insm,ptr,ptr+remain,off);
			}
			return first + v;
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_define<instmtype> &&
					   ::ufio::operations::decay::defines::has_any_of_read_operations<instmtype>)
	{
		auto oldoff{::ufio::operations::decay::input_stream_seek_decay(insm, 0, ::ufio::seekdir::cur)};
		::ufio::operations::decay::input_stream_seek_decay(insm, off, ::ufio::seekdir::beg);
		auto ret{::ufio::details::read_some_impl(insm, first, last)};
		::ufio::operations::decay::input_stream_seek_decay(insm, oldoff, ::ufio::seekdir::beg);
		return ret;
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_bytes_define<instmtype> &&
					   (::ufio::operations::decay::defines::has_any_of_read_bytes_operations<instmtype>))
	{
		auto oldoff{::ufio::operations::decay::input_stream_seek_bytes_decay(insm, 0, ::ufio::seekdir::cur)};
		::ufio::operations::decay::input_stream_seek_bytes_decay(insm, off, ::ufio::seekdir::beg);
		auto ret{::ufio::details::read_some_impl(insm, first, last)};
		::ufio::operations::decay::input_stream_seek_bytes_decay(insm, oldoff, ::ufio::seekdir::beg);
		return ret;
	}
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr ::std::byte *pread_some_bytes_cold_impl(instmtype insm, ::std::byte *first, ::std::byte *last,
														 ::ufio::intfpos_t off)
{
	using char_type = typename instmtype::input_char_type;
	if constexpr (::ufio::operations::decay::defines::has_pread_some_bytes_underflow_define<instmtype>)
	{
		return pread_some_bytes_underflow_define(insm, first, last, off);
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_pread_some_bytes_underflow_define<instmtype>)
	{
		::std::size_t len{static_cast<::std::size_t>(last - first)};
		io_scatter_t sc{first, len};
		return ::ufio::scatter_status_one_size(
				   scatter_pread_some_bytes_underflow_define(insm, __builtin_addressof(sc), 1, off), len) +
			   first;
	}
	else if constexpr (sizeof(char_type) == 1 &&
					   (::ufio::operations::decay::defines::has_pread_some_underflow_define<instmtype>))
	{
		using char_type_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= char_type *;
		return ::ufio::details::pread_some_cold_impl(insm, reinterpret_cast<char_type_ptr>(first),
														reinterpret_cast<char_type_ptr>(last), off);
	}
	else if constexpr (sizeof(char_type) == 1 &&
					   ::ufio::operations::decay::defines::has_scatter_pread_some_underflow_define<instmtype>)
	{
		using char_type_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= char_type *;
		::std::size_t len{static_cast<::std::size_t>(last - first)};
		basic_io_scatter_t<char_type> sc{reinterpret_cast<char_type_ptr>(first), len};
		return ::ufio::scatter_status_one_size(
				   scatter_pread_some_bytes_underflow_define(insm, __builtin_addressof(sc), 1, off), len) +
			   first;
	}
	else if constexpr (::ufio::operations::decay::defines::has_pread_all_bytes_underflow_define<instmtype>)
	{
		pread_all_bytes_underflow_define(insm, first, last, off);
		return last;
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_pread_all_bytes_underflow_define<instmtype>)
	{
		io_scatter_t sc{first, static_cast<::std::size_t>(last - first)};
		scatter_pread_all_bytes_underflow_define(insm, __builtin_addressof(sc), 1, off);
		return last;
	}
	else if constexpr (sizeof(char_type) == 1 &&
					   ::ufio::operations::decay::defines::has_pread_all_underflow_define<instmtype>)
	{
		using char_type_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= char_type *;
		pread_all_underflow_define(insm, reinterpret_cast<char_type_ptr>(first), reinterpret_cast<char_type_ptr>(last),
								   off);
		return last;
	}
	else if constexpr (sizeof(char_type) == 1 &&
					   ::ufio::operations::decay::defines::has_scatter_pread_all_underflow_define<instmtype>)
	{
		io_scatter_t sc{first, static_cast<::std::size_t>(last - first)};
		scatter_pread_all_bytes_underflow_define(insm, __builtin_addressof(sc), 1, off);
		return last;
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_bytes_define<instmtype> &&
					   (::ufio::operations::decay::defines::has_any_of_read_bytes_operations<instmtype>))
	{
		auto oldoff{::ufio::operations::decay::input_stream_seek_bytes_decay(insm, 0, ::ufio::seekdir::cur)};
		::ufio::operations::decay::input_stream_seek_bytes_decay(insm, off, ::ufio::seekdir::beg);
		auto ret{::ufio::details::read_some_bytes_impl(insm, first, last)};
		::ufio::operations::decay::input_stream_seek_bytes_decay(insm, oldoff, ::ufio::seekdir::beg);
		return ret;
	}
	else if constexpr (sizeof(char_type) == 1 &&
					   ::ufio::operations::decay::defines::has_input_or_io_stream_seek_define<instmtype> &&
					   ::ufio::operations::decay::defines::has_any_of_read_operations<instmtype>)
	{
		auto oldoff{::ufio::operations::decay::input_stream_seek_decay(insm, 0, ::ufio::seekdir::cur)};
		::ufio::operations::decay::input_stream_seek_decay(insm, off, ::ufio::seekdir::beg);
		auto ret{::ufio::details::read_some_impl(insm, first, last)};
		::ufio::operations::decay::input_stream_seek_decay(insm, oldoff, ::ufio::seekdir::beg);
		return ret;
	}
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void pread_all_cold_impl(instmtype insm, typename instmtype::input_char_type *first,
										  typename instmtype::input_char_type *last, ::ufio::intfpos_t off)
{
	using char_type = typename instmtype::input_char_type;
	if constexpr (::ufio::operations::decay::defines::has_pread_all_underflow_define<instmtype>)
	{
		pread_all_underflow_define(insm, first, last, off);
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_pread_all_underflow_define<instmtype>)
	{
		::std::size_t len{static_cast<::std::size_t>(last - first)};
		basic_io_scatter_t<char_type> sc{first, len};
		scatter_pread_all_underflow_define(insm, __builtin_addressof(sc), 1, off);
	}
	else if constexpr (::ufio::operations::decay::defines::has_pread_some_underflow_define<instmtype>)
	{
		for (;;)
		{
			auto nit{pread_some_underflow_define(insm, first, last, off)};
			off = ::ufio::fposoffadd_nonegative(off, nit - first);
			if (nit == last)
			{
				return;
			}
			if (nit == first)
			{
				::ufio::throw_parse_code(::ufio::parse_code::end_of_file);
			}
			first = nit;
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_pread_some_underflow_define<instmtype>)
	{
		for (;;)
		{
			::std::size_t len{static_cast<::std::size_t>(last - first)};
			basic_io_scatter_t<char_type> sc{first, len};
			auto ret{scatter_pread_some_bytes_underflow_define(insm, __builtin_addressof(sc), 1, off)};
			auto nit{first + ::ufio::scatter_status_one_size(ret, len)};
			off = ::ufio::fposoffadd_nonegative(off, nit - first);
			if (nit == last)
			{
				return;
			}
			if (nit == first)
			{
				::ufio::throw_parse_code(::ufio::parse_code::end_of_file);
			}
			first = nit;
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_any_of_pread_bytes_operations<instmtype>)
	{
		pread_all_bytes_cold_impl(insm, reinterpret_cast<::std::byte *>(first), reinterpret_cast<::std::byte *>(last),
								  off);
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_define<instmtype> &&
					   ::ufio::operations::decay::defines::has_any_of_read_operations<instmtype>)
	{
		auto oldoff{::ufio::operations::decay::input_stream_seek_decay(insm, 0, ::ufio::seekdir::cur)};
		::ufio::operations::decay::input_stream_seek_decay(insm, off, ::ufio::seekdir::beg);
		::ufio::details::read_all_bytes_impl(insm, first, last);
		::ufio::operations::decay::input_stream_seek_decay(insm, oldoff, ::ufio::seekdir::beg);
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_bytes_define<instmtype> &&
					   (::ufio::operations::decay::defines::has_any_of_read_bytes_operations<instmtype>))
	{
		auto oldoff{::ufio::operations::decay::input_stream_seek_bytes_decay(insm, 0, ::ufio::seekdir::cur)};
		::ufio::operations::decay::input_stream_seek_bytes_decay(insm, off, ::ufio::seekdir::beg);
		::ufio::details::read_all_bytes_impl(insm, first, last);
		::ufio::operations::decay::input_stream_seek_bytes_decay(insm, oldoff, ::ufio::seekdir::beg);
	}
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void pread_all_bytes_cold_impl(instmtype insm, ::std::byte *first, ::std::byte *last,
												::ufio::intfpos_t off)
{
	using char_type = typename instmtype::input_char_type;
	if constexpr (::ufio::operations::decay::defines::has_pread_all_bytes_underflow_define<instmtype>)
	{
		pread_all_bytes_underflow_define(insm, first, last, off);
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_pread_all_bytes_underflow_define<instmtype>)
	{
		io_scatter_t sc{first, static_cast<::std::size_t>(last - first)};
		scatter_pread_all_bytes_underflow_define(insm, __builtin_addressof(sc), 1, off);
	}
	else if constexpr (::ufio::operations::decay::defines::has_pread_some_bytes_underflow_define<instmtype>)
	{
		while (first != last)
		{
			auto nit{pread_some_bytes_underflow_define(insm, first, last, off)};
			if (nit == last)
			{
				return;
			}
			if (nit == first)
			{
				::ufio::throw_parse_code(::ufio::parse_code::end_of_file);
			}
			off = ::ufio::fposoffadd_nonegative(off, nit - first);
			first = nit;
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_pread_some_bytes_underflow_define<instmtype>)
	{
		for (;;)
		{
			::std::size_t len{static_cast<::std::size_t>(last - first)};
			io_scatter_t sc{first, len};
			::std::size_t sz{::ufio::scatter_status_one_size(
				scatter_pread_some_bytes_underflow_define(insm, __builtin_addressof(sc), 1, off), len)};
			auto nit = first + sz;
			if (nit == last)
			{
				return;
			}
			if (nit == first)
			{
				::ufio::throw_parse_code(::ufio::parse_code::end_of_file);
			}
			off = ::ufio::fposoffadd_nonegative(off, sz);
			first = nit;
		}
	}
	else if constexpr (sizeof(char_type) == 1 &&
					   ::ufio::operations::decay::defines::has_any_of_pread_operations<instmtype>)
	{
		using char_type_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= char_type *;
		char_type_ptr firstcptr{reinterpret_cast<char_type_ptr>(first)};
		char_type_ptr lastcptr{reinterpret_cast<char_type_ptr>(last)};
		::ufio::details::pread_all_cold_impl(insm, firstcptr, lastcptr, off);
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_bytes_define<instmtype> &&
					   ::ufio::operations::decay::defines::has_any_of_read_bytes_operations<instmtype>)
	{
		auto oldoff{::ufio::operations::decay::input_stream_seek_bytes_decay(insm, 0, ::ufio::seekdir::cur)};
		::ufio::operations::decay::input_stream_seek_bytes_decay(insm, off, ::ufio::seekdir::beg);
		::ufio::details::read_all_bytes_impl(insm, first, last);
		::ufio::operations::decay::input_stream_seek_bytes_decay(insm, oldoff, ::ufio::seekdir::beg);
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_define<instmtype> &&
					   ::ufio::operations::decay::defines::has_any_of_read_operations<instmtype>)
	{
		auto oldoff{::ufio::operations::decay::input_stream_seek_decay(insm, 0, ::ufio::seekdir::cur)};
		::ufio::operations::decay::input_stream_seek_decay(insm, off, ::ufio::seekdir::beg);
		::ufio::details::read_all_bytes_impl(insm, first, last);
		::ufio::operations::decay::input_stream_seek_decay(insm, oldoff, ::ufio::seekdir::beg);
	}
}

template <typename instmtype>
inline constexpr typename instmtype::input_char_type *
pread_some_impl(instmtype insm, typename instmtype::input_char_type *first, typename instmtype::input_char_type *last,
				::ufio::intfpos_t off)
{
	if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_mutex_ref_define<instmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(insm)};
		return ::ufio::details::pread_some_impl(::ufio::operations::decay::input_stream_unlocked_ref_decay(insm),
												   first, last, off);
	}
	else
	{
		return ::ufio::details::pread_some_cold_impl(insm, first, last, off);
	}
}

template <typename instmtype>
inline constexpr void pread_all_impl(instmtype insm, typename instmtype::input_char_type *first,
									 typename instmtype::input_char_type *last, ::ufio::intfpos_t off)
{
	if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_mutex_ref_define<instmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(insm)};
		return ::ufio::details::pread_all_impl(::ufio::operations::decay::input_stream_unlocked_ref_decay(insm),
												  first, last, off);
	}
	else
	{
		::ufio::details::pread_all_cold_impl(insm, first, last, off);
	}
}

template <typename instmtype>
inline constexpr ::std::byte *pread_some_bytes_impl(instmtype insm, ::std::byte *first, ::std::byte *last,
													::ufio::intfpos_t off)
{
	if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_mutex_ref_define<instmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(insm)};
		return ::ufio::details::pread_some_bytes_impl(
			::ufio::operations::decay::input_stream_unlocked_ref_decay(insm), first, last, off);
	}
	else
	{
		return ::ufio::details::pread_some_bytes_cold_impl(insm, first, last, off);
	}
}

template <typename instmtype>
inline constexpr void pread_all_bytes_impl(instmtype insm, ::std::byte *first, ::std::byte *last,
										   ::ufio::intfpos_t off)
{
	if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_mutex_ref_define<instmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(insm)};
		return ::ufio::details::pread_all_bytes_impl(
			::ufio::operations::decay::input_stream_unlocked_ref_decay(insm), first, last, off);
	}
	else
	{
		::ufio::details::pread_all_bytes_cold_impl(insm, first, last, off);
	}
}

} // namespace details

} // namespace ufio
