#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
#include <vector>
#include "longspaces.h"

int main()
{
	{
		ufio::timer t(u8"output");
		ufio::filebuf_file obf(u8"fstream.txt", ufio::open_mode::out);
		std::ostream fout(obf.fb);
		for (std::size_t i{}; i != N; ++i)
		{
			fout << i;
			obf.fb->sputn(filled_chars<char>.data(), static_cast<std::streampos>(filled_chars<char>.size()));
		}
	}
	std::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::filebuf_file ibf(u8"fstream.txt", ufio::open_mode::in);
		std::istream fin(ibf.fb);
		for (std::size_t i{}; i != N; ++i)
		{
			fin >> vec[i];
		}
	}
}
