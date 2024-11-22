#include <complex>
#include <ufio.h>

using namespace ufio::io;

int main()
{
	std::complex<double> c(3.46e2, 32424.436e-40);
	println(c, "\n", ufio::mnp::hexfloat(c));
}