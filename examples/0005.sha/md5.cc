#include <ufio.h>
#include <ufio_device.h>
#include <ufio_crypto.h>

/*
This is just for demo purpose. You should avoid md5 in general because it is insecure.
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
	ufio::md5_context md;
	ufio::ibuf_file ibf(os_c_str(argv[1]));
	auto transmitted{::ufio::operations::transmit_bytes_until_eof(as_file(md), ibf)};
	md.do_final();
	println(hash_digest(md), " *", os_c_str(argv[1]), "\nTransmitted:", transmitted,
			" bytes\tElapsed Time:", ufio::posix_clock_gettime(ufio::posix_clock_id::realtime) - t0);
}
