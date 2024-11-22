#include <ufio.h>
#include <ufio_device.h>

int main()
{
	ufio::obuf_file obf(u8"obf.txt");
	print(obf, "Hello World\n");
}
