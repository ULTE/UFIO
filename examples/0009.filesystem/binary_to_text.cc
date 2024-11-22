#include <ufio_device.h>
#include <ufio.h>
#include <string_view>

using namespace ufio::io;

int main(int argc, char const **argv)
try
{
	if (argc < 3)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", ufio::mnp::os_c_str(*argv), " <source directory> <dest directory>\n");
		return 1;
	}
	ufio::dir_file df(::ufio::mnp::os_c_str(argv[1]));
	ufio::dir_file df_crlf(::ufio::mnp::os_c_str(argv[2]));
	using namespace std::string_view_literals;
	for (auto ent : current(at(df)))
	{
		if (std::u8string_view(u8extension(ent)) == u8".cc"sv)
		{
			ufio::native_file pf(drt(ent), ufio::open_mode::in | ufio::open_mode::text); // sorry i am stupid
			ufio::c_file_unlocked pf2(at(df_crlf), native_filename(ent),
										 ufio::open_mode::out | ufio::open_mode::text);
			transmit(pf2, pf);
		}
	}
}
catch (ufio::error e)
{
	perrln(e);
}
