#include <ufio.h>

// Basic functions like print and scan are in namespace ufio::io
// The namespace is introduced to avoid conflict with std::print
// It's encouraged to directly be 'using'
using namespace ufio::io;

int main()
{
	print("Hello World\n");
}
/*
This outputs to C's stdout FILE*
*/