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
		ufio::u8obuf_file obf(u8"iobuf_file.txt");
		for (auto &e : tb)
		{
			println(obf, e);
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::u8ibuf_file ibf(u8"iobuf_file.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			scan(ibf, vec[i]);
		}
	}
}
