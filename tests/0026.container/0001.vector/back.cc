#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	ufio::vector<char> letters{'a', 'b', 'c', 'd', 'e', 'f'};

	if (!letters.empty())
	{
		print("The first character is '", chvw(letters.back()), "'.\n");
	}
}