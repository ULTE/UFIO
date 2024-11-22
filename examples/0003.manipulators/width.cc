#include <ufio.h>

using namespace ufio::io;

int main()
{
	using namespace ufio::mnp;
	println(left("hello", 20));
	println(middle("hello", 20));
	println(right("hello", 20));
}
