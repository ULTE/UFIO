#include <ufio.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>

int main()
{
	ufio::timer t(u8"ufio::vector");
	ufio::vector<std::size_t> vec(100000000);
}