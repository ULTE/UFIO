#include <ufio.h>
#include <ufio_device.h>

thread_local ufio::obuf_file obf(u8"/dev/null");

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const *ptr, std::size_t n) noexcept
{
	auto e{::ufio::details::my_rfind_dot(ptr, ptr + n)};
	write(obf, ptr, e);
	return 0;
}