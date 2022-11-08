#include<fast_io.h>
#include<fast_io_device.h>
#include<fast_io_driver/timer.h>
#include<fast_io_driver/qt.h>

int main()
{
	std::size_t spaces{};
	{
		fast_io::timer t(u8"input");
		fast_io::u16iutf8_file ibf(u8"ibuf_white_hole_engine.txt");
		for(QString qstr;scan<true>(ibf,fast_io::mnp::strlike_get(qstr));++spaces){}
	}
	println(spaces);
}
