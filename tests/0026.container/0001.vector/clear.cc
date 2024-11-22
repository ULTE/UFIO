#include <string_view>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

void print_info(std::string_view rem, ufio::vector<int> const &v)
{
	println(rem, "{ ", rgvw(v, " "), " }\nSize=", v.size(), ", Capacity=", v.capacity());
}

int main()
{
	ufio::vector<int> container{1, 2, 3};
	print_info("Before clear: ", container);
	container.clear();
	print_info("After clear: ", container);
}