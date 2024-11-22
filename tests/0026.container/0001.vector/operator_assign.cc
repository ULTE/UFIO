#include <initializer_list>
#include <iterator>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	ufio::vector<int> x{1, 2, 3}, y, z;
	auto const w = {4, 5, 6, 7};

	print("Initially:\n");
	print("x = {", rgvw(x, ", "), "}\ny = {", rgvw(y, ", "), "}\nz = {", rgvw(z, ", "), "}\n");

	print("Copy assignment copies data from x to y:\n");
	y = x;
	print("x = {", rgvw(x, ", "), "}\ny = {", rgvw(y, ", "), "}\n");

	print("Move assignment moves data from x to z, modifying both x and z:\n");
	z = std::move(x);
	print("x = {", rgvw(x, ", "), "}\nz = {", rgvw(z, ", "), "}\n");

	print("Assignment of initializer_list w to z:\n");
	z = w;
	print("w = {", rgvw(w, ", "), "}\nz = {", rgvw(z, ", "), "}\n");
}
