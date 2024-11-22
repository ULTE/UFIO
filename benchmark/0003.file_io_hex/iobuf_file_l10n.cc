#include <ufio.h>
#include <ufio_device.h>
#include <ufio_i18n.h>
#include <ufio_driver/timer.h>
#include <vector>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::obuf_file obf("iobuf_file_l10n.txt");
		ufio::native_l10n loc("");
		for (std::size_t i{}; i != N; ++i)
		{
			println(imbue(loc, obf), ufio::mnp::hex(i));
		}
	}
}
