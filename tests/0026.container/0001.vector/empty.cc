#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	ufio::vector<int> numbers;
	println("Initially, numbers.empty(): ", boolalpha(numbers.empty()));

	numbers.push_back(42);
	println("After adding elements, numbers.empty(): ", boolalpha(numbers.empty()));
}