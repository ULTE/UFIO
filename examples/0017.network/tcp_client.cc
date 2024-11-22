#include <ufio.h>

int main()
{
	ufio::net_service service;
	ufio::native_socket_file socket(tcp_connect(ufio::ipv4{{127, 0, 0, 1}, 2000}));
	ufio::operations::transmit_bytes_until_eof(ufio::out(), socket);
}
