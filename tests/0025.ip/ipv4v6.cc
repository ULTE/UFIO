#include <ufio.h>

using namespace ufio::io;

int main()
{
	constexpr ::ufio::ipv4 v4{{0xFF, 0xFF, 0xFF, 0xFF}, 0xFFFF};
	constexpr ::ufio::ipv6 v6{{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, 0xFFFF};
	constexpr ::ufio::ip ip0{::ufio::ipv6{{0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, 0xFFFF}};

	constexpr ::ufio::ip ip1{::ufio::ipv6{{0xFFFF, 0xFFFF, 0, 0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF}, 0xFFFF}};

	constexpr ::ufio::ip ip2{::ufio::ipv6{{0xFFFF, 0xFFFF, 0, 0, 0, 0xFFFF, 0, 0}, 0xFFFF}};

	constexpr ::ufio::ip ip3{::ufio::ipv6{{0xFFFF, 0xFFFF, 0, 0, 0, 0, 0, 0}, 0xFFFF}};

	constexpr ::ufio::ip ip4{::ufio::ipv6{{0, 0, 0, 0, 0xFFFF, 0xFFFF, 0, 0}, 0xFFFF}};

	constexpr ::ufio::ip ip5{::ufio::ipv6{{0, 0, 0, 0, 0, 0, 0xFFFF, 0xFFFF}, 0xFFFF}};

	constexpr ::ufio::ip ip6{::ufio::ipv6{{}, 0xFFFF}};

	println("v4:", v4, "\n"
					   "v6:",
			v6, "\n"
				"ip0:",
			ip0, "\n"
				 "ip1:",
			ip1, "\n"
				 "ip2:",
			ip2, "\n"
				 "ip3:",
			ip3, "\n"
				 "ip4:",
			ip4, "\n"
				 "ip5:",
			ip5, "\n"
				 "ip6:",
			ip6);
}