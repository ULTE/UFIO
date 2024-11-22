#include <ufio.h>
#include <ufio_i18n.h>

using namespace ufio::io;

int main()
{
	ufio::native_l10n loc("");
	println(imbue(loc, ufio::c_stdout()), "rigstr\t", ufio::mnp::internal("asf", 10), "\n"
																							"lft\t",
			ufio::mnp::left(-10000, 10), "\n"
											"mid\t",
			ufio::mnp::middle(-10000, 10), "\n"
											  "rig\t",
			ufio::mnp::right(-10000, 10), "\n"
											 "int\t",
			ufio::mnp::internal(-10000, 10), "\n"
												"lefch\t",
			ufio::mnp::left(-10000, 10, '+'), "\n"
												 "midch\t",
			ufio::mnp::middle(-10000, 10, '+'), "\n"
												   "rigch\t",
			ufio::mnp::right(-10000, 10, '+'), "\n"
												  "intch\t",
			ufio::mnp::internal(-10000, 10, '+'));
}
