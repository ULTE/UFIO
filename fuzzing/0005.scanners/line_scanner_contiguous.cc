#include <string_view>
#include <ufio.h>
#include <ufio_device.h>

thread_local ufio::obuf_file obf("/dev/null");

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const *ptr, std::size_t n) noexcept
{
	ufio::ibuffer_view view(reinterpret_cast<char const *>(ptr), reinterpret_cast<char const *>(ptr) + n);
	for (std::string_view line : line_scanner(view))
	{
		write(obf, ptr, ptr + n);
	}
	return 0;
}