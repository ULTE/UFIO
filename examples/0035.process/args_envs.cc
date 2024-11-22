#include <ufio.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 0) [[unlikely]]
		{
			return 1;
		}
		::ufio::io::perr("Usage: ", ::ufio::mnp::os_c_str(*argv), " <exe>\n");
		return 1;
	}
	::ufio::native_process p{
		::ufio::mnp::os_c_str(argv[1]),
		{"char",
		 L"wchar Double\"quotation\"marks",
		 u8"u8",
		 u"u16",
		 U"u32",
		 114514,
		 115145.1919810},
		{},
		{}};
	auto ec{wait(p)};
	::ufio::io::perrln(::ufio::mnp::os_c_str(*argv), " -> Exit code: ", static_cast<int>(ec.wait_loc));
}
