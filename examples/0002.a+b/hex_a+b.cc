#include <ufio.h>

using namespace ufio::io;

int main()
{
	using namespace ufio::mnp;
	std::size_t a, b;
	scan(hex_get(a), hex_get(b));
	println(hex(a + b), " ", hexupper(a + b));
}
