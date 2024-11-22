#include <string>
#include <atlfile.h>
#include <ufio_driver/mfc.h>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	ufio::atl_file file(u"atl.txt", ufio::open_mode::out);
	print(file, "Hello World\n");
}
