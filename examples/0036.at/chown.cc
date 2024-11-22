#include <ufio.h>
#include <ufio_dsal/string_view.h>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		if (argc == 0)
		{
			return 1;
		}
		::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file> <owner> <group>\n");
		return 1;
	}

#if __cpp_exceptions
	try
#endif
	{
		::std::uint_least64_t o;
		::std::uint_least64_t g;
		::ufio::scan(::ufio::mnp::os_c_str(argv[2]), o, g);
		::ufio::native_fchownat(::ufio::at_fdcwd(), ufio::mnp::os_c_str(argv[1]), o, g);
	}
#if __cpp_exceptions
	catch (ufio::error e)
	{
		::ufio::io::perrln(e);
	}
#endif
}
