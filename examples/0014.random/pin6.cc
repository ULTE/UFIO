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
	ufio::u8obuf_file obf(u"pin6.txt");
	ufio::ibuf_white_hole_engine eng;
	std::uniform_int_distribution<unsigned> ud(0, 9);
	for (std::size_t i{}; i != n; ++i)
	{
		for (std::size_t j{}; j != 6u; ++j)
		{
			char8_t ch(static_cast<char8_t>(ud(eng)));
			ch += u8'0';
			print(obf, ufio::mnp::chvw(ch));
		}
		println(obf);
	}
}
