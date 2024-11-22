#include <ufio.h>
#include <ufio_driver/timer.h>

int main()
{
	ufio::timer tm(u8"posix");
	::ufio::posix_file nf(u"posixfile.txt", ufio::open_mode::out);
	for (::std::size_t i{}; i != 100000; ++i)
	{
		::ufio::io::print(nf, "Hello World\n", "Hello World\n", "Hello World\n");
	}
}
