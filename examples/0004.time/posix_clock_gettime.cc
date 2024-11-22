#include <ufio.h>

using namespace ufio::io;

int main()
{
	ufio::posix_tzset();
	ufio::unix_timestamp tsp{ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)};
	println("Unix Timestamp:", tsp,
			"\n"
			"utc:",
			utc(tsp),
			"\n"
			"local:",
			local(tsp),
			"\n"
			"timezone:",
			ufio::timezone_name());
}
