#include <ufio.h>

using namespace ufio::io;

int main()
{
	print(ufio::dbg(), "Hello World remote debugger from ufio\n"); // it will use remote debugger if you have one.
}
