#pragma once

namespace ufio
{


namespace operations::decay
{
template <typename instmtype>
inline constexpr ::std::byte *read_some_bytes_decay(instmtype insm, ::std::byte *first, ::std::byte *last);

template <typename instmtype>
inline constexpr ::std::byte *pread_some_bytes_decay(instmtype insm, ::std::byte *first, ::std::byte *last,
														  ::ufio::intfpos_t);

} // namespace operations::decay

namespace details
{
template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr io_scatter_status_t scatter_read_some_bytes_cold_impl(instmtype insm, io_scatter_t const *pscatters,
																	   ::std::size_t n);

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void scatter_read_all_bytes_cold_impl(instmtype insm, io_scatter_t const *pscatters, ::std::size_t n);

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void
scatter_read_all_cold_impl(instmtype insm, basic_io_scatter_t<typename instmtype::input_char_type> const *pscatters,
						   ::std::size_t n);

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr io_scatter_status_t
scatter_read_some_cold_impl(instmtype insm, basic_io_scatter_t<typename instmtype::input_char_type> const *pscatters,
							::std::size_t n)
{
	using char_type = typename instmtype::input_char_type;
	if constexpr (::ufio::operations::decay::defines::has_scatter_read_some_underflow_define<instmtype>)
	{
		return scatter_read_some_underflow_define(insm, pscatters, n);
	}
	else if constexpr (::ufio::operations::decay::defines::has_read_some_underflow_define<instmtype>)
	{
		for (::std::size_t i{}; i != n; ++i)
		{
			auto [basec, len] = pscatters[i];
			char_type *base{const_cast<char_type *>(basec)};
			auto ed{base + len};
			auto written{::ufio::details::read_some_impl(insm, base, ed)};
			::std::size_t sz{static_cast<::std::size_t>(written - base)};
			if (sz != len)
			{
				return {i, sz};
			}
		}
		return {n, 0};
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_read_all_underflow_define<instmtype> ||
					   ::ufio::operations::decay::defines::has_read_all_underflow_define<instmtype>)
	{
		scatter_read_all_cold_impl(insm, pscatters, n);
		return {n, 0};
	}
	else if constexpr ((::ufio::operations::decay::defines::has_any_of_read_bytes_operations<instmtype>))
	{
		if constexpr (sizeof(char_type) == 1)
		{
			using scattermayalias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
				[[__gnu__::__may_alias__]]
#endif
				= io_scatter_t const *;
			return ::ufio::details::scatter_read_some_bytes_cold_impl(
				insm, reinterpret_cast<scattermayalias_ptr>(pscatters), n);
		}
		else
		{
			for (::std::size_t i{}; i != n; ++i)
			{
				auto [basefd, len] = pscatters[i];
				char_type *basef{const_cast<char_type *>(basefd)};
				auto edf{basef + len};
				::std::byte *base{reinterpret_cast<::std::byte *>(const_cast<void *>(basef))};
				::std::byte *ed{reinterpret_cast<::std::byte *>(edf)};
				auto readed{::ufio::details::read_some_bytes_impl(insm, base, ed)};
				::std::size_t diff{static_cast<::std::size_t>(readed - base)};
				::std::size_t md{diff % sizeof(char_type)};
				::std::size_t sz{diff / sizeof(char_type)};
				if (md)
				{
					::std::size_t dfd{sizeof(char_type) - md};
					auto readedend{readed + dfd};
					auto it{::ufio::operations::decay::read_some_bytes_decay(insm, readed, readedend)};
					if (it == readedend)
					{
						++sz;
					}
				}
				if (sz != len)
				{
					return {i, sz};
				}
			}
			return {n, 0};
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_define<instmtype> &&
					   (::ufio::operations::decay::defines::has_any_of_pread_operations<instmtype>))
	{
		auto ret{scatter_pread_some_cold_impl(insm, pscatters, n, 0)};
		::ufio::operations::decay::input_stream_seek_decay(insm, fposoffadd_scatters(0, pscatters, ret),
															  ::ufio::seekdir::cur);
		return ret;
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_bytes_define<instmtype> &&
					   (::ufio::operations::decay::defines::has_any_of_pread_bytes_operations<instmtype>))
	{
		auto ret{scatter_pread_some_cold_impl(insm, pscatters, n, 0)};
		::ufio::operations::decay::input_stream_seek_bytes_decay(
			insm, ::ufio::details::scatter_fpos_mul<char_type>(::ufio::fposoffadd_scatters(0, pscatters, ret)),
			::ufio::seekdir::cur);
		return ret;
	}
}

template <typename instmtype>
inline constexpr io_scatter_status_t
scatter_read_some_impl(instmtype insm, basic_io_scatter_t<typename instmtype::input_char_type> const *pscatters,
					   ::std::size_t n)
{
	if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_mutex_ref_define<instmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(insm)};
		return ::ufio::details::scatter_read_some_impl(
			::ufio::operations::decay::input_stream_unlocked_ref_decay(insm), pscatters, n);
	}
	else if constexpr (::ufio::operations::decay::defines::has_ibuffer_basic_operations<instmtype>)
	{
		using char_type = typename instmtype::input_char_type;
		char_type *curr{ibuffer_curr(insm)};
		char_type *ed{ibuffer_end(insm)};

		::std::size_t buffptrdiff{static_cast<::std::size_t>(ed - curr)};

		auto i{pscatters}, e{pscatters + n};
		for (; i != e; ++i)
		{
			auto [base, len] = *i;
			if (len < buffptrdiff)
#if __has_cpp_attribute(likely)
				[[likely]]
#endif
			{
				::ufio::details::non_overlapped_copy_n(curr, len, base);
				curr += len;
				buffptrdiff -= len;
			}
			else
			{
				break;
			}
		}
		ibuffer_set_curr(insm, curr);
		if (i != e)
#if __has_cpp_attribute(unlikely)
			[[unlikely]]
#endif
		{
			auto ret{::ufio::details::scatter_read_some_cold_impl(insm, i, static_cast<::std::size_t>(e - i))};
			ret.position += static_cast<::std::size_t>(i - pscatters);
			return ret;
		}
		return {n, 0};
	}
	else
	{
		return scatter_read_some_cold_impl(insm, pscatters, n);
	}
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void
scatter_read_all_cold_impl(instmtype insm, basic_io_scatter_t<typename instmtype::input_char_type> const *pscatters,
						   ::std::size_t n)
{
	using char_type = typename instmtype::input_char_type;
	if constexpr (::ufio::operations::decay::defines::has_scatter_read_all_underflow_define<instmtype>)
	{
		scatter_read_all_underflow_define(insm, pscatters, n);
	}
	else if constexpr (::ufio::operations::decay::defines::has_read_all_underflow_define<instmtype>)
	{
		for (auto i{pscatters}, e{pscatters + n}; i != e; ++i)
		{
			auto [base, len] = *i;
			::ufio::details::read_all_impl(insm, base, base + len);
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_scatter_read_some_underflow_define<instmtype>)
	{
		for (;;)
		{
			auto ret{::ufio::details::scatter_read_some_impl(insm, pscatters, n)};
			::std::size_t retpos{ret.position};
			if (retpos == n)
			{
				return;
			}
			if (!retpos)
			{
				::ufio::throw_parse_code(::ufio::parse_code::end_of_file);
			}
			::std::size_t pisc{ret.position_in_scatter};
			if (pisc)
			{
				auto pi = pscatters[ret.position];
				::ufio::details::read_all_impl(insm, pi.base + pisc, pi.len);
				++retpos;
			}
			pscatters += retpos;
			n -= retpos;
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_read_some_underflow_define<instmtype>)
	{
		for (auto i{pscatters}, e{pscatters + n}; i != e; ++i)
		{
			auto [base, len] = *i;
			::ufio::details::read_all_impl(insm, base, base + len);
		}
	}
	else if constexpr ((::ufio::operations::decay::defines::has_any_of_read_bytes_operations<instmtype>))
	{
		if constexpr (sizeof(char_type) == 1)
		{
			using scattermayalias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
				[[__gnu__::__may_alias__]]
#endif
				= io_scatter_t *;
			::ufio::details::scatter_read_all_bytes_cold_impl(insm, reinterpret_cast<scattermayalias_ptr>(pscatters),
																 n);
		}
		else
		{
			for (::std::size_t i{}; i != n; ++i)
			{
				auto [basef, len] = pscatters[i];
				auto edf{basef + len};
				::std::byte *base{reinterpret_cast<::std::byte *>(const_cast<void *>(basef))};
				::std::byte *ed{reinterpret_cast<::std::byte *>(edf)};
				::ufio::details::read_all_bytes_impl(insm, base, ed);
			}
		}
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_define<instmtype> &&
					   (::ufio::operations::decay::defines::has_any_of_pread_operations<instmtype>))
	{
		scatter_pread_all_cold_impl(insm, pscatters, n, 0);
		::ufio::operations::decay::input_stream_seek_decay(
			insm, ::ufio::fposoffadd_scatters(0, pscatters, {n, 0}), ::ufio::seekdir::cur);
	}
	else if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_seek_bytes_define<instmtype> &&
					   (::ufio::operations::decay::defines::has_any_of_pread_bytes_operations<instmtype>))
	{
		scatter_pread_all_cold_impl(insm, pscatters, n, 0);
		::ufio::operations::decay::input_stream_seek_bytes_decay(
			insm, ::ufio::details::scatter_fpos_mul<char_type>(::ufio::fposoffadd_scatters(0, pscatters, {n, 0})),
			::ufio::seekdir::cur);
	}
}

template <typename instmtype>
inline constexpr void scatter_read_all_impl(instmtype insm,
											basic_io_scatter_t<typename instmtype::input_char_type> const *pscatters,
											::std::size_t n)
{
	if constexpr (::ufio::operations::decay::defines::has_input_or_io_stream_mutex_ref_define<instmtype>)
	{
		::ufio::operations::decay::stream_ref_decay_lock_guard lg{
			::ufio::operations::decay::input_stream_mutex_ref_decay(insm)};
		return ::ufio::details::scatter_read_all_impl(
			::ufio::operations::decay::input_stream_unlocked_ref_decay(insm), pscatters, n);
	}
	else if constexpr (::ufio::operations::decay::defines::has_ibuffer_basic_operations<instmtype>)
	{
		using char_type = typename instmtype::input_char_type;
		char_type *curr{ibuffer_curr(insm)};
		char_type *ed{ibuffer_end(insm)};

		::std::size_t buffptrdiff{static_cast<::std::size_t>(ed - curr)};

		auto i{pscatters}, e{pscatters + n};
		for (; i != e; ++i)
		{
			auto [base, len] = *i;
			if (len < buffptrdiff)
#if __has_cpp_attribute(likely)
				[[likely]]
#endif
			{
				::ufio::details::non_overlapped_copy_n(curr, len, base);
				curr += len;
				buffptrdiff -= len;
			}
			else
			{
				break;
			}
		}
		ibuffer_set_curr(insm, curr);
		if (i != e)
#if __has_cpp_attribute(unlikely)
			[[unlikely]]
#endif
		{
			return ::ufio::details::scatter_read_all_cold_impl(insm, i, static_cast<::std::size_t>(e - i));
		}
	}
	else
	{
		return ::ufio::details::scatter_read_all_cold_impl(insm, pscatters, n);
	}
}

} // namespace details

} // namespace ufio
