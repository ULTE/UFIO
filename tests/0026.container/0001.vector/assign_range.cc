#include <algorithm>
#include <cassert>
#include <list>
#include <ufio.h>
#include <ufio_dsal/vector.h>

int main()
{
	auto const source = std::list{2, 7, 1};
	auto destination = ufio::vector{3, 1, 4};
	destination.assign_range(source);
	assert(std::ranges::equal(source, destination));
}