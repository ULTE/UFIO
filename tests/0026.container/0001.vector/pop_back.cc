#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

template <typename T>
void print_info(T const &xs)
{
	print("[ ", rgvw(xs, " "), " ]\n");
}

int main()
{
	ufio::vector<int> numbers;

	print_info(numbers);

	numbers.push_back(5);
	numbers.push_back(3);
	numbers.push_back(4);

	print_info(numbers);

	numbers.pop_back();

	print_info(numbers);
}