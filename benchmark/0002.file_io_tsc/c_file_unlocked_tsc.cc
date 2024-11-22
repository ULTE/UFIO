#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/tsc_timer.h>
#include <vector>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::tsc_timer t(u8"output");
		ufio::u8c_file_unlocked obf(u8"c_file_unlocked_tsc.txt", ufio::open_mode::out);
		for (std::size_t i{}; i != N; ++i)
		{
			println(obf, i);
		}
	}
	std::vector<std::size_t> vec(N);
	{
		ufio::tsc_timer t(u8"input");
		ufio::u8c_file_unlocked ibf(u8"c_file_unlocked_tsc.txt", ufio::open_mode::in);
		for (std::size_t i{}; i != N; ++i)
		{
			scan(ibf, vec[i]);
		}
	}
}
