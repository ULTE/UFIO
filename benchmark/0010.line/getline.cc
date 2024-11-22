#include <string>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	std::size_t lines{};
	{
		ufio::timer t(u8"input");
		ufio::filebuf_file fbf(u8"ibuf_white_hole_engine.txt", ufio::open_mode::in);
		std::istream fin(fbf.fb);
		for (std::string line; std::getline(fin, line); ++lines)
			;
	}
	println(lines);
}
