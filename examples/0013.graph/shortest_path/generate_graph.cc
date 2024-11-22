#include <ufio.h>
#include <ufio_device.h>
#include <random>
#include <ufio_driver/timer.h>

using namespace ufio::io;

int main()
{
	::ufio::timer timer(u8"generate_graph");
	ufio::u8obuf_file obf(u8"graph.txt");
	constexpr std::size_t m{1000000};
	constexpr std::size_t n{100000};
	println(obf, m, u8" ", n);
	ufio::ibuf_white_hole_engine rg;
	std::uniform_int_distribution<std::size_t> node_dist(0, n - 1);
	std::uniform_int_distribution<std::size_t> weight_dist(0, 1000000);
	for (std::size_t i{}; i != m; ++i)
	{
		println(obf, node_dist(rg), u8" ", node_dist(rg), u8" ", weight_dist(rg));
	}
}
