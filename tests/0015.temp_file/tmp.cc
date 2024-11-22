#include <ufio.h>

using namespace ufio::io;

int main()
{
	ufio::native_file file(ufio::io_temp);
	for (std::size_t i{}; i != 1000; ++i)
	{
		print(file, "Hello World\n");
	}
	rewind(file);
	println("transmitted:", transmit(ufio::c_stdout(), file));
}
