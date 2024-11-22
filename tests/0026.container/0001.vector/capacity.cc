#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	int sz = 100;
	ufio::vector<int> v;

	auto cap = v.capacity();
	println("Initial size: ", v.size(), ", capacity: ", cap);

	print("\nDemonstrate the capacity's growth policy."
		  "\nSize:  Capacity:  Ratio:\n");
	while (sz-- > 0)
	{
		v.push_back(sz);
		if (cap != v.capacity())
		{
			println(left(v.size(), 7), left(v.capacity(), 11), left(v.capacity() / static_cast<float>(cap), 10));
			cap = v.capacity();
		}
	}

	println("\nFinal size: ", v.size(), ", capacity: ", v.capacity());
}