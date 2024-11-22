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
		ufio::u16outf8_file obf(u8"u16utf8_file.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			print(obf, u"😀😃😄😁😆😅🤣😂🙂🙃\n");
		}
	}
	std::u16string buffer;
	{
		ufio::timer t(u8"input");
		ufio::u16iutf8_file ibf(u8"u16utf8_file.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			scan(ibf, buffer);
		}
	}
}