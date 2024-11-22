#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
#include <vector>
#include <iomanip>

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::filebuf_file obf(u8"fstream.txt", ufio::open_mode::out);
		std::ostream fout(obf.fb);
		fout << std::hex;
		for (std::size_t i{}; i != N; ++i)
		{
			fout << i << '\n';
		}
	}
	std::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::filebuf_file ibf(u8"fstream.txt", ufio::open_mode::in);
		std::istream fin(ibf.fb);
		fin >> std::hex;
		for (std::size_t i{}; i != N; ++i)
		{
			fin >> vec[i];
		}
	}
}
