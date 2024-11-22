#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	ufio::vector<int> nums{1, 3, 5, 7};

	print("nums contains ", nums.size(), " elements.\n");
}