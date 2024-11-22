#include <ufio.h>
#include <ufio_i18n.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	ufio::vector<char> q;
	ufio::native_l10n l10n{"en_US.UTF-8"};
	println(imbue(l10n, ufio::c_stdout()), "Maximum size of a std::vector is ", q.max_size());
}