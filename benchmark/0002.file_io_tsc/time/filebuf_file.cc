#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::filebuf_file obf(u8"filebuf_file.txt", ufio::open_mode::out);
		for (std::size_t i{}; i != N; ++i)
		{
			println(obf, i);
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::filebuf_file ibf(u8"filebuf_file.txt", ufio::open_mode::in);
		for (std::size_t i{}; i != N; ++i)
		{
			scan(ibf, vec[i]);
		}
	}
}
