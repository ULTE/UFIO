#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::obuf_file obf(u8"iobuf_file_bin.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			write(obf, __builtin_addressof(i), __builtin_addressof(i) + 1);
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::ibuf_file ibf(u8"iobuf_file_bin.txt");
		for (auto it{vec.begin()}; it != vec.cend(); ++it)
		{
			::ufio::read_all(ibf, it, it + 1);
		}
	}
}
