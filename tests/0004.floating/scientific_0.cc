#include <ufio.h>
#include <ufio_i18n.h>

using namespace ufio::io;

int main()
{
	using namespace ufio::mnp;
	ufio::native_l10n loc("");
	constexpr float value{-2.271745e-01f};
	print("general:\t", value, "\t", comma_general(value), "\n"
														   "scientific:\t",
		  scientific(value), "\t", comma_scientific(value), "\n"
															"fixed:  \t",
		  fixed(value), "\t", comma_fixed(value), "\n"
												  "hexfloat:\t",
		  hexfloat(value), "\t", comma_hexfloat(value));
	println(imbue(loc, ufio::c_stdout()), "\n\n"
											 "lc:\n"
											 "general:\t",
			value, "\n"
				   "scientific:\t",
			ufio::mnp::scientific(value), "\n"
											 "fixed:  \t",
			fixed(value), "\n"
						  "hexfloat:\t",
			hexfloat(value));
}
