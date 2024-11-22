#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	ufio::vector vec{static_cast<::std::uint_least32_t>(1), 6, 10, 20};
	println("Before vec.push_back(50): vec.size()=", vec.size(), " vec.capacity()=", vec.capacity());
	vec.push_back(50);
	vec.push_back(50);
	println("After vec.push_back(50): vec.size()=", vec.size(), " vec.capacity()=", vec.capacity());
}