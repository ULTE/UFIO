#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main()
try
{
	ufio::obuf_file pf(u8"example.txt", ufio::open_mode::app);
	ufio::file_lock_guard g(file_lock(pf.handle), ufio::flock_request_l64{});
	ufio::io_flush_guard g2(pf);
	for (std::size_t i{}; i != 1000000; ++i)
	{
		print(pf, "Hello ");
		print(pf, "World\n");
	}
}
catch (ufio::error e)
{
	perrln(e);
	return 1;
}