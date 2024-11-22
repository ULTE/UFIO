#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::obuf_file_lockable obf(u8"iobuf_file_lockable_big.txt");
		ufio::io_lock_guard guard{obf};
		for (std::size_t i{}; i != N; ++i)
		{
			println(obf.unlocked_handle(), i);
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::ibuf_file_lockable ibf(u8"iobuf_file_lockable_big.txt");
		ufio::io_lock_guard guard{ibf};
		for (std::size_t i{}; i != N; ++i)
		{
			scan(ibf.unlocked_handle(), vec[i]);
		}
	}
}
