#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file>\n");
		return 1;
	}
	ufio::ibuf_file ibf(ufio::mnp::os_c_str(argv[1]));
	transmit(ufio::c_stdout(), ibf); // Transmit all bytes to FILE* stdout
}
