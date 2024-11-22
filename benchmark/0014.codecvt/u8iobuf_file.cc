#include <string>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(1000000);
	{
		ufio::timer t(u8"output");
		ufio::u8obuf_file obf(u8"u8iobuf_file.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			print(obf, u8"😀😃😄😁😆😅🤣😂🙂🙃\n");
		}
	}
	std::u8string buffer;
	{
		ufio::timer t(u8"input");
		ufio::u8ibuf_file ibf(u8"u8iobuf_file.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			scan(ibf, buffer);
		}
	}
}
