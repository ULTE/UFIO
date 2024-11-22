#include <ufio.h>

using namespace ufio::io;

int main()
{
	using namespace ufio::mnp;
	std::size_t a, b;
	scan(base_get<36>(a), base_get<36>(b));
	println(base<36>(a + b));
}
