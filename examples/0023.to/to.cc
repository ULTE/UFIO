#include <cstdint>
#include <ufio.h>

using namespace ufio::io;

int main()
{
#ifdef __SIZEOF_INT128__
	constexpr __uint128_t s{ufio::to<__uint128_t>("   2424", ufio::mnp::left(0, 30, '0'),
													 " sgdjasdopgjdasgpojadsgpoadjsgpoadsjgopjaghdsoighasdioghadsoi")};
	println(s);
#endif
}
