#include <ufio.h>
#include <ufio_device.h>
#include <random>

using namespace ufio::io;

int main(int argc, char **argv)
{
	std::size_t n{100};
	if (1 < argc)
	{
		n = ufio::to<std::size_t>(ufio::mnp::os_c_str(argv[1]));
	}
	ufio::u8obuf_file obf(u"password.txt");
	ufio::ibuf_white_hole_engine eng;
	std::uniform_int_distribution<std::size_t> ud(0, 61);
	std::uniform_int_distribution<std::size_t> rlen(8, 20);
	for (std::size_t i{}; i != n; ++i)
	{
		for (std::size_t j{}, s(rlen(eng)); j != s; ++j)
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
