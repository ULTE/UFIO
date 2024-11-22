#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

inline void test()
{
	for (std::size_t i{}; i != 1000000; ++i)
	{
		println(i);
	}
}

int main()
{
	ufio::u8obuf_file timer_obf(u"stdio_hack.txt");
	ufio::timer t(u8"stdio_hack");
	test();
}
