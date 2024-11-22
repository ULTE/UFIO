#include <ufio_device.h>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	ufio::obuf_file obf(u8"constant.txt");
	println(obf, 3);
	static_assert(ufio::constant_buffer_output_stream<ufio::obuf_file>);
	static_assert(ufio::constant_buffer_output_stream<ufio::u8ogb18030_file>);
}