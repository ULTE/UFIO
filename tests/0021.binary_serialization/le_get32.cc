#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::uint_least32_t u;
	scan(ufio::mnp::le_get<32>(u));
}
