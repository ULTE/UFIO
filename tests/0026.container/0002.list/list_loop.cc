#include <ufio_dsal/list.h>
#include <ufio.h>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	::ufio::list<::std::size_t> lst;
	for(::std::size_t i{};i!=100;++i)
	{
		lst.push_back(i);
	}
	for(auto const & e : lst)
	{
		println(e);
	}
}