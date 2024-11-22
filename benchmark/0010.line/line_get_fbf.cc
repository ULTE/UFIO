#include <string>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
#include <vector>
using namespace ufio::io;

int main()
{
	std::size_t lines{};
	{
		ufio::timer t(u8"input");
		// use std::filebuf_file to provide a fair comparison to C++ stream facilities
		ufio::filebuf_file fbf(u8"ibuf_white_hole_engine.txt", ufio::open_mode::in);
		for (std::string str; scan<true>(fbf, ufio::mnp::line_get(str));)
		{
			++lines;
		}
	}
	println(lines);
}
