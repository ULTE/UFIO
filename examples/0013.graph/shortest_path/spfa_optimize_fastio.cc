#include <ufio.h>
#include <ufio_device.h>
#include <ufio_dsal/queue.h>
#include <ufio_dsal/vector.h>
#include <ufio_driver/timer.h>

struct node
{
	std::size_t to, weight;
};

using namespace ufio::io;

int main()
{
	::ufio::timer timer(u8"spfa_optimize_fastio");
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
		graph[a].push_back({b, w});
	}
	::ufio::vector<std::size_t> relax(n, SIZE_MAX);
	::ufio::vector<char8_t> occupied(n);
	::ufio::queue<std::size_t> queue;
	occupied.front() = true;
	for (queue.push(relax.front() = 0); !queue.is_empty(); queue.pop())
	{
		auto front{queue.front()};
		auto minimum_weight{relax[front]};
		for (auto e : graph[front])
		{
			if (minimum_weight + e.weight < relax[e.to])
			{
				relax[e.to] = minimum_weight + e.weight;
				if (!occupied[e.to])
				{
					occupied[e.to] = true;
					queue.push(e.to);
				}
			}
		}
		occupied[front] = false;
	}
	ufio::obuf_file obf("spfa.txt");
	if (relax.back() == SIZE_MAX)
	{
		print(obf, "no answer\n");
	}
	else
	{
		println(obf, relax.back());
	}
}