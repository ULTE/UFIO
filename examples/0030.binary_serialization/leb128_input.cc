#include <string>
#include <limits>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::uint64_t u1, u2;
	std::int64_t i1, i2;
	std::string buffer(10000, '\0');
	u1 = 14142;
	using namespace ufio::mnp;
	print(ufio::obuffer_view{buffer}, leb128_put(u1));
	scan(ufio::ibuffer_view{buffer}, leb128_get(u2));
	println("u2 == ", hex0x(u2), "\t u1 == u2: ", boolalpha(u1 == u2));

	i1 = std::numeric_limits<std::int64_t>::max();
	print(ufio::obuffer_view{buffer}, leb128_put(i1));
	scan(ufio::ibuffer_view{buffer}, leb128_get(i2));
	println("i2 == ", hex0x(i2), "\t i1 == i2: ", boolalpha(i1 == i2));

	i1 = std::numeric_limits<std::int64_t>::min();
	print(ufio::obuffer_view{buffer}, leb128_put(i1));
	scan(ufio::ibuffer_view{buffer}, leb128_get(i2));
	println("i2 == ", hex0x(i2), "\t i1 == i2: ", boolalpha(i1 == i2));
}
