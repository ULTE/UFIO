#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <vector>

int main()
{
	constexpr std::size_t N(1000000);
	{
		ufio::timer t(u8"output");
		ufio::c_file obf(u8"stdio.txt", ufio::open_mode::out);
		for (std::size_t i{}; i != N; ++i)
		{
			[[maybe_unused]] auto _ = fprintf(obf.fp, "%zu\n", i);
		}
	}
	std::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::c_file ibf(u8"stdio.txt", ufio::open_mode::in);
		for (std::size_t i{}; i != N; ++i)
		{
			[[maybe_unused]] auto _ = fscanf(ibf.fp, "%zu", vec.data() + i);
		}
	}
}