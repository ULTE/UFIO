#include <string_view>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::string_view str;
	ufio::ibuffer_view ibv(str);
	std::size_t a;
	if (scan<true>(ibv, a))
	{
		println("not eof:", a);
	}
	else
	{
		print("EOF\n");
	}
}
