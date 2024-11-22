#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	ufio::timer tm(u8"u8c_file_unlocked");
	ufio::u8c_file_unlocked cf(u8"filebuf_file.txt", ufio::open_mode::out);
	for (std::size_t i{}; i != 10000000; ++i)
	{
		print(cf, u8"Hello World\n");
	}
}
