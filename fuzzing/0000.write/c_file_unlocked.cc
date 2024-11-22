#include <ufio.h>

ufio::c_file_unlocked obf("/dev/null", ufio::open_mode::out);

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const *ptr, std::size_t n) noexcept
{
	write(obf, ptr, ptr + n);
	return 0;
}