#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main()
{
	ufio::obuf_file obf("a.txt");
	println(status(obf.handle));
}