#include <stdio.h>
#include <ufio_core.h>
#if __has_include(<sys/uio.h>)
#include <sys/uio.h>
#endif
#include <unistd.h>
#include <cstdlib>

struct foo
{
	using input_char_type = char8_t;
	using output_char_type = char8_t;
	int fd{1};
};

inline constexpr foo io_stream_ref_define(foo f) noexcept
{
	return f;
}

inline ::std::byte const *write_some_bytes_overflow_define(foo f, ::std::byte const *first, ::std::byte const *last)
{
	auto res{::ufio::noexcept_call(::write, f.fd, first, static_cast<::std::size_t>(last - first))};
	if (res < 0)
	{
		::std::abort();
	}
	return first + res;
}

inline ::std::byte *read_some_bytes_underflow_define(foo f, ::std::byte *first, ::std::byte *last)
{
	auto res{::ufio::noexcept_call(::read, f.fd, first, static_cast<::std::size_t>(last - first))};
	if (res < 0)
	{
		::std::abort();
	}
	return first + res;
}

#if __has_include(<sys/uio.h>)

inline ::ufio::io_scatter_status_t scatter_write_some_bytes_overflow_define(
	foo f,
	::ufio::io_scatter_t const *base, ::std::size_t len)
{
	auto res{::ufio::noexcept_call(::writev, f.fd, reinterpret_cast<struct iovec const *>(base), len)};
	if (res < 0)
	{
		::std::abort();
	}
	return ::ufio::scatter_size_to_status(static_cast<::std::size_t>(res), base, len);
}

inline ::ufio::io_scatter_status_t scatter_read_some_bytes_underflow_define(
	foo f,
	::ufio::io_scatter_t const *base, ::std::size_t len)
{
	auto res{::ufio::noexcept_call(::readv, f.fd, reinterpret_cast<struct iovec const *>(base), len)};
	if (res < 0)
	{
		::std::abort();
	}
	return ::ufio::scatter_size_to_status(static_cast<::std::size_t>(res), base, len);
}
#endif

int main()
{
	foo f0{0};
	foo f1{1};
	::ufio::operations::println_freestanding(f1, ::ufio::operations::transmit_until_eof(f1, f0));
}
