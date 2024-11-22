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
		ufio::u32obuf_file obf(u8"u32iobuf_file.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			println(obf, i);
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::u32ibuf_file ibf(u8"u32iobuf_file.txt");
		for (auto it{vec.begin()}; it != vec.cend(); ++it)
		{
			scan(ibf, *it);
		}
	}
}
