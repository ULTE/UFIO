#include <string>
#include <string_view>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::u16string u16str = ufio::u16concat_std(u"The fart is ", 18);
	char16_t const *cstylestr{u" years old hot girl😍.\n"};
	constexpr std::u8string_view simp{u8"Don't be a simp! Be a chad dude.\n"};
	using namespace ufio::mnp;
	std::u32string u32str = ufio::u32concat_std(code_cvt(u16str), code_cvt_os_c_str(cstylestr), U"Leroy!!!");
	print(code_cvt(u32str), " Jenkins!!!\n", ufio::mnp::code_cvt(simp));
}
