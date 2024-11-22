#include <ufio.h>

using namespace ufio::io;

int main()
{
	constexpr auto tsp = ufio::to<ufio::iso8601_timestamp>("2022-12-01T01:23:45.1928303948203949323422366Z");
	println(tsp);
}
