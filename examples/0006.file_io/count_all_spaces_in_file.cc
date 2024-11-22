#include <algorithm>
#include <ufio.h>

using namespace ufio::io;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file>\n");
		return 1;
	}
	ufio::native_file_loader loader(::ufio::mnp::os_c_str(argv[1]));
	println(std::ranges::count_if(loader, [](char8_t ch) noexcept { return ufio::char_category::is_c_space(ch); }));
}
