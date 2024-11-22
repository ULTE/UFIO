#include <ufio.h>
#include <ufio_driver/timer.h>

int main()
{
	ufio::timer tm(u8"win32");
	::ufio::win32_file nf(u"win32file.txt", ufio::open_mode::out);
	for (::std::size_t i{}; i != 100000; ++i)
	{
		::ufio::io::print(nf, "Hello World\n", "Hello World\n", "Hello World\n");
	}
}
