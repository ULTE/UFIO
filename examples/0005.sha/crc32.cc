#include <ufio.h>
#include <ufio_device.h>
#include <ufio_crypto.h>

/*
This is just for demo purpose. You should avoid crc32 families in general because it is not even a crypto hash function.
*/

using namespace ufio::io;

int main(int argc, char **argv)
{
	using namespace ufio::mnp;
	if (argc != 2)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", os_c_str(*argv), " <file>\n");
		return 1;
	}
	auto t0{ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)};
	ufio::crc32_context crc;
	ufio::ibuf_file ibf(os_c_str(argv[1]));
	auto transmitted{::ufio::operations::transmit_bytes_until_eof(as_file(crc), ibf)};
	crc.do_final();
	println(hash_digest(crc), " *", os_c_str(argv[1]), "\nTransmitted:", transmitted,
			" bytes\tElapsed Time:", ufio::posix_clock_gettime(ufio::posix_clock_id::realtime) - t0);
}
