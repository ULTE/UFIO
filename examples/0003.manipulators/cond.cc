#include <ufio.h>

using namespace ufio::io;

int main()
{
	println(ufio::mnp::cond(true, "hello", "world"), "\n", ufio::mnp::cond(false, "hello", "world"));
}
