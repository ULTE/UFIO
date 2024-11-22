#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main()
{
	ufio::net_service service;
	ufio::native_socket_file socket(ufio::tcp_listen(2000));
	for (ufio::iobuf_socket_file file;;)
	{
		try
		{
			file.reopen(tcp_accept(socket));
			println(file, utc(ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)));
			file.close();
		}
		catch (...)
		{
		}
	}
}
