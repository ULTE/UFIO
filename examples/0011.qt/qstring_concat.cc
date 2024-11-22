#include <ufio.h>
#include <ufio_driver/qt.h>

using namespace ufio::io;

int main()
{
	QString qstr = ufio::u16concat_qt_qstring(u"Hello QString\n", 24.43624362634, u"124124");
	print(qstr);
}