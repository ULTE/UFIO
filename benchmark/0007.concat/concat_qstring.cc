#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/qt.h>
#include <vector>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"concat_qstring");
		ufio::obuf_file obf("concat_qstring.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			print(obf, ufio::u16concatln_qt_qstring(i));
		}
	}
}
