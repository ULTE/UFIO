#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include "generate.h"

int main()
{
	auto tb{generate_random_data()};
	{
		ufio::timer t(u8"output");
		ufio::c_file cf(u8"stdio.txt", ::ufio::open_mode::out);
		for (auto &e : tb)
		{
			[[maybe_unused]] auto _ = fprintf(cf.fp, "%zu\n", e);
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::c_file cf(u8"stdio.txt", ::ufio::open_mode::in);
		for (std::size_t i{}; i != N; ++i)
		{
			[[maybe_unused]] auto _ = fscanf(cf.fp, "%zu", vec.data() + i);
		}
	}
}
