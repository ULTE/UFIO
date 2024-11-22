﻿#include <ufio.h>
#include <ufio_device.h>
#include <string_view>
#include <array>
#include <algorithm>
#include <cstring>

using namespace ufio::io;

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", ::ufio::mnp::os_c_str(*argv), " <source directory>\n");
		return 1;
	}
	using namespace std::string_view_literals;
	constexpr std::array<char8_t, 3> utf8bom{0xEF, 0xBB, 0xBF};
	ufio::dir_file df(::ufio::mnp::os_c_str(argv[1]));
	for (auto const &ent : recursive(at(df)))
	{
		std::u8string_view view(u8extension(ent));
		if (view != u8".cc"sv && view != u8".h"sv && view != u8".cpp"sv && view != u8".cxx"sv && view != u8".hpp"sv)
		{
			continue;
		}
		ufio::allocation_file_loader loader(drt(ent));
		if (loader.size() >= utf8bom.size() && std::memcmp(loader.data(), utf8bom.data(), 3u) == 0)
		{
			continue;
		}
		ufio::obuf_file obf(drt(ent), ufio::open_mode::out);
		::ufio::operations::write_all_range(obf, utf8bom);
		print(obf, loader);
	}
}
