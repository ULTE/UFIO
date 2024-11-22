#include <ufio.h>

using namespace ufio::io;

int main()
{
	char const *ptr{"Hello World from char const*\n"};
	char8_t const *u8ptr{u8"Hello World from char8_t const*\n"};
	char32_t const *u32ptr{U"Hello World from char32_t const*\n"};
	print(ufio::mnp::os_c_str(ptr),
		  ufio::mnp::code_cvt(ufio::mnp::os_c_str(u8ptr)),
		  ufio::mnp::code_cvt(ufio::mnp::os_c_str(u32ptr)));
}