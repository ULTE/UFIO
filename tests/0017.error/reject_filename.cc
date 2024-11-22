#include <cstdio>
#include <ufio.h>

int main()
{
	char buffer[20]{}; // must be a string literal
	ufio::native_file nf(buffer, ufio::open_mode::out);
}
