#pragma once

namespace ufio
{

namespace details
{
template <typename outstmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr io_scatter_status_t scatter_write_some_bytes_cold_impl(outstmtype outsm, io_scatter_t const *pscatters,
																		::std::size_t n);

template <typename outstmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void scatter_write_all_bytes_cold_impl(outstmtype outsm, io_scatter_t const *pscatters,
														::std::size_t n);

template <typename outstmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void scatter_write_all_cold_impl(
	outstmtype outsm, basic_io_scatter_t<typename outstmtype::output_char_type> const *pscatters, ::std::size_t n);

template <typename outstmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr io_scatter_status_t scatter_write_some_cold_impl(
	outstmtype outsm, basic_io_scatter_t<typename outstmtype::output_char_type> const *pscatters, ::std::size_t n)
{
	using char_type = typename outstmtype::output_char_type;
	if constexpr (::ufio::operations::decay::defines::has_scatter_write_some_overflow_define<outstmtype>)
	{
		return scatter_write_some_overflow_define(outsm, pscatters, n);
	}
	else if constexpr (::ufio::operations::decay::defines::has_write_some_overflow_define<outstmtype>)
	{
		for (::std::size_t i{}; i != n; ++i)
		{
			auto [base, len] = pscatters[i];
			auto ed{base + len};
			auto written{::ufio::details::write_some_impl(outsm, base, ed)};
			::std::size_t sz{static_cast<::std::size_t>(written - base)};
			if (sz != len)
			{
				return {i, sz};
			}
		}
		return {n, 0};
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_write_all_overflow_define<outstmtype> ||
					   ::ufio::operations::decay::defines::has_write_all_overflow_define<outstmtype>)
	{
		scatter_write_all_cold_impl(outsm, pscatters, n);
		return {n, 0};
	}
	else if constexpr ((::ufio::operations::decay::defines::has_write_all_bytes_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_write_all_bytes_overflow_define<
							outstmtype> ||
						::ufio::operations::decay::defines::has_write_some_bytes_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_write_some_bytes_overflow_define<
							outstmtype>))
	{
		if constexpr (sizeof(char_type) == 1)
		{
			using scattermayalias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
				[[__gnu__::__may_alias__]]
#endif
				= io_scatter_t const *;
			return ::ufio::details::scatter_write_some_bytes_cold_impl(
				outsm, reinterpret_cast<scattermayalias_const_ptr>(pscatters), n);
		}
		else
		{
			for (::std::size_t i{}; i != n; ++i)
			{
				auto [basef, len] = pscatters[i];
				auto edf{basef + len};
				::std::byte const *base{reinterpret_cast<::std::byte const *>(basef)};
				::std::byte const *ed{reinterpret_cast<::std::byte const *>(edf)};
				auto written{::ufio::details::write_some_bytes_impl(outsm, base, ed)};
				::std::size_t diff{static_cast<::std::size_t>(written - base)};
				::std::size_t md{diff % sizeof(char_type)};
				::std::size_t sz{diff / sizeof(char_type)};
				if (md)
				{
					::std::size_t dfd{sizeof(char_type) - md};
					::ufio::details::write_all_bytes_impl(outsm, written, written + dfd);
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
	else if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_seek_define<outstmtype> &&
					   (::ufio::operations::decay::defines::has_pwrite_all_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_pwrite_all_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_pwrite_some_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_pwrite_some_overflow_define<outstmtype>))
	{
		auto ret{scatter_pwrite_some_cold_impl(outsm, pscatters, n, 0)};
		::ufio::operations::decay::output_stream_seek_decay(outsm, fposoffadd_scatters(0, pscatters, ret),
															   ::ufio::seekdir::cur);
		return ret;
	}
	else if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_seek_bytes_define<outstmtype> &&
					   (::ufio::operations::decay::defines::has_pwrite_all_bytes_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_pwrite_all_bytes_overflow_define<
							outstmtype> ||
						::ufio::operations::decay::defines::has_pwrite_some_bytes_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_pwrite_some_bytes_overflow_define<
							outstmtype>))
	{
		auto ret{scatter_pwrite_some_cold_impl(outsm, pscatters, n, 0)};
		::ufio::operations::decay::output_stream_seek_bytes_decay(
			outsm, ::ufio::details::scatter_fpos_mul<char_type>(::ufio::fposoffadd_scatters(0, pscatters, ret)),
			::ufio::seekdir::cur);
		return ret;
	}
}

template <typename outstmtype>
inline constexpr io_scatter_status_t
scatter_write_some_impl(outstmtype outsm, basic_io_scatter_t<typename outstmtype::output_char_type> const *pscatters,
						::std::size_t n)
{
	if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_mutex_ref_define<outstmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::output_stream_mutex_ref_decay(outsm)};
		return ::ufio::details::scatter_write_some_impl(
			::ufio::operations::decay::output_stream_unlocked_ref_decay(outsm), pscatters, n);
	}
	else if constexpr (::ufio::operations::decay::defines::has_obuffer_basic_operations<outstmtype>)
	{
		using char_type = typename outstmtype::output_char_type;
		char_type *curr{obuffer_curr(outsm)};
		char_type *ed{obuffer_end(outsm)};

		::std::size_t buffptrdiff;
		if constexpr (::ufio::operations::decay::defines::has_obuffer_is_line_buffering_define<outstmtype>)
		{
			::std::ptrdiff_t pptrdf{ed - curr};
			if (pptrdf < 0)
			{
				pptrdf = 0;
			}
			buffptrdiff = static_cast<::std::size_t>(pptrdf);
		}
		else
		{
			buffptrdiff = static_cast<::std::size_t>(ed - curr);
		}

		auto i{pscatters}, e{pscatters + n};
		for (; i != e; ++i)
		{
			auto [base, len] = *i;
			if (len < buffptrdiff)
#if __has_cpp_attribute(likely)
				[[likely]]
#endif
			{
				curr = ::ufio::details::non_overlapped_copy_n(base, len, curr);
				buffptrdiff -= len;
			}
			else
			{
				break;
			}
		}
		obuffer_set_curr(outsm, curr);
		if (i != e)
#if __has_cpp_attribute(unlikely)
			[[unlikely]]
#endif
		{
			auto ret{::ufio::details::scatter_write_some_cold_impl(outsm, i, static_cast<::std::size_t>(e - i))};
			ret.position += static_cast<::std::size_t>(i - pscatters);
			return ret;
		}
		return {n, 0};
	}
	else
	{
		return scatter_write_some_cold_impl(outsm, pscatters, n);
	}
}

template <typename outstmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void
scatter_write_all_cold_impl(outstmtype outsm,
							basic_io_scatter_t<typename outstmtype::output_char_type> const *pscatters, ::std::size_t n)
{
	using char_type = typename outstmtype::output_char_type;
	if constexpr (::ufio::operations::decay::defines::has_scatter_write_all_overflow_define<outstmtype>)
	{
		scatter_write_all_overflow_define(outsm, pscatters, n);
	}
	else if constexpr (::ufio::operations::decay::defines::has_write_all_overflow_define<outstmtype>)
	{
		for (auto i{pscatters}, e{pscatters + n}; i != e; ++i)
		{
			auto [base, len] = *i;
			::ufio::details::write_all_impl(outsm, base, base + len);
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_write_some_overflow_define<outstmtype>)
	{
		for (;;)
		{
			auto ret{::ufio::details::scatter_write_some_impl(outsm, pscatters, n)};
			::std::size_t retpos{ret.position};
			if (retpos == n)
			{
				return;
			}
			::std::size_t pisc{ret.position_in_scatter};
			if (pisc)
			{
				auto pi = pscatters[ret.position];
				::ufio::details::write_all_impl(outsm, pi.base + pisc, pi.base + pi.len);
				++retpos;
			}
			pscatters += retpos;
			n -= retpos;
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_write_some_overflow_define<outstmtype>)
	{
		for (auto i{pscatters}, e{pscatters + n}; i != e; ++i)
		{
			auto [base, len] = *i;
			::ufio::details::write_all_impl(outsm, base, base + len);
		}
	}
	else if constexpr ((::ufio::operations::decay::defines::has_write_all_bytes_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_write_all_bytes_overflow_define<
							outstmtype> ||
						::ufio::operations::decay::defines::has_write_some_bytes_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_write_some_bytes_overflow_define<
							outstmtype>))
	{
		if constexpr (sizeof(char_type) == 1)
		{
			using scattermayalias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
				[[__gnu__::__may_alias__]]
#endif
				= io_scatter_t const *;
			::ufio::details::scatter_write_all_bytes_cold_impl(
				outsm, reinterpret_cast<scattermayalias_const_ptr>(pscatters), n);
		}
		else
		{
			for (::std::size_t i{}; i != n; ++i)
			{
				auto [basef, len] = pscatters[i];
				auto edf{basef + len};
				::std::byte const *base{reinterpret_cast<::std::byte const *>(basef)};
				::std::byte const *ed{reinterpret_cast<::std::byte const *>(edf)};
				::ufio::details::write_all_bytes_impl(outsm, base, ed);
			}
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_seek_define<outstmtype> &&
					   (::ufio::operations::decay::defines::has_pwrite_all_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_pwrite_all_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_pwrite_some_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_pwrite_some_overflow_define<outstmtype>))
	{
		scatter_pwrite_all_cold_impl(outsm, pscatters, n, 0);
		::ufio::operations::decay::output_stream_seek_decay(
			outsm, ::ufio::fposoffadd_scatters(0, pscatters, {n, 0}), ::ufio::seekdir::cur);
	}
	else if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_seek_bytes_define<outstmtype> &&
					   (::ufio::operations::decay::defines::has_pwrite_all_bytes_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_pwrite_all_bytes_overflow_define<
							outstmtype> ||
						::ufio::operations::decay::defines::has_pwrite_some_bytes_overflow_define<outstmtype> ||
						::ufio::operations::decay::defines::has_scatter_pwrite_some_bytes_overflow_define<
							outstmtype>))
	{
		scatter_pwrite_all_cold_impl(outsm, pscatters, n, 0);
		::ufio::operations::decay::output_stream_seek_bytes_decay(
			outsm,
			::ufio::details::scatter_fpos_mul<char_type>(::ufio::fposoffadd_scatters(0, pscatters, {n, 0})),
			::ufio::seekdir::cur);
	}
}

template <typename outstmtype>
inline constexpr void scatter_write_all_impl(outstmtype outsm,
											 basic_io_scatter_t<typename outstmtype::output_char_type> const *pscatters,
											 ::std::size_t n)
{
	if constexpr (::ufio::operations::decay::defines::has_output_or_io_stream_mutex_ref_define<outstmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::output_stream_mutex_ref_decay(outsm)};
		return ::ufio::details::scatter_write_all_impl(
			::ufio::operations::decay::output_stream_unlocked_ref_decay(outsm), pscatters, n);
	}
	else if constexpr (::ufio::operations::decay::defines::has_obuffer_basic_operations<outstmtype>)
	{
		using char_type = typename outstmtype::output_char_type;
		char_type *curr{obuffer_curr(outsm)};
		char_type *ed{obuffer_end(outsm)};

		::std::size_t buffptrdiff;
		if constexpr (::ufio::operations::decay::defines::has_obuffer_is_line_buffering_define<outstmtype>)
		{
			::std::ptrdiff_t pptrdf{ed - curr};
			if (pptrdf < 0)
			{
				pptrdf = 0;
			}
			buffptrdiff = static_cast<::std::size_t>(pptrdf);
		}
		else
		{
			buffptrdiff = static_cast<::std::size_t>(ed - curr);
		}

		auto i{pscatters}, e{pscatters + n};
		for (; i != e; ++i)
		{
			auto [base, len] = *i;
			if (len < buffptrdiff)
#if __has_cpp_attribute(likely)
				[[likely]]
#endif
			{
				curr = ::ufio::details::non_overlapped_copy_n(base, len, curr);
				buffptrdiff -= len;
			}
			else
			{
				break;
			}
		}
		obuffer_set_curr(outsm, curr);
		if (i != e)
#if __has_cpp_attribute(unlikely)
			[[unlikely]]
#endif
		{
			return ::ufio::details::scatter_write_all_cold_impl(outsm, i, static_cast<::std::size_t>(e - i));
		}
	}
	else
	{
		return ::ufio::details::scatter_write_all_cold_impl(outsm, pscatters, n);
	}
}

} // namespace details

} // namespace ufio
