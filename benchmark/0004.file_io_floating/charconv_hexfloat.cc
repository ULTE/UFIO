﻿#include <ufio.h>
#include <random>
#include <cfloat>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <charconv>

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
		char buffer[40];
		auto start{buffer};
		ufio::timer t(u8"charconv hexfloat");
		ufio::obuf_file file(u8"hexfloat_charconv.txt");
		for (auto const &e : vec)
		{
			auto [res, ec] = std::to_chars(buffer, start + 40, e, std::chars_format::hex);
			*res = '\n';
			++res;
			::ufio::operations::write_all(file, start, res);
		}
	}
}
