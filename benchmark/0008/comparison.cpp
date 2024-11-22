#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>

#include <charconv>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <cfloat>

#include "dragonbox/dragonbox_to_chars.h"

// both ufio::pr_rsv_size<char, double> and jkj::dragonbox::max_output_string_length<jkj::dragonbox::ieee754_binary64> are 24 so 25 with trailing null terminator
constexpr int buf_size = 25;

inline void charconv_ofstream(std::vector<double> const &vec)
{
	ufio::timer t(u8"charconv");
	std::ofstream ofs{"charconv.txt"};
	for (auto const e : vec)
	{
		char buf[buf_size]{0};
		std::to_chars(buf, buf + buf_size, e, std::chars_format::scientific);
		ofs << buf << '\n';
	}
}

inline void charconv_ufio(std::vector<double> const &vec)
{
	ufio::timer t(u8"charconv2");
	ufio::obuf_file file{u8"charconv2.txt"};
	for (auto const e : vec)
	{
		char buf[buf_size]{0};
		std::to_chars(buf, buf + buf_size, e, std::chars_format::scientific);
		println(file, ufio::mnp::os_c_str(buf));
	}
}

inline void ufio_ofstream(std::vector<double> const &vec)
{
	ufio::timer t(u8"ufio");
	std::ofstream ofs{"ufio.txt"};
	for (auto const e : vec)
	{
		char buf[buf_size]{0};
		ufio::pr_rsv_to_c_array(buf, ufio::mnp::scientific(e));
		ofs << buf << '\n';
	}
}

inline void ufio_ufio(std::vector<double> const &vec)
{
	ufio::timer t(u8"ufio2");
	ufio::obuf_file file{u8"ufio2.txt"};
	for (auto const e : vec)
	{
		char buf[buf_size]{0};
		ufio::pr_rsv_to_c_array(buf, ufio::mnp::scientific(e));
		println(file, ufio::mnp::os_c_str(buf));
	}
}

inline void dragonbox_ofstream(std::vector<double> const &vec)
{
	ufio::timer t(u8"dragonbox");
	std::ofstream ofs{"dragonbox.txt"};
	for (auto const e : vec)
	{
		char buf[buf_size]{0};
		jkj::dragonbox::to_chars(e, buf);
		ofs << buf << '\n';
	}
}

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

	charconv_ofstream(vec);
	charconv_ufio(vec);

	ufio_ofstream(vec);
	ufio_ufio(vec);

	dragonbox_ofstream(vec);
	dragonbox_ufio(vec);

	return 0;
}