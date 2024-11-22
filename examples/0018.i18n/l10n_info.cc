#include <ufio.h>
#include <ufio_i18n.h>

using namespace ufio::io;

int main()
try
{
	ufio::native_l10n loc(u8"");
	println(imbue(loc, ufio::c_stdout()), loc);
}
catch (ufio::error e)
{
	perrln(e);
	return 1;
}