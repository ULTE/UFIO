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
		ufio::u8c_file_unlocked obf(u8"c_file_unlocked_text.txt",
									   ufio::open_mode::out | ufio::open_mode::text);
		for (std::size_t i{}; i != N; ++i)
		{
			println(obf, i);
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::u8c_file_unlocked ibf(u8"c_file_unlocked_text.txt", ufio::open_mode::in | ufio::open_mode::text);
		for (std::size_t i{}; i != N; ++i)
		{
			scan(ibf, vec[i]);
		}
	}
}
