#include <string>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	std::size_t spaces{};
	{
		ufio::timer t(u8"input");
		ufio::u16iutf8_file ibf(u8"ibuf_white_hole_engine.txt");
		for (std::u16string u16str; scan<true>(ibf, ufio::mnp::strlike_get(u16str)); ++spaces)
		{
		}
	}
	println(spaces);
}
