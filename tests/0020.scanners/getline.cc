#include <string>
#include <ufio_legacy.h>

using namespace ufio::io;

int main()
{
	ufio::filebuf_file fbf(u8"test.txt", ufio::open_mode::in);
	std::istream fin(fbf.fb);
	for (std::string line; std::getline(fin, line); println(line))
		;
}
