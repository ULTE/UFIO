#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include "dragonbox/dragonbox_to_chars.h"
#include <random>
#include <vector>
#include <cfloat>
using namespace ufio::io;

constexpr int buf_size = 25;

inline void dragonbox_ufio(std::vector<double> const &vec)
{
	ufio::timer t(u8"dragonbox2");
	ufio::obuf_file file{u8"dragonbox2.txt"};
	for (auto const e : vec)
	{
		char buf[buf_size]{0};
		jkj::dragonbox::to_chars(e, buf);
		println(file, ufio::mnp::os_c_str(buf));
	}
}

int main()
{
	constexpr std::size_t N = 10'000'000;

	std::mt19937_64 eng{};
	std::uniform_real_distribution<double> dis(DBL_MIN, DBL_MAX);
	std::vector<double> vec;
	vec.reserve(N);
	for (std::size_t i{}; i != N; ++i)
	{
		vec.emplace_back(dis(eng));
	}
	dragonbox_ufio(vec);
}
