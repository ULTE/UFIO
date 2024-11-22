#pragma once

#if !defined(__cplusplus)
#error "You must be using a C++ compiler"
#endif

#include "impl/misc/push_macros.h"
#include "impl/misc/push_warnings.h"

#include <version>
#include <type_traits>
#include <concepts>
#include <limits>
#include <cstdint>
#include <cstddef>
#include <new>
#include <initializer_list>
#include <bit>
#include <compare>
#include <algorithm>
#include "../ufio_core_impl/freestanding/impl.h"
#include "../ufio_core_impl/terminate.h"
#include "../ufio_core_impl/intrinsics/msvc/impl.h"
#include "../ufio_core_impl/allocation/impl.h"

#include "impl/freestanding.h"
#include "impl/common.h"
#include "impl/deque.h"

#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))

namespace ufio
{

template <typename T, typename Alloc = ::ufio::native_global_allocator>
using deque = ::ufio::containers::deque<T, Alloc>;

namespace containers
{

#if 0
template <::std::input_iterator InputIt>
deque(InputIt, InputIt) -> deque<typename ::std::iterator_traits<InputIt>::value_type, ::ufio::native_global_allocator>;

#ifdef __cpp_lib_containers_ranges
template <::std::ranges::input_range R>
deque(::std::from_range_t, R &&) -> deque<::std::ranges::range_value_t<R>, ::ufio::native_global_allocator>;
#endif
#endif
} // namespace containers

namespace tlc
{
template <typename T, typename Alloc = ::ufio::native_thread_local_allocator>
using deque = ::ufio::containers::deque<T, Alloc>;
}

} // namespace ufio

#endif

#include "impl/misc/pop_macros.h"
#include "impl/misc/pop_warnings.h"
