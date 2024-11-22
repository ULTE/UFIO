#include <ufio.h>
#include <ufio_device.h>
#include <random>

using namespace ufio::io;

int main()
{
	ufio::u8obuf_file obf(u8"directed_graph.txt");
	constexpr std::size_t m{600000};
	constexpr std::size_t n{50000};
	println(obf, m, u8" ", n);
	ufio::ibuf_white_hole_engine rg;
	std::uniform_int_distribution<std::size_t> node_dist(0, n - 1);
	for (std::size_t i{}; i != m; ++i)
	{
		println(obf, node_dist(rg), " ", node_dist(rg));
	}
}
