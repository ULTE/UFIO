#include <ufio.h>
#include <ufio_driver/timer.h>
#include <ufio_dsal/vector.h>

int main()
{
	ufio::timer tm(u8"ufio::vector::push_back");
	ufio::vector<std::size_t> vec;
	constexpr std::size_t n{100000000};
	vec.reserve(n);
	for (std::size_t i{}; i != n; ++i)
	{
		vec.emplace_back(i);
	}
}