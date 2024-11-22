#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <ufio_driver/refterm.h>
using namespace ufio::io;

inline void test()
{
	ufio::u8obuf_file obf(ufio::win32_refterm_fast_pipe());
	for (std::size_t i{}; i != 1000000; ++i)
	{
		println(obf, i);
	}
}

int main()
{
	ufio::u8obuf_file timer_obf(u"fpipe.txt");
	ufio::timer t(u8"fpipe");
	test();
}
