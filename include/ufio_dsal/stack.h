#pragma once
#include "deque.h"
#include "impl/stack.h"

#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))

namespace ufio
{

template <typename T, typename Container = ::ufio::deque<T>>
using stack = ::ufio::containers::stack<Container>;

namespace tlc
{
template <typename T, typename Container = ::ufio::tlc::deque<T>>
using stack = ::ufio::containers::stack<Container>;
}

} // namespace ufio
#endif