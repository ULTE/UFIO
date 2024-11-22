#include <ufio_dsal/deque.h>

auto test(::ufio::deque<::std::size_t>::iterator a, ::ufio::deque<::std::size_t>::iterator b)
{
	return a - b;
}