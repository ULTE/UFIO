#include <ufio.h>
#include <ufio_i18n.h>

using namespace ufio::io;

int main()
{
	ufio::native_l10n loc(u8"");
	println(imbue(loc, ufio::c_stdout()), "Hello World ", -1248721947124LL, " ", ufio::mnp::boolalpha(true));
}