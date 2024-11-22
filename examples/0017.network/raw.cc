#include <ufio.h>

int main()
{
	ufio::net_service service;
	ufio::native_socket_file sock(ufio::sock_family::inet, ufio::sock_type::stream, ufio::open_mode{},
									 ufio::sock_protocol::ip);
	constexpr ufio::posix_sockaddr_in in{.sin_family = to_native_sock_family(ufio::sock_family::inet),
											.sin_port = ufio::big_endian(static_cast<std::uint16_t>(100)),
											.sin_addr = {192, 168, 0, 1}};
	posix_connect(sock, std::addressof(in), sizeof(in));
}
