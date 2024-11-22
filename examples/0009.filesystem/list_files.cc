/*
 * Usage:
 *     ./list_files [directory]
 */
#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main(int argc, char **argv)
{
	using namespace ufio::mnp;
	auto dname = os_c_str(".");
	if (argc > 1)
	{
		dname = os_c_str(argv[1]);
	}
	try
	{
		ufio::dir_file df(dname);
		for (auto const &ent : current(at(df)))
		{
			if (is_dot(ent)) // ignore . and ..
			{
				continue;
			}
			switch (type(ent))
			{
				using enum ::ufio::file_type;
			case directory:
				print("D: ");
				break;
			default:
				print("F: ");
			}
			println(code_cvt(u8filename(ent)));
		}
	}
	catch (ufio::error &e)
	{
		perr("Fatal error: ", e);
		return 1;
	}
	return 0;
}
