#include <ufio.h>

using namespace ufio::io;

ufio::out_buf_type_lockable globalstdout{ufio::out()};

int main()
{
	print(globalstdout, "Hello World\n");
}
/*
This creates a global object that can avoid CRT. but being thread-safe and full buffer.
*/