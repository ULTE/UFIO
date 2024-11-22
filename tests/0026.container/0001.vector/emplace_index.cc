#include <algorithm>
#include <ranges>
#include <string>
#include <ufio.h>
#include <ufio_dsal/vector.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	::ufio::vector<::std::size_t> vec;
	vec.push_back(4);
	vec.emplace_index(0,6);
	vec.emplace_index(0,8);
	vec.erase_index(0);
	for(auto const & e : vec)
	{
		::ufio::io::println(e);
	}
}
