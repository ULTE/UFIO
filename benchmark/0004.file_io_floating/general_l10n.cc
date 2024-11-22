#include <ufio.h>
#include <random>
#include <cfloat>
#include <ufio_device.h>
#include <ufio_driver/timer.h>
#include <ufio_i18n.h>
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
	ufio::native_l10n l10n("");
	{
		ufio::timer t(u8"general_l10n");
		ufio::u8obuf_file file(u8"general_l10n.txt");
		for (auto const &e : vec)
		{
			println(imbue(l10n, file), ufio::mnp::general(e));
		}
	}
}
