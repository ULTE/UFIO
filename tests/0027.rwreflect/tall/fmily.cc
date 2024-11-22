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

inline constexpr foo output_stream_ref_define(foo f) noexcept
{
	return f;
}
extern "C" void fake_scatters_write(
	::ufio::io_scatter_t const *base, ::std::size_t len) noexcept;

inline ::std::byte const *write_some_bytes_overflow_define(foo f, ::std::byte const *first, ::std::byte const *last)
{
	auto res{::ufio::noexcept_call(::write, f.fd, first, static_cast<::std::size_t>(last - first))};
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
#endif

struct bar
{};

#if 0
template<::ufio::output_stream optstmtype>
inline constexpr void print_define(::ufio::io_reserve_type_t<char8_t,bar>,optstmtype opt,bar)
{
	::ufio::operations::print_freestanding(opt,u8"\nbar",1,u8"\nbar2\n",u8"bar3\n");
}

static_assert(::ufio::printable<char8_t,bar>);
#endif

int main()
{
	foo f{1};
	::ufio::operations::println_freestanding(f, u8"Hello");
	//	static_assert(::ufio::byte_output_stream<foo>);
	//	:ufio::operations::decay::scatter_write_all_bytes_decay()
	//	::ufio::operations::println_freestanding(f,::std::source_location::current(),u8"\nPara1\n",u8"Para2\n",u8"Para3\n",u8"Para4\nPara",5,u8"\nPara",6,bar{},u8"Para7\n",u8"Para8");
}
