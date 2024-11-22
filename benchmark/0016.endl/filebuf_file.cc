#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	ufio::timer tm(u8"u8filebuf_file");
	ufio::filebuf_file fbf(u8"filebuf_file.txt", ufio::open_mode::out);
	for (std::size_t i{}; i != 10000000; ++i)
	{
		print(fbf, "Hello World\n");
	}
}
