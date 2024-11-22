#include <atlstr.h>
#include <ufio_driver/mfc.h>
#include <ufio.h>
#include <ufio_driver/timer.h>
#include <ufio_device.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N(10000000);
	{
		ufio::timer t(u8"concat_cstring");
		ufio::obuf_file obf("concat_cstring.txt");
		for (std::size_t i{}; i != N; ++i)
		{
			print(obf, ufio::concatln_atl_cstring(i));
		}
	}
}
