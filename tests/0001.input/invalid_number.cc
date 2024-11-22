#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main()
try
{
	ufio::u8ibuf_file ibf(u8"invalid.txt");
	std::size_t s{};
	scan(ibf, s);
	println(s);
}
catch (ufio::parse_code code)
{
	perrln(code);
	return 1;
}