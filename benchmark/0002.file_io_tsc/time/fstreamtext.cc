#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"output");
		ufio::filebuf_file obf(u8"fsmtext.txt", ufio::open_mode::out | ufio::open_mode::text);
		std::ostream fout(obf.fb);
		for (std::size_t i{}; i != N; ++i)
		{
			fout << i;
			obf.fb->sputc('\n');
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::filebuf_file ibf(u8"fsmtext.txt", ufio::open_mode::in | ufio::open_mode::text);
		std::istream fin(ibf.fb);
		for (std::size_t i{}; i != N; ++i)
		{
			fin >> vec[i];
		}
	}
}
