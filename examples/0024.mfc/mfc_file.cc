#include <string>
#include <afx.h>
#include <ufio_driver/mfc.h>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	ufio::mfc_file file(u"mfc.txt", ufio::open_mode::out);
	print(file, "Hello World\n");
}
