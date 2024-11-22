#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
#include <iostream>

int main()
{
	::std::uintptr_t u{};
	{
	::ufio::timer tm(u8"coutfd");
	for (::std::size_t i{};i!=10000000;++i)
	{
		::ufio::streambuf_io_observer siob{std::cout.rdbuf()};
		u+=std::bit_cast<std::uintptr_t>(static_cast<::ufio::c_io_observer>(siob).fp);
	}
	}
	::ufio::io::println("u=",u);
}
