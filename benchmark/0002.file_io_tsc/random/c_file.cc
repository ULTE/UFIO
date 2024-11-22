#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include "generate.h"
using namespace ufio::io;

int main()
{
	auto tb{generate_random_data()};
	{
		ufio::timer t(u8"output");
		ufio::c_file cf(u8"c_file.txt", ::ufio::open_mode::out);
		for (auto &e : tb)
		{
			println(cf, e);
		};
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::c_file cf(u8"c_file.txt", ::ufio::open_mode::in);
		for (std::size_t i{}; i != N; ++i)
		{
			scan(cf, vec[i]);
		}
	}
}
