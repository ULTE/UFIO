#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

inline void print_container(ufio::vector<int> const &c)
{
	println(rgvw(c, " "));
}

int main()
{
	ufio::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print_container(c);

	c.erase_index(0);
	print_container(c);

	c.erase_index(2, 5);
	print_container(c);

	// Erase all even numbers
	for (::std::size_t i{}; i!=c.size();)
	{
		if (c[i] % 2 == 0)
		{
			c.erase_index(i);
		}
		else
		{
			++i;
		}
	}

	print_container(c);
}