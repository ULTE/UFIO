#include <ufio.h>
#include <ufio_device.h>

ufio::net_service serivce;
thread_local ufio::iobuf_socket_file soc(ufio::tcp_connect(ufio::ipv4{{127, 0, 0, 1}, 2000}));

extern "C" int LLVMFuzzerTestOneInput(std::uint8_t const *ptr, std::size_t n) noexcept
{
	write(soc, ptr, ptr + n);
	return 0;
}