﻿#include <string>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <vector>
using namespace ufio::io;

int main()
{
	std::size_t lines{};
	{
		ufio::timer t(u8"input");
		ufio::u8ibuf_file ibf(u8"ibuf_white_hole_engine.txt");
		for (std::u8string str; scan<true>(ibf, ufio::mnp::line_get(str));)
		{
			++lines;
		}
	}
	println(lines);
}
