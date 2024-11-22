#include <ufio_dsal/list.h>
#include <ufio_dsal/vector.h>
#include <ufio.h>
#include <ufio_driver/timer.h>
#include <random>
#include <algorithm>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	::ufio::vector<::std::size_t> vec;
	constexpr
		::std::size_t n{1000000};
	vec.reserve(n);
	for(::std::size_t i{};i!=n;++i)
	{
		vec.push_back_unchecked(i);
	}
	::ufio::ibuf_white_hole_engine eng;
	::std::ranges::shuffle(vec,eng);

	::ufio::list<::std::size_t> lst(vec.begin(),vec.end());
	{
		::ufio::timer tm(u8"::ufio::list<T>::sort()");
		lst.sort();
	}
	perrln("issorted?",::ufio::mnp::boolalpha(::std::ranges::is_sorted(lst)));
}