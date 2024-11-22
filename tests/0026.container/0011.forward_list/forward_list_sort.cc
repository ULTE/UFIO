#include <ufio_dsal/forward_list.h>
#include <ufio_dsal/vector.h>
#include <ufio.h>
#include <random>
#include <algorithm>

int main()
{
	::ufio::vector<::std::size_t> vec;
	constexpr ::std::size_t n{10};
	vec.reserve(n);
	for (::std::size_t i{}; i != n; ++i)
	{
		vec.push_back_unchecked(i);
	}
	::ufio::ibuf_white_hole_engine eng;
	::std::ranges::shuffle(vec, eng);

#if 0
//UNFINISHED
	::ufio::forward_list<::std::size_t> flst(::ufio::freestanding::from_range, vec);
#if 0
	flst.sort();
#endif
	::ufio::forward_list<::std::size_t> flst2{1, 3, 5, 7, 9};
	::ufio::io::println("flst:\n", ::ufio::mnp::rgvw(flst, "\n"), "\nflst2:\n", ::ufio::mnp::rgvw(flst2, "\n"));
	flst2.reverse();
	::ufio::io::println("flst2:\n", ::ufio::mnp::rgvw(flst2, "\n"));
#endif
}
