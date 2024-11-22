#include <winrt/base.h>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"winrt::to_hstring");
		ufio::obuf_file obf(u"winrt_to_hstring.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			println(obf, winrt::to_hstring(i));
		}
		// this is a little bit cheat to the benchmark. but i guess it would still be extremely slow
	}
}
