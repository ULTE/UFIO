#include <ufio.h>
#include <ufio_driver/qt.h>

using namespace ufio::io;

int main()
{
	ufio::qt_file file("a.txt", ufio::open_mode::out);
	print(file, "Hello World", 20, " die\n");
}
