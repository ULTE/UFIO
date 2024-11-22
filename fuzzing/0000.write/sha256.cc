#include <ufio.h>
#include <ufio_crypto.h>
#include <ufio_device.h>

thread_local ufio::sha256_context ctx;
thread_local ufio::u32obuf_file obf(u8"/dev/null");

using namespace ufio::io;

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const *ptr, std::size_t n) noexcept
{
	ctx.reset();
	for (std::size_t i{}; i != 16; ++i)
	{
		write(::ufio::mnp::as_file(ctx), ptr, ptr + n);
	}
	ctx.do_final();
	println(obf, ::ufio::mnp::hash_digest(ctx));
	return 0;
}
