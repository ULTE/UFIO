#include <ufio.h>
#include <ufio_driver/qt.h>
#include <QtCore/QVariant>

using namespace ufio::io;

int main()
{
	QVariant var = 4.503;
	println("var:", var);
}