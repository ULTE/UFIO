#include <ufio.h>
#include <ufio_driver/qt.h>

using namespace ufio::io;

int main()
{
	QString qstr = "Hello QString\n";
	print(qstr);
}