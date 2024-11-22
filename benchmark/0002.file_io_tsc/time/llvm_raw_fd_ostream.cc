#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/llvm.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::llvm::raw_fd_ostream_file fsof(u8"llvm_raw_fd_ostream.txt", ufio::open_mode::out);
		auto &os(*fsof.os);
		for (std::size_t i{}; i != N; ++i)
		{
			os << i << '\n';
		}
	}
}
