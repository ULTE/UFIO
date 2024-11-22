#pragma once

namespace ufio
{

namespace details
{
template <typename outstmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr io_scatter_status_t scatter_pwrite_some_bytes_cold_impl(outstmtype outsm,
																		 io_scatter_t const *pscatters, ::std::size_t n,
																		 ::ufio::intfpos_t off);

template <typename outstmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void scatter_pwrite_all_bytes_cold_impl(outstmtype outsm, io_scatter_t const *pscatters,
														 ::std::size_t n, ::ufio::intfpos_t off);

template <typename outstmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr io_scatter_status_t
scatter_pwrite_some_cold_impl(outstmtype outsm,
							  basic_io_scatter_t<typename outstmtype::output_char_type> const *pscatters,
							  ::std::size_t n, ::ufio::intfpos_t off)
{
	using char_type = typename outstmtype::output_char_type;
	if constexpr (::ufio::operations::decay::defines::has_scatter_pwrite_some_overflow_define<outstmtype>)
	{
		return scatter_pwrite_some_overflow_define(outsm, pscatters, n);
	}
	else if constexpr (::ufio::operations::decay::defines::has_pwrite_some_overflow_define<outstmtype>)
	{
		for (::std::size_t i{}; i != n; ++i)
		{
			auto [base, len] = pscatters[i];
			auto ed{base + len};
			auto written{::ufio::details::pwrite_some_impl(outsm, base, ed)};
			::std::size_t sz{static_cast<::std::size_t>(written - base)};
			if (sz != len)
			{
				return {i, sz};
			}
		}
		return {n, 0};
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_pwrite_all_overflow_define<outstmtype> ||
					   ::ufio::operations::decay::defines::has_pwrite_all_overflow_define<outstmtype>)
	{
		::ufio::details::scatter_pwrite_all_bytes_cold_impl(outsm, pscatters, n, off);
		return {n, 0};
	}
	else
#if 0
		if constexpr ((::ufio::operations::decay::defines::has_pwrite_all_bytes_overflow_define<outstmtype> ||
#endif
	/*
	 * The implementation of synthesizing pwrite through write+seek is missing
	 */
	{
		if constexpr (sizeof(char_type) == 1)
		{
			using scattermayalias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
				[[__gnu__::__may_alias__]]
#endif
				= io_scatter_t const *;
			return ::ufio::details::scatter_pwrite_some_bytes_cold_impl(
				outsm, reinterpret_cast<scattermayalias_const_ptr>(pscatters), n, off);
		}
		else
		{
			for (::std::size_t i{}; i != n; ++i)
			{
				auto [basef, len] = pscatters[i];
				auto edf{basef + len};
				::std::byte const *base{reinterpret_cast<::std::byte const *>(basef)};
				::std::byte const *ed{reinterpret_cast<::std::byte const *>(edf)};
				auto written{::ufio::details::pwrite_some_bytes_impl(outsm, base, ed, off)};
				::std::size_t diff{static_cast<::std::size_t>(written - base)};
				off = ::ufio::fposoffadd_nonegative(off, diff);
				::std::size_t md{diff % sizeof(char_type)};
				::std::size_t sz{diff / sizeof(char_type)};
				if (md)
				{
					::std::size_t dfd{sizeof(char_type) - md};
					::ufio::details::pwrite_all_bytes_impl(outsm, written, written + dfd, off);
					off = ::ufio::fposoffadd_nonegative(off, dfd);
					++sz;
				}
				if (sz != len)
				{
					return {i, sz};
				}
			}
			return {n, 0};
		}
	}
}

template <typename outstmtype>
inline constexpr io_scatter_status_t
scatter_pwrite_some_impl(outstmtype outsm, basic_io_scatter_t<typename outstmtype::output_char_type> const *pscatters,
						 ::std::size_t n, ::ufio::intfpos_t off)
{
	if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_mutex_ref_define<outstmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::output_stream_mutex_ref_decay(outsm)};
		return ::ufio::details::scatter_pwrite_some_impl(
			::ufio::operations::decay::output_stream_unlocked_ref_decay(outsm), pscatters, n);
	}
	else
	{
		if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_buffer_flush_define<outstmtype>)
		{
			::ufio::operations::decay::output_stream_buffer_flush_decay(outsm);
		}
		return ::ufio::details::scatter_pwrite_some_cold_impl(outsm, pscatters, n, off);
	}
}

template <typename outstmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void
scatter_pwrite_all_cold_impl(outstmtype outsm,
							 basic_io_scatter_t<typename outstmtype::output_char_type> const *pscatters,
							 ::std::size_t n, ::ufio::intfpos_t off)
{
	if constexpr (::ufio::operations::decay::defines::has_scatter_pwrite_all_overflow_define<outstmtype>)
	{
		scatter_pwrite_all_overflow_define(outsm, pscatters, n);
	}
	else if constexpr (::ufio::operations::decay::defines::has_pwrite_all_overflow_define<outstmtype>)
	{
		for (auto i{pscatters}, e{pscatters + n}; i != e; ++i)
		{
			auto [base, len] = *i;
			::ufio::details::pwrite_all_impl(outsm, base, base + len, off);
			off = ::ufio::fposoffadd_nonegative(off, len);
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_pwrite_some_overflow_define<outstmtype>)
	{
		for (;;)
		{
			auto ret{::ufio::details::scatter_pwrite_some_impl(outsm, pscatters, n, off)};
			::std::size_t retpos{ret.position};
			if (retpos == n)
			{
				return;
			}
			off = ::ufio::fposoffadd_scatters(off, pscatters, ret);
			::std::size_t pisc{ret.position_in_scatter};
			if (pisc)
			{
				auto pi = pscatters[ret.position];
				::ufio::details::pwrite_all_impl(outsm, pi.base + pisc, pi.base + pi.len, off);
				off = ::ufio::fposoffadd_nonegative(off, pi.len - pisc);
				++retpos;
			}
			pscatters += retpos;
			n -= retpos;
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_pwrite_some_overflow_define<outstmtype>)
	{
		for (auto i{pscatters}, e{pscatters + n}; i != e; ++i)
		{
			auto [base, len] = *i;
			::ufio::details::pwrite_all_impl(outsm, base, base + len, off);
			off = ::ufio::fposoffadd_nonegative(off, len);
		}
	}
	else
#if 0
if constexpr ((::ufio::operations::decay::defines::has_pwrite_all_bytes_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_pwrite_all_bytes_overflow_define<
							outstmtype> ||
						::ufio::operations::decay::defines::has_pwrite_some_bytes_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_pwrite_some_bytes_overflow_define<
							outstmtype>))
#endif
	/*
	 * The implementation of synthesizing pwrite through write+seek is missing
	 */
	{
		using char_type = typename outstmtype::output_char_type;
		if constexpr (sizeof(char_type) == 1)
		{
			using scattermayalias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
				[[__gnu__::__may_alias__]]
#endif
				= io_scatter_t const *;
			::ufio::details::scatter_pwrite_all_bytes_cold_impl(
				outsm, reinterpret_cast<scattermayalias_const_ptr>(pscatters), n, off);
		}
		else
		{
			for (::std::size_t i{}; i != n; ++i)
			{
				auto [basef, len] = pscatters[i];
				auto edf{basef + len};
				::std::byte const *base{reinterpret_cast<::std::byte const *>(basef)};
				::std::byte const *ed{reinterpret_cast<::std::byte const *>(edf)};
				::ufio::details::pwrite_all_bytes_impl(outsm, base, ed, off);
				off = ::ufio::fposoffadd_nonegative(off, len);
			}
		}
	}
}

template <typename outstmtype>
inline constexpr void
scatter_pwrite_all_impl(outstmtype outsm, basic_io_scatter_t<typename outstmtype::output_char_type> const *pscatters,
						::std::size_t n, ::ufio::intfpos_t off)
{
	if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_mutex_ref_define<outstmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::output_stream_mutex_ref_decay(outsm)};
		return ::ufio::details::scatter_pwrite_all_impl(
			::ufio::operations::decay::output_stream_unlocked_ref_decay(outsm), pscatters, n);
	}
	else
	{
		if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_buffer_flush_define<outstmtype>)
		{
			::ufio::operations::decay::output_stream_buffer_flush_decay(outsm);
		}
		return ::ufio::details::scatter_pwrite_all_cold_impl(outsm, pscatters, n, off);
	}
}

} // namespace details

} // namespace ufio
