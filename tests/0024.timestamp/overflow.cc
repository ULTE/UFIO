#include <string>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::string s{"2022-12-01T01:60:57.1928303948203949323422366Z"};
	try
	{
		[[maybe_unused]] auto tsp = ufio::to<ufio::iso8601_timestamp>(s);
	}
	catch (ufio::error e)
	{
		print(static_cast<ufio::parse_code>(e.code));
	}
}