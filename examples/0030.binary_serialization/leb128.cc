#include <string>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	using namespace ufio::mnp;
	constexpr std::size_t v{142142};
	auto str{ufio::u8concat_std(leb128_put(v))};
	println(rgvw(str, "\t"));

	str = ufio::u8concat_std(leb128_put(PTRDIFF_MAX));
	println(rgvw(str, "\t"));

	str = ufio::u8concat_std(leb128_put(PTRDIFF_MIN));
	println(rgvw(str, "\t"));
}