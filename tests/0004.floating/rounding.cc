#include <ufio.h>
#include <charconv>
using namespace ufio::io;

int main()
{
	println(4.8371439708550857e+306);
	char buffer[30];
	auto [p, ec] = std::to_chars(buffer, buffer + 30, 4.8371439708550857e+306);
	ufio::operations::write_all(ufio::c_stdout(), buffer, p);
}