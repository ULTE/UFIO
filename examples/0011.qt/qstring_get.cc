#include <ufio.h>
#include <ufio_driver/qt.h>

using namespace ufio::io;

int main()
{
	QString qstr;
	scan(ufio::mnp::strlike_get(qstr));
	println(qstr);
}
