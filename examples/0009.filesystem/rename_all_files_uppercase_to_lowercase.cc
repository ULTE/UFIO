#include <string>
#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", ::ufio::mnp::os_c_str(*argv), " <directory>\n");
		return 1;
	}
	using namespace std::string_view_literals;
	ufio::dir_file dir(::ufio::mnp::os_c_str(argv[1]));
	for (auto ent : recursive(at(dir)))
	{
		if (type(ent) == ufio::file_type::regular || type(ent) == ufio::file_type::symlink)
		{
			std::u8string_view u8fn(u8filename(ent));
			std::u8string filename(u8fn);
			for (auto &e : filename)
			{
				e = ufio::char_category::to_c_lower(e);
			}
			if (filename == u8fn)
			{
				continue;
			}
			native_renameat(drt(ent), at(ent), filename);
			println(ufio::mnp::code_cvt(u8fn), "->", ufio::mnp::code_cvt(filename));
		}
	}
}
