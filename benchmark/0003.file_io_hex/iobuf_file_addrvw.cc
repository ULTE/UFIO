#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <vector>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::obuf_file obf(u8"iobuf_file_addrvw.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			println(obf, ufio::mnp::addrvw(i));
		}
	}
	std::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::ibuf_file ibf(u8"iobuf_file_addrvw.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			scan(ibf, ufio::mnp::addrvw_get(vec[i]));
		}
	}
}
