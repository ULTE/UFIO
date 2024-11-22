#include <ufio.h>
#include <ufio_driver/timer.h>
#include <ufio_device.h>
#include <iostream>
using namespace ufio::io;

inline void test()
{
	for (std::size_t i{}; i != 1000000; ++i)
	{
		std::cout << i << '\n';
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	ufio::u8obuf_file timer_obf(u"iostream.txt");
	ufio::timer t(u8"iostream");
	test();
}
