#include <cstddef>
#include <span>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

void pointer_func(int const *p, std::size_t size)
{
	print("data = ");
	for (std::size_t i = 0; i < size; ++i)
	{
		print(p[i], " ");
	}
	print("\n");
}

void span_func(std::span<int const> data) // since C++20
{
	print("data = ", rgvw(data, " "), "\n");
}

int main()
{
	ufio::vector<int> container{1, 2, 3, 4};

	// Prefer container.data() over &container[0]
	pointer_func(container.data(), container.size());

	// std::span (C++20) is a safer alternative to separated pointer/size.
	span_func({container.data(), container.size()});
}