#include <ufio.h>
#include <ufio_unit/gb18030.h>
#include <ufio_device.h>

ufio::ogb18030_file obf("/dev/null");

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const *ptr, std::size_t n) noexcept
{
	write(obf, ptr, ptr + n);
	return 0;
}