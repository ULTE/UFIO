﻿#pragma once

namespace ufio::operations::decay
{

template <typename instmtype>
inline constexpr typename instmtype::input_char_type *
read_some_decay(instmtype insm, typename instmtype::input_char_type *first, typename instmtype::input_char_type *last)
{
	return ::ufio::details::read_some_impl(insm, first, last);
}

template <typename instmtype>
inline constexpr void read_all_decay(instmtype insm, typename instmtype::input_char_type *first,
									 typename instmtype::input_char_type *last)
{
	::ufio::details::read_all_impl(insm, first, last);
}

template <typename instmtype>
inline constexpr ::std::byte *read_some_bytes_decay(instmtype insm, ::std::byte *first, ::std::byte *last)
{
	return ::ufio::details::read_some_bytes_impl(insm, first, last);
}

template <typename instmtype>
inline constexpr void read_all_bytes_decay(instmtype insm, ::std::byte *first, ::std::byte *last)
{
	::ufio::details::read_all_bytes_impl(insm, first, last);
}

template <typename instmtype>
inline constexpr io_scatter_status_t
scatter_read_some_decay(instmtype insm, basic_io_scatter_t<typename instmtype::input_char_type> const *pscatters,
						::std::size_t n)
{
	return ::ufio::details::scatter_read_some_impl(insm, pscatters, n);
}

template <typename instmtype>
inline constexpr io_scatter_status_t scatter_read_some_bytes_decay(instmtype insm, io_scatter_t const *pscatters,
																   ::std::size_t n)
{
	return ::ufio::details::scatter_read_some_bytes_impl(insm, pscatters, n);
}

template <typename instmtype>
inline constexpr void scatter_read_all_decay(instmtype insm,
											 basic_io_scatter_t<typename instmtype::input_char_type> const *pscatters,
											 ::std::size_t n)
{
	::ufio::details::scatter_read_all_impl(insm, pscatters, n);
}

template <typename instmtype>
inline constexpr void scatter_read_all_bytes_decay(instmtype insm, io_scatter_t const *pscatters, ::std::size_t n)
{
	::ufio::details::scatter_read_all_bytes_impl(insm, pscatters, n);
}

template <typename instmtype>
inline constexpr typename instmtype::input_char_type *
pread_some_decay(instmtype insm, typename instmtype::input_char_type *first, typename instmtype::input_char_type *last,
				 ::ufio::intfpos_t off)
{
	return ::ufio::details::pread_some_impl(insm, first, last, off);
}

template <typename instmtype>
inline constexpr void pread_all_decay(instmtype insm, typename instmtype::input_char_type *first,
									  typename instmtype::input_char_type *last, ::ufio::intfpos_t off)
{
	::ufio::details::pread_all_impl(insm, first, last, off);
}

template <typename instmtype>
inline constexpr ::std::byte *pread_some_bytes_decay(instmtype insm, ::std::byte *first, ::std::byte *last,
													 ::ufio::intfpos_t off)
{
	return ::ufio::details::pread_some_bytes_impl(insm, first, last, off);
}

template <typename instmtype>
inline constexpr void pread_all_bytes_decay(instmtype insm, ::std::byte *first, ::std::byte *last,
											::ufio::intfpos_t off)
{
	::ufio::details::pread_all_bytes_impl(insm, first, last, off);
}

template <typename instmtype>
inline constexpr io_scatter_status_t
scatter_pread_some_decay(instmtype insm, basic_io_scatter_t<typename instmtype::input_char_type> const *pscatters,
						 ::std::size_t n, ::ufio::intfpos_t off)
{
	return ::ufio::details::scatter_pread_some_impl(insm, pscatters, n, off);
}

template <typename instmtype>
inline constexpr io_scatter_status_t scatter_pread_some_bytes_decay(instmtype insm, io_scatter_t const *pscatters,
																	::std::size_t n, ::ufio::intfpos_t off)
{
	return ::ufio::details::scatter_pread_some_bytes_impl(insm, pscatters, n, off);
}

template <typename instmtype>
inline constexpr void scatter_pread_all_decay(instmtype insm,
											  basic_io_scatter_t<typename instmtype::input_char_type> const *pscatters,
											  ::std::size_t n, ::ufio::intfpos_t off)
{
	::ufio::details::scatter_pread_all_impl(insm, pscatters, n, off);
}

template <typename instmtype>
inline constexpr void scatter_pread_all_bytes_decay(instmtype insm, io_scatter_t const *pscatters, ::std::size_t n,
													::ufio::intfpos_t off)
{
	::ufio::details::scatter_pread_all_bytes_impl(insm, pscatters, n, off);
}

} // namespace ufio::operations::decay
