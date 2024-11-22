#include <string>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	ufio::ipv6 v6{{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, 0xFFFF};
	std::string str = ufio::concat_std(v6);
	println(v6, "\n", str, "\n", ufio::to<ufio::ipv6>(str));
}
