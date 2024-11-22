#include <ufio_dsal/vector.h>

consteval auto test()
{
	return ufio::vector{2, 3, 4}[2];
}

int main()
{
	test();
}