#include <ufio.h>
#include <ufio_device.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 0)
		{
			return 1;
		}
		::ufio::io::perr("Usage: ", ::ufio::mnp::os_c_str(*argv), " <file>\n");
		return 1;
	}
	::ufio::win32_file_loader a{::ufio::mnp::os_c_str(argv[1])};
	::ufio::io::print(a);
}
