#include <cassert>
#include <algorithm>
#include <list>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	auto head = ufio::vector<int>{1, 2, 3, 4};
	auto const tail = std::list{-5, -6, -7};
	head.append_range(tail);
	assert(std::ranges::equal(head, ufio::vector<int>{1, 2, 3, 4, -5, -6, -7}));
}