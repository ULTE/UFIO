#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
#include <iostream>

int main()
{
	unsigned u{};
	{
	::ufio::timer tm(u8"coutfd");
	for (::std::size_t i{};i!=10000000;++i)
	{
		::ufio::streambuf_io_observer siob{std::cout.rdbuf()};
		u+=static_cast<unsigned>(static_cast<::ufio::posix_io_observer>(siob).fd);
	}
	}
	::ufio::io::println("u=",u);
}
