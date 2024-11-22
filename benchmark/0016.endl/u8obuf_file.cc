#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	ufio::timer tm(u8"u8obuf_file");
	ufio::u8obuf_file obf(u8"u8obuf_file.txt");
	for (std::size_t i{}; i != 10000000; ++i)
	{
		print(obf, u8"Hello World\n");
	}
}
