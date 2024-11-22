
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	auto iso8601_ts{utc(ufio::posix_clock_gettime(ufio::posix_clock_id::realtime))};
	{
		ufio::timer timer(u8"ufio");
		ufio::obuf_file obf(u8"iso8601.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			println(obf, iso8601_ts);
		}
	}
}