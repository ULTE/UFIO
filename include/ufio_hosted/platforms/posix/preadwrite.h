#pragma once

namespace ufio
{

namespace details
{

#ifndef __wasi__
inline ::std::byte *posix_pread_bytes_impl(int fd, ::std::byte *first, ::std::byte *last, ::ufio::intfpos_t off)
{
	auto ret{::ufio::noexcept_call(::pread, fd, first, static_cast<::std::size_t>(last - first), off)};
	if (ret < 0)
	{
		::ufio::throw_posix_error();
	}
	return first + ret;
}

inline ::std::byte const *posix_pwrite_bytes_impl(int fd, ::std::byte const *first, ::std::byte const *last,
												  ::ufio::intfpos_t off)
{
	auto ret{::ufio::noexcept_call(::pwrite, fd, first, static_cast<::std::size_t>(last - first), off)};
	if (ret < 0)
	{
		::ufio::throw_posix_error();
	}
	return first + ret;
}
#endif

inline ::ufio::io_scatter_status_t posix_scatter_pread_bytes_impl(int fd, ::ufio::io_scatter_t const *pscatter,
																	 ::std::size_t n, ::ufio::intfpos_t off)
{
#if defined(__linux__) && defined(__NR_preadv)
	auto ret{system_call<__NR_preadv, ::std::ptrdiff_t>(fd, pscatter, n, off)};
	::ufio::linux_system_call_throw_error(ret);
#elif defined(__wasi__)
	using iovec_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= __wasi_iovec_t const *;
	::std::size_t ret;
	auto val{noexcept_call(__wasi_fd_pread, fd, reinterpret_cast<iovec_may_alias_const_ptr>(pscatter), n,
						   static_cast<__wasi_filesize_t>(off), __builtin_addressof(ret))};
	if (val)
	{
		::ufio::throw_posix_error(val);
	}
#else
	using iovec_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= struct iovec const *;

	auto ret{::ufio::noexcept_call(::preadv, fd, reinterpret_cast<iovec_may_alias_const_ptr>(pscatter), n, off)};
	if (ret < 0)
	{
		::ufio::throw_posix_error();
	}
#endif
	return scatter_size_to_status(static_cast<::std::size_t>(ret), pscatter, n);
}

inline ::ufio::io_scatter_status_t posix_scatter_pwrite_bytes_impl(int fd, ::ufio::io_scatter_t const *pscatter,
																	  ::std::size_t n, ::ufio::intfpos_t off)
{
#if defined(__linux__) && defined(__NR_pwritev)
	auto ret{system_call<__NR_pwritev, ::std::ptrdiff_t>(fd, pscatter, n, off)};
	::ufio::linux_system_call_throw_error(ret);
#elif defined(__wasi__)
	using iovec_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= __wasi_ciovec_t const *;
	::std::size_t ret;
	auto val{noexcept_call(__wasi_fd_pwrite, fd, reinterpret_cast<iovec_may_alias_const_ptr>(pscatter), n,
						   static_cast<__wasi_filesize_t>(off), __builtin_addressof(ret))};
	if (val)
	{
		::ufio::throw_posix_error(val);
	}
#else
	using iovec_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= struct iovec const *;

	auto ret{::ufio::noexcept_call(::pwritev, fd, reinterpret_cast<iovec_may_alias_const_ptr>(pscatter), n, off)};
	if (ret < 0)
	{
		::ufio::throw_posix_error();
	}
#endif
	return scatter_size_to_status(static_cast<::std::size_t>(ret), pscatter, n);
}

} // namespace details

#ifndef __wasi__

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

#endif

template <::std::integral char_type>
inline ::ufio::io_scatter_status_t
scatter_pread_some_bytes_underflow_define(::ufio::basic_posix_io_observer<char_type> piob,
										  ::ufio::io_scatter_t const *pscatters, ::std::size_t n,
										  ::ufio::intfpos_t fpos)
{
	return ::ufio::details::posix_scatter_pread_bytes_impl(piob.fd, pscatters, n, fpos);
}

template <::std::integral char_type>
inline ::ufio::io_scatter_status_t
scatter_pwrite_some_bytes_overflow_define(::ufio::basic_posix_io_observer<char_type> piob,
										  ::ufio::io_scatter_t const *pscatters, ::std::size_t n,
										  ::ufio::intfpos_t fpos)
{
	return ::ufio::details::posix_scatter_pwrite_bytes_impl(piob.fd, pscatters, n, fpos);
}

} // namespace ufio
