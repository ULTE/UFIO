#include <cassert>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;


int main()
{
	ufio::vector<int> const
		a{1, 2, 3},
		b{1, 2, 3},
		c{7, 8, 9, 10};

	assert(""
		   "Compare equal containers:" &&
		   (a != b) == false &&
		   (a == b) == true &&
		   (a < b) == false &&
		   (a <= b) == true &&
		   (a > b) == false &&
		   (a >= b) == true &&
		   (a <=> b) != std::weak_ordering::less &&
		   (a <=> b) != std::weak_ordering::greater &&
		   (a <=> b) == std::weak_ordering::equivalent &&
		   (a <=> b) >= 0 &&
		   (a <=> b) <= 0 &&
		   (a <=> b) == 0 &&

		   "Compare non equal containers:" &&
		   (a != c) == true &&
		   (a == c) == false &&
		   (a < c) == true &&
		   (a <= c) == true &&
		   (a > c) == false &&
		   (a >= c) == false &&
		   (a <=> c) == std::weak_ordering::less &&
		   (a <=> c) != std::weak_ordering::equivalent &&
		   (a <=> c) != std::weak_ordering::greater &&
		   (a <=> c) < 0 &&
		   (a <=> c) != 0 &&
		   (a <=> c) <= 0 &&
		   "");
}
