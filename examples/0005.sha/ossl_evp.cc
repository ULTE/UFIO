#include <ufio.h>
#include <ufio_device.h>
#include <ufio_hosted_crypto.h>

using namespace ufio::io;

int main(int argc, char **argv)
try
{
	using namespace ufio::mnp;
	if (argc != 3)
	{
		if (argv == 0)
		{
			return 1;
		}
		perr("Usage: ", os_c_str(*argv), " <hash algorithm> <file>\n");
		return 1;
	}
	auto t0{ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)};
	ufio::ossl_evp_hash_file ctx(::ufio::mnp::os_c_str(argv[1]));
	ufio::ibuf_file ibf(os_c_str(argv[2]));
	auto transmitted{::ufio::operations::transmit_bytes_until_eof(as_file(ctx), ibf)};
	ctx.do_final();
	println(hash_digest(ctx), " *", os_c_str(argv[2]), "\nAlgorithm:", ::ufio::mnp::os_c_str(argv[1]),
			"\nTransmitted:", transmitted,
			" bytes\tElapsed Time:", ufio::posix_clock_gettime(ufio::posix_clock_id::realtime) - t0);
}
catch (ufio::error e)
{
	perrln(e);
	return 1;
}
