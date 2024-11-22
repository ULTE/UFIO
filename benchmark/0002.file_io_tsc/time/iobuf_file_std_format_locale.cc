#include <string>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>
#include <format>
#include <locale>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		std::locale loc("");
		ufio::timer t(u8"output");
		ufio::obuf_file obf(u8"iobuf_file_std_format_locale.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			print(obf, std::format(loc, "{}\n", i));
		}
	}
}
