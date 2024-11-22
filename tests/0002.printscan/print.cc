#include <ufio.h>

using namespace ufio::io;

int main()
{
	print("Hello World\n");
	println("Hello World");
	print(ufio::out(), "Hello World\n");
	println(ufio::out(), "Hello World");
	print(ufio::u8out(), u8"Hello World\n");
	println(ufio::u8out(), u8"Hello World");

	perr("Hello World\n");
	perrln("Hello World");
	perr(ufio::out(), "Hello World\n");
	perrln(ufio::out(), "Hello World");
	perr(ufio::u8out(), u8"Hello World\n");
	perrln(ufio::u8out(), u8"Hello World");

#ifndef NDEBUG
	debug_print("Hello World\n");
	debug_println("Hello World");
	debug_print(ufio::out(), "Hello World\n");
	debug_println(ufio::out(), "Hello World");
	debug_print(ufio::u8out(), u8"Hello World\n");
	debug_println(ufio::u8out(), u8"Hello World");

	debug_perr("Hello World\n");
	debug_perrln("Hello World");
	debug_perr(ufio::out(), "Hello World\n");
	debug_perrln(ufio::out(), "Hello World");
	debug_perr(ufio::u8out(), u8"Hello World\n");
	debug_perrln(ufio::u8out(), u8"Hello World");
#endif
}
