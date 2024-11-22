﻿#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main()
{
	ufio::net_service serivce;
	ufio::native_socket_file socket(ufio::tcp_listen(2000));
	ufio::obuf_file null_device(u8"/dev/null");
	ufio::native_file logs(u8"log.txt", ufio::open_mode::out);
	for (ufio::iobuf_socket_file soc;;)
	{
		try
		{
			soc.reopen(ufio::tcp_accept(socket));
			for (std::size_t sz; scan<true>(soc, ::ufio::mnp::le_get<64>(sz));)
				;
			soc.close();
		}
		catch (...)
		{
			perrln(logs, std::source_location::current());
		}
	}
	return 0;
}