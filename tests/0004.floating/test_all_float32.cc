#include <ufio.h>
#include <ufio_device.h>
#include <ufio_crypto.h>
#include <ufio_driver/timer.h>

using namespace ufio::io;

int main()
{
	using namespace ufio::mnp;
	ufio::timer tm(u8"test float32 ");
	ufio::sha256_context sha;
	{
		constexpr std::uint64_t v{UINT32_MAX};
		for (std::uint64_t i{}; i <= v; ++i)
		{
			std::uint32_t low32bits{static_cast<std::uint32_t>(i)};
			println(as_file(sha), ufio::mnp::scientific(std::bit_cast<float>(low32bits)));
		}
		//	flush(sha_obf);
		sha.do_final();
	}
	println("sha256=", hash_digest(sha));
}
