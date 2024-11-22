#include <string_view>
#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main()
try
{
	ufio::http_header_buffer bf;
	ufio::ibuf_file ibf(u8"test.txt");
	scan(ibf, bf);
	println("request:", bf.request(), "\n"
									  "code:",
			bf.code(), "\n"
					   "reason:",
			bf.reason());
	for (auto [key, value] : line_generator(bf))
	{
		println("key=", key, " value=", value);
	}
}
catch (ufio::parse_code c)
{
	perrln(c);
}
