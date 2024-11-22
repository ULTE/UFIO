#include <string_view>
#include <ufio.h>
#include <ufio_device.h>

thread_local std::size_t context{};

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const *ptr, std::size_t n) noexcept
{
	::ufio::basic_http_header_buffer<char> buffer;
	auto ret{::ufio::details::http_header_scan_context_define_impl(context, reinterpret_cast<char const *>(ptr),
																	  reinterpret_cast<char const *>(ptr) + n, buffer)};
	return 0;
}