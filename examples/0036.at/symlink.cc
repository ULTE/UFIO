#include <ufio.h>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		if (argc == 0)
		{
			return 1;
		}
		::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <oldfile> <newfile>\n");
		return 1;
	}

#if __cpp_exceptions
	try
#endif
	{
		::ufio::native_symlinkat(ufio::mnp::os_c_str(argv[1]),
									::ufio::at_fdcwd(), ufio::mnp::os_c_str(argv[2]));
	}
#if __cpp_exceptions
	catch (ufio::error e)
	{
		::ufio::io::perrln(e);
	}
#endif
}
