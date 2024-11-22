#include <string>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	ufio::vector<char> characters;

	// lack functionality in mnp::rgvw
	auto print_vector = [&]() {
		for (char c : characters)
		{
			print(chvw(c), " ");
		}
		print("\n");
	};

	characters.assign(5, 'a');
	print_vector();

	std::string const extra(6, 'b');
	characters.assign(extra.begin(), extra.end());
	print_vector();

	characters.assign({'C', '+', '+', '1', '1'});
	print_vector();
}