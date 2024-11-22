#include <string_view>
#include <ufio.h>
#include <ufio_device.h>
#include <algorithm>
#include <functional>

using namespace ufio::io;

int main(int argc, char **argv)
{
	using namespace ::ufio::mnp;
	if (argc < 3)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", os_c_str(*argv), " <wow addons directory> <new version string>\n");
		return 1;
	}
	std::string_view versionstring{argv[2]};
	using namespace std::string_view_literals;
	ufio::dir_file df(os_c_str(argv[1]));
	constexpr ::std::u8string_view vw(u8"## Interface: ");
	::std::boyer_moore_horspool_searcher searcher(reinterpret_cast<char const *>(vw.data()),
												  reinterpret_cast<char const *>(vw.data()) + vw.size());
	for (auto ent : recursive(at(df)))
	{
		if (type(ent) != ufio::file_type::regular)
		{
			continue;
		}
		std::u8string_view ext(u8extension(ent));
		if (ext == u8".toc"sv)
		{
			ufio::allocation_file_loader loader(drt(ent));
			auto bg{loader.data()};
			auto ed{loader.data() + loader.size()};
			auto it{std::search(bg, ed, searcher)};
			if (it == ed)
			{
				continue;
			}
			if (it - loader.data() > 3)
			{
				continue;
			}
			auto itvwsze{it + vw.size()};
			auto nextn{std::find(itvwsze, ed, u8'\n')};
			ufio::obuf_file obf(drt(ent));
			ufio::operations::write_all(obf, bg, itvwsze);
			print(obf, versionstring);
			ufio::operations::write_all(obf, nextn, ed);
		}
	}
}