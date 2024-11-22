#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::size_t a, b;
	scan(a, b);
	println(a + b);
}
