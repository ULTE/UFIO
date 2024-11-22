#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <vector>
#include "longspaces.h"
using namespace ufio::io;

int main()
{
	{
		ufio::timer t(u8"output");
		ufio::u32outf8_file obf("u32utf8_file.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			print(obf, i, ufio::mnp::strvw(filled_chars<typename decltype(obf)::output_char_type>));
		}
	}
	std::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::u32iutf8_file ibf("u32utf8_file.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			scan(ibf, vec[i]);
		}
	}
}
