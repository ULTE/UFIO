#pragma once
#include "deque.h"
#include "impl/queue.h"

#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))

namespace ufio
{

template <typename T, typename Container = ::ufio::deque<T>>
using queue = ::ufio::containers::queue<Container>;

namespace tlc
{
template <typename T, typename Container = ::ufio::tlc::deque<T>>
using queue = ::ufio::containers::queue<Container>;
}

} // namespace ufio
#endif