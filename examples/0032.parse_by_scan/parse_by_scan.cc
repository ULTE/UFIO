#include <ufio.h>

using namespace ufio::io;

int main()
{
	constexpr char8_t const testbuffer[]{u8"412741298414 1235321525"};
	::std::uint_least64_t val;
	auto [position, code] = ::ufio::parse_by_scan(testbuffer, testbuffer + sizeof(testbuffer), val);
	if (code != ::ufio::parse_code::ok)
	{
		perr("parse failed\n");
		return 1;
	}
	println("val=", val, " position:", position - testbuffer);
}