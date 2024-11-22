#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <vector>
#include "longspaces.h"

int main()
{
	{
		ufio::timer t(u8"output");
		ufio::c_file obf(u8"stdio.txt", ufio::open_mode::out);
		using char_type = typename decltype(obf)::output_char_type;
		for (std::size_t i{}; i != N; ++i)
		{
			[[maybe_unused]] auto _ = fprintf(obf.fp, "%zu", i);
			[[maybe_unused]] auto __ = fwrite(filled_chars<char_type>.data(), filled_chars<char_type>.size(), sizeof(char_type), obf.fp);
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
