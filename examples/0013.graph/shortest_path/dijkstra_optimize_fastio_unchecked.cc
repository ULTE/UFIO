#include <ufio_dsal/vector.h>
#include <ufio_dsal/priority_queue.h>
#include <ufio.h>
#include <ufio_device.h>
#include <ufio_driver/timer.h>

struct node
{
	std::size_t to, weight;
};

inline constexpr bool operator==(node const &a, node const &b) noexcept
{
	return a.to == b.to;
}

inline constexpr auto operator<=>(node const &a, node const &b) noexcept
{
	return a.to <=> b.to;
}

using namespace ufio::io;

int main()
{
	::ufio::timer timer(u8"dijkstra_optimize_fastio_unchecked");
	ufio::ibuf_file ibf("graph.txt");
	std::size_t m, n;
	scan(ibf, m, n);
	::ufio::vector<::ufio::vector<node>> graph(n);
	std::size_t const average{(m / n + 1) * 13 / 10};
	for (auto &v : graph)
	{
		v.reserve(average);
	}
	for (std::size_t i{}; i != m; ++i)
	{
		std::size_t a, b, w;
		scan(ibf, a, b, w);
		graph.index_unchecked(a).push_back({b, w});
	}
	::ufio::priority_queue<node, ::std::ranges::greater> queue;
	::ufio::vector<std::size_t> relax(n, SIZE_MAX);
	for (queue.push({relax.front() = 0, 0}); !queue.is_empty();)
	{
		auto [minimum_weight, minimum_node]{queue.pop_element_unchecked()};
		if (relax.index_unchecked(minimum_node) < minimum_weight)
		{
			continue;
		}
		for (auto e : graph.index_unchecked(minimum_node))
		{
			if (minimum_weight + e.weight < relax.index_unchecked(e.to))
			{
				queue.push({relax.index_unchecked(e.to) = minimum_weight + e.weight, e.to});
			}
		}
	}
	ufio::obuf_file obf("dijkstra.txt");
	if (relax.back_unchecked() == SIZE_MAX)
	{
		print(obf, "no answer\n");
	}
	else
	{
		println(obf, relax.back_unchecked());
	}
}
