#include <ufio.h>

using namespace ufio::io;

int main()
{
	println(ufio::native_local_timezone{}());
}