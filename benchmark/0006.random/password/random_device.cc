#include <ufio.h>
#include <ufio_device.h>
#include <random>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	ufio::timer tm(u8"random_device");
	ufio::u8obuf_file obf(u"random_device.txt");
	std::random_device eng;
	std::uniform_int_distribution<std::size_t> ud(0, 61);
	std::uniform_int_distribution<std::size_t> rlen(8, 20);
	for (std::size_t i(0); i != 1000000; ++i)
	{
		for (std::size_t j(0), s(rlen(eng)); j != s; ++j)
		{
			char8_t ch(static_cast<char8_t>(ud(eng)));
			if (ch < 10u)
			{
				ch += u8'0';
			}
			else if (ch < 36u)
			{
				ch = ch - 10u + u8'a';
			}
			else
			{
				ch = ch - 36u + u8'A';
			}
			print(obf, ufio::mnp::chvw(ch));
		}
		println(obf);
	}
}
