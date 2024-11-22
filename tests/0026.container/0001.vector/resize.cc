#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

void print_info(auto rem, ufio::vector<int> const &c)
{
	println(os_c_str(rem), rgvw(c, " "));
}

int main()
{
	ufio::vector<int> c = {1, 2, 3};
	print_info("The vector holds: ", c);

	c.resize(5);
	print_info("After resize up to 5: ", c);

	c.resize(2);
	print_info("After resize down to 2: ", c);

	c.resize(6, 4);
	print_info("After resize up to 6 (initializer = 4): ", c);
}