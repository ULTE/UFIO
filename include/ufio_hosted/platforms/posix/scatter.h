#pragma once

namespace ufio
{

namespace details
{

inline ::ufio::io_scatter_status_t posix_scatter_read_bytes_impl(int fd, ::ufio::io_scatter_t const *pscatter,
																	::std::size_t n)
{
#if defined(__linux__) && defined(__NR_readv)
	auto ret{system_call<__NR_readv, ::std::ptrdiff_t>(fd, pscatter, n)};
	::ufio::linux_system_call_throw_error(ret);
#elif defined(__wasi__)
	using iovec_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= __wasi_iovec_t const *;
	::std::size_t ret;
	auto val{noexcept_call(__wasi_fd_read, fd, reinterpret_cast<iovec_may_alias_const_ptr>(pscatter), n,
						   __builtin_addressof(ret))};
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

	auto ret{::ufio::noexcept_call(::readv, fd, reinterpret_cast<iovec_may_alias_const_ptr>(pscatter), n)};
	if (ret < 0)
	{
		::ufio::throw_posix_error();
	}
#endif
	return scatter_size_to_status(static_cast<::std::size_t>(ret), pscatter, n);
}

inline ::ufio::io_scatter_status_t posix_scatter_write_bytes_impl(int fd, ::ufio::io_scatter_t const *pscatter,
																	 ::std::size_t n)
{
#if defined(__linux__) && defined(__NR_writev)
	auto ret{system_call<__NR_writev, ::std::ptrdiff_t>(fd, pscatter, n)};
	::ufio::linux_system_call_throw_error(ret);
#elif defined(__wasi__)
	using iovec_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= __wasi_ciovec_t const *;
	::std::size_t ret;
	auto val{noexcept_call(__wasi_fd_write, fd, reinterpret_cast<iovec_may_alias_const_ptr>(pscatter), n,
						   __builtin_addressof(ret))};
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

	auto ret{::ufio::noexcept_call(::writev, fd, reinterpret_cast<iovec_may_alias_const_ptr>(pscatter), n)};
	if (ret < 0)
	{
		::ufio::throw_posix_error();
	}
#endif
	return scatter_size_to_status(static_cast<::std::size_t>(ret), pscatter, n);
}

} // namespace details

template <::std::integral char_type>
inline ::ufio::io_scatter_status_t
scatter_read_some_bytes_underflow_define(::ufio::basic_posix_io_observer<char_type> piob,
										 ::ufio::io_scatter_t const *pscatters, ::std::size_t n)
{
	return ::ufio::details::posix_scatter_read_bytes_impl(piob.fd, pscatters, n);
}

template <::std::integral char_type>
inline ::ufio::io_scatter_status_t
scatter_write_some_bytes_overflow_define(::ufio::basic_posix_io_observer<char_type> piob,
										 ::ufio::io_scatter_t const *pscatters, ::std::size_t n)
{
	return ::ufio::details::posix_scatter_write_bytes_impl(piob.fd, pscatters, n);
}

} // namespace ufio
