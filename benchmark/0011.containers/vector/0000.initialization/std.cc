#include <ufio.h>
#include <ufio_driver/timer.h>
#include <vector>

int main()
{
	ufio::timer t(u8"std::vector");
	std::vector<std::size_t> vec(100000000);
}