#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>
#include <ufio_i18n.h>
using namespace ufio::io;

int main()
{
	ufio::native_l10n loc("");
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::obuf_file obf("iobuf_file_l10n.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			println(imbue(loc, obf), i);
		}
	}
}
