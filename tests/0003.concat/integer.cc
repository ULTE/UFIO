#include <string>
#include <ufio.h>
#include <climits>

using namespace ufio::io;

int main()
{
	print(ufio::concat(stdout), "\n",
		  ufio::concatln(stdout),
		  ufio::concatln(nullptr),
		  ufio::concatln(true),
		  ufio::concatln(ufio::mnp::boolalpha(true)),
		  ufio::concatln(0),
		  ufio::concatln(1000),
		  ufio::concatln(-1000),
		  ufio::concatln(-1000LL),
		  ufio::concatln(SIZE_MAX),
		  ufio::concatln(PTRDIFF_MAX),
		  ufio::concatln(PTRDIFF_MIN),
		  ufio::concatln(UINTMAX_MAX),
		  ufio::concatln(INTMAX_MIN),
		  ufio::concatln(ufio::mnp::base<36>(INTMAX_MIN)),
		  ufio::concatln(ufio::mnp::base<36>(INTMAX_MAX)),
		  ufio::concatln(ufio::mnp::base<36, true, true>(INTMAX_MAX)),
		  ufio::concatln(ufio::mnp::base<36, true, true>(INTMAX_MAX / 100)),
		  ufio::concatln(ufio::mnp::base<36, true, true>(INTMAX_MIN / 100)));
}