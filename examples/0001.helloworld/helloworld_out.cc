#include <ufio.h>

using namespace ufio::io;

int main()
{
	print(ufio::out(), "Hello World\n");
}
/*
This outputs to file descriptor 1 on non-windows systems. STDOUT_HANDLE on windows or Wine or ReactOS.
*/