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
		::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <dirname>\n");
		return 1;
	}

#if __cpp_exceptions
	try
#endif
	{
		::ufio::dir_file d(ufio::mnp::os_c_str(argv[1]));
	}
#if __cpp_exceptions
	catch (ufio::error e)
	{
		::ufio::io::perrln(e);
	}
#endif
}
