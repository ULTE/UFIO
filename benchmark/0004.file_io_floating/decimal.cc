#include <ufio.h>
#include <random>
#include <cfloat>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
using namespace ufio::io;

int main()
{
	constexpr std::size_t N{10000000};
	std::mt19937_64 eng{};
	std::uniform_real_distribution<double> dis(DBL_MIN, DBL_MAX);
	std::vector<double> vec;
	vec.reserve(N);
	for (std::size_t i{}; i != N; ++i)
	{
		vec.emplace_back(dis(eng));
	}
	{
		ufio::timer t(u8"decimal");
		ufio::u8obuf_file file(u8"decimal.txt");
		for (auto const &e : vec)
		{
			println(file, e);
		}
	}
}
