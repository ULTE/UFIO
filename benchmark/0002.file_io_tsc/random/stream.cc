#include <ufio.h>
#include <ufio_device.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
#include "generate.h"

int main()
{
	auto tb{generate_random_data()};
	{
		ufio::timer t(u8"output");
		ufio::filebuf_file fbf(u8"stream.txt", ::ufio::open_mode::out);
		::std::ostream os(fbf.fb);
		for (auto &e : tb)
		{
			os << e << '\n';
		}
	}
	::ufio::vector<std::size_t> vec(N);
	{
		ufio::timer t(u8"input");
		ufio::filebuf_file fbf(u8"stream.txt", ::ufio::open_mode::in);
		::std::istream ism(fbf.fb);
		for (std::size_t i{}; i != N; ++i)
		{
			ism >> vec[i];
		}
	}
}
