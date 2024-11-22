#include <cassert>
#include <iterator>
#include <algorithm>
#include <list>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	auto container = ufio::vector{1, 2, 3, 4};
	auto pos = std::next(container.begin(), 2);
	assert(*pos == 3);
	auto const rg = std::list{-1, -2, -3};

	container.insert_range(pos, rg);
	assert(std::ranges::equal(container, ufio::vector{1, 2, -1, -2, -3, 3, 4}));
}