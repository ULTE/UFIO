#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <ufio_driver/qt.h>
using namespace ufio::io;

int main()
{
	std::size_t spaces{};
	{
		ufio::timer t(u8"input");
		ufio::u8ibuf_file ibf(u8"ibuf_white_hole_engine.txt");
		for (QString qstr; scan<true>(ibf, ufio::mnp::strlike_line_get(qstr)); ++spaces)
		{
		}
	}
	println(spaces);
}
