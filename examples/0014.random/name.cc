﻿#include <ufio.h>
#include <ufio_device.h>
#include <random>
#include <ufio_dsal/vector.h>

using namespace ufio::io;

int main(int argc, char **argv)
{
	std::size_t n{100};
	if (1 < argc)
	{
		n = ufio::to<std::size_t>(ufio::mnp::os_c_str(argv[1]));
	}
	ufio::u8ibuf_file ibuf(u"freq.txt");
	ufio::vector<char8_t> vec;
	{
		char8_t c;
		for (std::size_t f; scan<true>(ibuf, ufio::mnp::ch_get(c), f);)
		{
			for (std::size_t i{}; i != f; ++i)
			{
				vec.emplace_back(ufio::char_category::to_c_lower(c));
			}
		}
	}
	if (vec.empty())
	{
		perr("No frequency\n");
		return 1;
	}
	ufio::ibuf_white_hole_engine eng;
	std::uniform_int_distribution<std::size_t> ud(0, vec.size() - 1);
	std::uniform_int_distribution<std::size_t> rlen(6, 12);
	ufio::u8obuf_file obf(u"name.txt");
	for (std::size_t i{}; i != n; ++i)
	{
		for (std::size_t j{}, s(rlen(eng)); j != s; ++j)
		{
			print(obf, ufio::mnp::chvw(vec[ud(eng)]));
		}
		println(obf);
	}
}
