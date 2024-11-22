#include <algorithm>
#include <numeric>
#include <string>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	ufio::vector<int> nums{1, 2, 4, 8, 16};
	ufio::vector<std::string> fruits{"orange", "apple", "raspberry"};
	ufio::vector<char> empty;

	// Print vector.
	std::for_each(nums.begin(), nums.end(), [](int const n) { print(n, " "); });
	print("\n");

	// Sums all integers in the vector nums (if any), printing only the result.
	println("Sum of nums: ",
			std::accumulate(nums.begin(), nums.end(), 0));

	// Prints the first fruit in the vector fruits, checking if there is any.
	if (!fruits.empty())
	{
		println("First fruit: ", *fruits.begin());
	}

	if (empty.begin() == empty.end())
	{
		print("vector 'empty' is indeed empty.\n");
	}
}