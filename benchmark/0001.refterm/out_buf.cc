#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

inline void test()
{
	ufio::out_buf_type obf{ufio::out()};
	for (std::size_t i{}; i != 1000000; ++i)
	{
		println(obf, i);
	}
}
// STDOUT_HANDLE
int main()
{
	ufio::u8obuf_file timer_obf(u"out_buf.txt");
	ufio::timer t(u8"out_buf");
	test();
}
