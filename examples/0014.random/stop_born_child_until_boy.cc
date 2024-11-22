// This is an emulation on how many times you can keep born a child to be a boy without abortion.
#include <random>
#include <ufio.h>
#include <map>

using namespace ufio::io;

int main(int argc, char **argv)
{
	using namespace ufio::mnp;
	if (argc < 2)
	{
		if (argc == 0)
		{
			return 1;
		}
		perr("Usage: ", os_c_str(*argv), " N\n");
		return 1;
	}
	constexpr auto natural_male_to_female_ratio{1.03};
	constexpr auto total_ratio{natural_male_to_female_ratio + 1.0};
	constexpr auto male_probability{natural_male_to_female_ratio / total_ratio};
	ufio::ibuf_white_hole_engine engine;
	std::bernoulli_distribution dis(male_probability);

	::std::uint_least64_t const n{::ufio::to<::std::uint_least64_t>(os_c_str(argv[1]))};
	::std::map<std::uint_least64_t, std::uint_least64_t> map;
	::std::uint_least64_t total_population{};
	for (::std::uint_least64_t i{}; i != n; ++i)
	{
		std::uint_least64_t j{1};
		for (; !dis(engine); ++j)
			;
		++map[j];
		total_population += j;
	}
	ufio::out_buf_type obf(ufio::out());
	for (auto const &e : map)
	{
		print(obf, e.first, " ", e.second, " (", percentage_conventional(e.second, n), ")\n");
	}
	::std::uint_least64_t const females{total_population - n};
	println(obf, "males:", n, "\tfemales:", females,
			"\n"
			"total population:",
			total_population,
			"\n"
			"Sex Ratio:",
			percentage_sex_ratio(n, females));
}
