#include <string_view>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_crypto.h>

using namespace ufio::io;

int main()
{
	ufio::net_service serivce;
	ufio::native_socket_file socket(ufio::tcp_listen(2000));
	ufio::sha256_context ctx; // use sha256 to prevent zero-copy transmission
	ufio::native_file logs(u8"log.txt", ufio::open_mode::out);
	for (ufio::u8ibuf_file soc;;) // should work directly on unix like OS
	{
		try
		{
			soc.reopen(ufio::tcp_accept(socket));
			for (std::u8string_view line : line_scanner(soc))
			{
				println(::ufio::mnp::u8as_file(ctx), line);
			}
			soc.close();
			println("sha256:", ufio::mnp::hash_digest(ctx));
		}
		catch (...)
		{
			perrln(logs, std::source_location::current());
		}
	}
	return 0;
}
