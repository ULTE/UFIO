#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>

int main()
{
	ufio::timer tm(u8"ofstream");
	ufio::filebuf_file fbf(u8"ofstream.txt", ufio::open_mode::out);
	std::ostream fout(fbf.fb);
	for (std::size_t i{}; i != 10000000; ++i)
	{
		fout << "Hello World\n";
	}
}
