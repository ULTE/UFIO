#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>

int main()
{
	ufio::timer tm(u8"ofstream_endl");
	ufio::filebuf_file fbf(u8"ofstream_endl.txt", ufio::open_mode::out);
	std::ostream fout(fbf.fb);
	// PLEASE NEVER USE std::endl!!!!!!!! It is a historical mistake and part of the reason why ufio as a library
	// even exists in the first place.
	for (std::size_t i{}; i != 10000000; ++i)
	{
		fout << "Hello World" << std::endl;
	}
}
