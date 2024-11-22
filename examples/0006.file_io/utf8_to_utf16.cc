#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main(int argc, char **argv)
#ifdef __cpp_exceptions
try
#endif
{
	using namespace ufio::mnp;
	if (argc != 3)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", os_c_str(*argv), " <input UTF8 file> <output UTF-32 file>\n");
		return 1;
	}
	auto t0{ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)};
	ufio::u16iutf8_file file(os_c_str(argv[1])); // This will do codecvt from UTF-8 to UTF-16
	ufio::obuf_file obf(os_c_str(argv[2]), ufio::open_mode::excl);
	auto transmitted{transmit(obf, file)};
	println(os_c_str(argv[1]), " => ", os_c_str(argv[2]), "\nTransmitted:", transmitted,
			" utf-16 characters\tElapsed Time:", ufio::posix_clock_gettime(ufio::posix_clock_id::realtime) - t0);
}
#ifdef __cpp_exceptions
catch (ufio::error e)
{
	perrln(e);
}
catch (std::exception const &e)
{
	perrln(ufio::mnp::ehvw(e));
}
catch (...)
{
	perr("unknown EH\n");
}
#endif
