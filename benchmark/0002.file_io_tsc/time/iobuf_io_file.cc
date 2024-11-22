#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::iobuf_io_file obf(::ufio::io_cookie_type<::ufio::native_file>, "iobuf_io_file.txt",
								   ::ufio::open_mode::out);
		for (std::size_t i{}; i != N; ++i)
		{
			println(obf, i);
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::iobuf_io_file ibf(::ufio::io_cookie_type<::ufio::native_file>, "iobuf_io_file.txt",
								   ::ufio::open_mode::in);
		for (std::size_t i{}; i != N; ++i)
		{
			scan(ibf, vec[i]);
		}
	}
}
