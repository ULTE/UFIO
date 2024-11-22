#include <ufio_device.h>
#include <ufio.h>
#include <ufio_driver/timer.h>
#include <ufio_i18n.h>
using namespace ufio::io;

int main()
{
	ufio::native_l10n l10n("");
	constexpr std::size_t N(10000000);
	auto iso8601_ts{utc(ufio::posix_clock_gettime(ufio::posix_clock_id::realtime))};
	{
		ufio::timer timer(u8"ufio");
		ufio::obuf_file obf(u8"ufio.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			println(imbue(l10n, obf), ufio::mnp::date_fmt(iso8601_ts));
		}
	}
}