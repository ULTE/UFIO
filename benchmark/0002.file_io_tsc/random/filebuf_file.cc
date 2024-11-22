#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
#include "generate.h"
using namespace ufio::io;

int main()
{
	auto tb{generate_random_data()};
	{
		ufio::timer t(u8"output");
		ufio::filebuf_file fbf(u8"filebuf_file.txt", ::ufio::open_mode::out);
		for (auto &e : tb)
		{
			println(fbf, e);
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::filebuf_file fbf(u8"filebuf_file.txt", ::ufio::open_mode::in);
		for (std::size_t i{}; i != N; ++i)
		{
			scan(fbf, vec[i]);
		}
	}
}
