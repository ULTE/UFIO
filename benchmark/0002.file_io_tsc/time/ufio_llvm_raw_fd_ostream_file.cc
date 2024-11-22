#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/llvm.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::llvm::raw_fd_ostream_file fsof(u8"ufio_llvm_raw_fd_ostream_file.txt", ufio::open_mode::out);
		for (std::size_t i{}; i != N; ++i)
		{
			println(fsof, i);
		}
	}
}
