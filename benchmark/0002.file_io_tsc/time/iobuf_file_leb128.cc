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
		ufio::u8obuf_file obf(u8"iobuf_file_leb128.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			print(obf, ufio::mnp::leb128_put(i));
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::u8ibuf_file ibf(u8"iobuf_file_leb128.txt");
		for (auto it{vec.begin()}; it != vec.cend(); ++it)
		{
			scan(ibf, ufio::mnp::leb128_get(*it));
		}
	}
}
