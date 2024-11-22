#include <ufio.h>
#include <ufio_dsal/string_view.h>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		if (argc == 0)
		{
			return 1;
		}
		::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file> [f, x, w, r]\n");
		return 1;
	}

#if __cpp_exceptions
	try
#endif
	{
		::ufio::u8cstring_view argv2{ufio::mnp::os_c_str(reinterpret_cast<char8_t *>(argv[2]))};
		::ufio::access_how ah;
		if (argv2 == u8"f")
		{
			ah = ::ufio::access_how::f_ok;
		}
		else if (argv2 == u8"x")
		{
			ah = ::ufio::access_how::x_ok;
		}
		else if (argv2 == u8"w")
		{
			ah = ::ufio::access_how::w_ok;
		}
		else if (argv2 == u8"r")
		{
			ah = ::ufio::access_how::r_ok;
		}
		else
		{
			::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file> [f, x, w, r]\n");
			return 1;
		}

		::ufio::native_faccessat(::ufio::at_fdcwd(), ufio::mnp::os_c_str(argv[1]), ah);
	}
#if __cpp_exceptions
	catch (ufio::error e)
	{
		::ufio::io::perrln(e);
	}
#endif
}
