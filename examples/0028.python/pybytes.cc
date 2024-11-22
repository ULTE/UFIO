#include <ufio.h>
#include <ufio_driver/python/pyobject.h>

using namespace ufio::io;

int main()
{
	auto obj{ufio::concat_pyobject_file("Hello World\n")};
	print(obj);
}
