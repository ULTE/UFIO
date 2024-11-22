#include <string>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	ufio::vector<std::string> letters;

	letters.push_back("abc");
	std::string s{"def"};
	letters.push_back(std::move(s));

	print("std::vector letters holds: ");
	for (auto &&e : letters)
	{
		print("\"", e, "\" ");
	}

	print("\nMoved-from string s holds: \"", s, "\"\n");
}