#include <string>
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
		ufio::obuf_file obf("iobuf_file_concatln.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			print(obf, ufio::concatln_std(i));
		}
	}
}
