#include <ufio_dsal/list.h>
#include <ufio_dsal/vector.h>
#include <ufio.h>
#include <random>
#include <algorithm>
using namespace ufio::io;
using namespace ufio::mnp;

int main()
{
	::ufio::vector<::std::size_t> vec;
	constexpr ::std::size_t n{100000};
	vec.reserve(n);
	for (::std::size_t i{}; i != n; ++i)
	{
		vec.push_back_unchecked(i);
	}
	::ufio::ibuf_white_hole_engine eng;
	::std::ranges::shuffle(vec, eng);

	::ufio::list<::std::size_t> lst(::ufio::freestanding::from_range, vec);

	lst.sort();
	for (auto const &e : lst)
	{
		println(e);
	}
}
