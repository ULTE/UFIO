#include <ufio.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 0)
		{
			return 1;
		}
		::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file>\n");
		return 1;
	}

#if __cpp_exceptions
	try
#endif
	{
		::ufio::io::perrln(::ufio::native_fstatat(::ufio::at_fdcwd(), ufio::mnp::os_c_str(argv[1])));
	}
#if __cpp_exceptions
	catch (ufio::error e)
	{
		::ufio::io::perrln(e);
	}
#endif
}
