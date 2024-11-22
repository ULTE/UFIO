#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	ufio::timer tm(u8"u8obuf_file");
	ufio::u8native_file nf(u8"u8native_file.txt", ufio::open_mode::out);
	// native_file does not hold a buffer at all. So it is an unbuffered stream. If you really want to just prevent data
	// from not printing out when crashing. Just use this instead of std::endl. It does not invoke the cost of syscalls
	// and other similar cost.
	for (std::size_t i{}; i != 10000000; ++i)
	{
		print(nf, u8"Hello World\n");
	}
}
