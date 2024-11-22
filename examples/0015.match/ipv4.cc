#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main()
{
	char8_t a, b, c, d;
	scan(a, ".", b, ".", c, ".", d);
	println(a, ".", b, ".", c, ".", d);
}