#include <ufio_dsal/string.h>
#include <ufio.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	int test_i{};
	::ufio::string test_s("hellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohello");
	::ufio::string re;
	auto t0{ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)};
	for (std::size_t i{}; i != 1000000; ++i)
	{
		re = ufio::concat_ufio("hello", test_i, test_s);
	}
	print(ufio::posix_clock_gettime(ufio::posix_clock_id::realtime) - t0, "s ", re);
}
