#include <ufio.h>
#include <ufio_driver/timer.h>
#include <vector>

int main()
{
	ufio::timer tm(u8"std::vector::push_back");
	std::vector<std::size_t> vec;
	constexpr std::size_t n{100000000};
	vec.reserve(n);
	for (std::size_t i{}; i != n; ++i)
	{
		vec.push_back(i);
	}
}