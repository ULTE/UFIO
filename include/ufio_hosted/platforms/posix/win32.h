#pragma once

namespace ufio
{

namespace details
{

inline ::std::byte *posix_pread_bytes_impl(int fd, ::std::byte *first, ::std::byte *last, ::ufio::intfpos_t off)
{
	return ::ufio::win32::details::pread_some_bytes_impl(::ufio::details::my_get_osfile_handle(fd), first, last,
															off);
}

inline ::std::byte const *posix_pwrite_bytes_impl(int fd, ::std::byte const *first, ::std::byte const *last,
												  ::ufio::intfpos_t off)
{
	return ::ufio::win32::details::pwrite_some_bytes_impl(::ufio::details::my_get_osfile_handle(fd), first, last,
															 off);
}

} // namespace details

template <::std::integral char_type>
inline ::std::byte *pread_some_bytes_underflow_define(::ufio::basic_posix_io_observer<char_type> piob,
													  ::std::byte *first, ::std::byte *last, ::ufio::intfpos_t off)
{
	return ::ufio::details::posix_pread_bytes_impl(piob.fd, first, last, off);
}

template <::std::integral char_type>
inline ::std::byte const *pwrite_some_bytes_overflow_define(::ufio::basic_posix_io_observer<char_type> piob,
															::std::byte const *first, ::std::byte const *last,
															::ufio::intfpos_t off)
{
	return ::ufio::details::posix_pwrite_bytes_impl(piob.fd, first, last, off);
}

} // namespace ufio
