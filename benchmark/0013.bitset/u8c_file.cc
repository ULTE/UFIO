#include <bitset>
#include <ufio.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
#if __cpp_lib_constexpr_bitset >= 202207L
	constexpr
#endif
		std::bitset<152>
			bts("110111100000111111111111111111111111101101111000001111111111111111111111111011011110000011111111111111"
				"11111111111011011110000011111111111111111111111110");
	constexpr std::size_t N{1000000UL};
	ufio::timer t(u8"u8c_file");
	ufio::u8c_file obf(u8"u8c_file.txt", ufio::open_mode::out);
	for (std::size_t i{}; i != N; ++i)
	{
		println(obf, bts);
	}
}
