#include <ufio.h>
#include <ufio_legacy.h>
#include <ufio_driver/timer.h>
#include <ufio_device.h>
using namespace ufio::io;

inline void test()
{
	ufio::nt_file wf(ufio::io_dup, ufio::nt_stdout());
	ufio::filebuf_file fbf(std::move(wf), ufio::open_mode::out);
	std::ofstream fout;
	*fout.rdbuf() = std::move(*fbf.fb);
	for (std::size_t i{}; i != 1000000; ++i)
	{
		fout << i << '\n';
	}
}

int main()
{
	ufio::u8obuf_file timer_obf(u"fstream.txt");
	ufio::timer t(u8"fstream");
	test();
}
