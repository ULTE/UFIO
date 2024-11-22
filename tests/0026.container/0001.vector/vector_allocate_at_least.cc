#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	ufio::vector<::std::size_t> vec;
	println("Before vec.push_back(50): vec.size()=",vec.size()," vec.capacity()=",vec.capacity());
	vec.push_back(50);
	vec.push_back(50);
	println("After vec.push_back(50): vec.size()=",vec.size()," vec.capacity()=",vec.capacity());
}