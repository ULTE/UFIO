#pragma once
#include "vector.h"
#include "impl/priority_queue.h"

#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))

namespace ufio
{

template <typename T, typename Cmp = ::std::ranges::less, typename Container = ::ufio::vector<T>>
using priority_queue = ::ufio::containers::priority_queue<Cmp, Container>;

namespace tlc
{
template <typename T, typename Cmp = ::std::ranges::less, typename Container = ::ufio::tlc::vector<T>>
using priority_queue = ::ufio::containers::priority_queue<Cmp, Container>;
}

} // namespace ufio
#endif
