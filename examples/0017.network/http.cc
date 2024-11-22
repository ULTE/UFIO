#include <ufio.h>
#include <ufio_device.h>
#include <string_view>

using namespace ufio::io;

int main(int argc, char const **argv)
{
	if (argc < 2)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", ::ufio::mnp::os_c_str(*argv), " <domain>\n");
		return 1;
	}
	ufio::net_service service;
	ufio::u8iobuf_socket_file socket{
		ufio::tcp_connect(ufio::to_ip(ufio::native_dns_file(::ufio::mnp::os_c_str(argv[1])), 80))};
	print(socket,
		  u8"GET / HTTP/1.1\r\n"
		  "Host:",
		  ::ufio::mnp::code_cvt_os_c_str(argv[1]), // this may be dangerous but here we just show the example
		  u8"\r\n"
		  "User-agent:whatever\r\n"
		  "Accept-Type:*/*\r\n"
		  "Connection:close\r\n\r\n");
	ufio::u8http_header_buffer buffer;
	scan(socket, buffer);
	using namespace std::string_view_literals;
	for (auto [key, value] : line_generator(buffer))
	{
		if (std::u8string_view(key) == u8"Content-Length"sv)
		{
			auto content_length{::ufio::u8to<std::uint_least64_t>(value)};
			ufio::u8native_file nf(u8"index.html", ufio::open_mode::out);
			::ufio::operations::transmit_bytes_some(nf, socket, content_length);
			return 0;
		}
	}
}
