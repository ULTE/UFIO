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
		::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file> <perms>\n");
		return 1;
	}

#if __cpp_exceptions
	try
#endif
	{
		::std::uint_least32_t perm;
		::ufio::scan(::ufio::mnp::os_c_str(argv[2]), perm);
		::ufio::native_fchmodat(::ufio::at_fdcwd(), ufio::mnp::os_c_str(argv[1]), static_cast<::ufio::perms>(perm));
	}
#if __cpp_exceptions
	catch (ufio::error e)
	{
		::ufio::io::perrln(e);
	}
#endif
}
