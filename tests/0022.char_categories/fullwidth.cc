#include <ufio.h>

using namespace ufio::io;

int main()
{
	using namespace ufio::char_category;
	using namespace ufio::mnp;
	println(ufio::u8c_stdout(),
			u8"！\t", boolalpha(is_c_fullwidth(U'！')), u8"\n"
														u8"!\t",
			boolalpha(is_c_fullwidth(U'!')), u8"\n"
											 u8"＀\t",
			boolalpha(is_c_fullwidth(U'＀')), u8"\n"
											   u8"｠\t",
			boolalpha(is_c_fullwidth(U'｠')), u8"\n"
											  u8"！\t",
			to_c_halfwidth(U'！'));
}