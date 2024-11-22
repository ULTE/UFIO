#include <string>
#include <string_view>
#include <ufio.h>
#include <ufio_device.h>

thread_local ufio::obuf_file obf(u8"/dev/null");
thread_local ufio::wobuf_file wobf(u8"/dev/null");
thread_local ufio::u8obuf_file u8obf(u8"/dev/null");
thread_local ufio::u16obuf_file u16obf(u8"/dev/null");
thread_local ufio::u32obuf_file u32obf(u8"/dev/null");

using namespace ufio::io;

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const *ptr, std::size_t n) noexcept
{
	std::string_view v(reinterpret_cast<char const *>(ptr), n);
	print(obf, ufio::concat(v));
	print(wobf, ufio::wconcat(ufio::mnp::code_cvt(v)));
	print(u8obf, ufio::u8concat(ufio::mnp::code_cvt(v)));
	print(u16obf, ufio::u16concat(ufio::mnp::code_cvt(v)));
	print(u32obf, ufio::u32concat(ufio::mnp::code_cvt(v)));
	print(obf, ufio::concat(ufio::mnp::code_cvt(ufio::u32concat(ufio::mnp::code_cvt(v))), v),
		  ufio::concat(ufio::mnp::code_cvt(ufio::u16concat(ufio::mnp::code_cvt(v))), v));
	print(wobf, ufio::wconcat(ufio::mnp::code_cvt(v)), ufio::wconcat(ufio::mnp::code_cvt(v)));
	print(u8obf, ufio::u8concat(ufio::mnp::code_cvt(v)), ufio::u8concat(ufio::mnp::code_cvt(v)));
	print(u16obf, ufio::u16concat(ufio::mnp::code_cvt(v)), ufio::u16concat(ufio::mnp::code_cvt(v)));
	print(u32obf, ufio::u32concat(ufio::mnp::code_cvt(v)), ufio::u32concat(ufio::mnp::code_cvt(v)));
	return 0;
}
