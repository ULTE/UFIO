#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/cryptopp_driver.h>
#include <cryptopp/sha.h>

/*
Need to install CryptoPP first
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
	ufio::ibuf_file ibf(os_c_str(argv[1]));
	ufio::cryptopp::iterated_hash_context<CryptoPP::SHA256> ctx;
	auto transmitted{::ufio::operations::transmit_bytes_until_eof(as_file(ctx), ibf)};
	ctx.do_final();
	println(hash_digest(ctx), " *", os_c_str(argv[1]), "\nTransmitted:", transmitted,
			" bytes\tElapsed Time:", ufio::posix_clock_gettime(ufio::posix_clock_id::realtime) - t0);
}
