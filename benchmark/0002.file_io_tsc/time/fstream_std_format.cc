#include <string>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>
#include <format>
#include <fstream>

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		std::ofstream fout("fstream_std_format.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			fout << std::format("{}\n", i);
		}
	}
}
