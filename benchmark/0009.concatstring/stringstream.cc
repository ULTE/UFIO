#include <string>
#include <ufio.h>
#include <ufio_driver/timer.h>
#include <sstream>
using namespace ufio::io;

int main()
{
	int test_i{};
	std::string test_s{"hellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohello"};
	std::string re{};
	auto t0{ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)};
	std::ostringstream sst;
	for (std::size_t i{}; i != 1000000; ++i)
	{
		sst.str("");
		sst << "hello" << test_i << test_s;
		re = sst.str();
	}
	print(ufio::posix_clock_gettime(ufio::posix_clock_id::realtime) - t0, "s ", re);
}
