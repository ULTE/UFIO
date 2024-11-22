#include <string>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::string str = ufio::concat_std("The "
										  "fart is ",
										  3,
										  " years old.\n"
										  "Leeroy!!!!",
										  "Jenkins!!!\n");
	print(str);
}
