#include <string>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"concat_std");
		ufio::obuf_file obf("concat_std.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			print(obf, ufio::concatln_std(i));
		}
	}
}
