#include <ufio.h>
#include <ufio_driver/linux_kernel.h>

using namespace ufio::io;

extern "C" int ufio_dummy_init() noexcept
{
	println(ufio::u8kpr(), u8"Hello linux kernel from C++ ufio, i know linus torvalds hates this: ", 20);
	return 0;
}

extern "C" void ufio_dummy_exit() noexcept
{
	print(ufio::u8kpr(), u8"Goodby linux kernel from C++ ufio\n");
}
