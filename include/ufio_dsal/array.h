#pragma once

#if !defined(__cplusplus)
#error "You must be using a C++ compiler"
#endif

#if !defined(__cplusplus)
#error "You must be using a C++ compiler"
#endif

#include "impl/misc/push_macros.h"
#include "impl/misc/push_warnings.h"

#include "../ufio_core.h"
#include "impl/array.h"

namespace ufio
{

template <typename T, ::std::size_t N>
using array = ::ufio::containers::array<T, N>;

namespace tlc
{
template <typename T, ::std::size_t N>
using array = ::ufio::containers::array<T, N>;

using ::ufio::containers::to_array;
} // namespace tlc

using ::ufio::containers::to_array;

} // namespace ufio

#include "impl/misc/pop_macros.h"
#include "impl/misc/pop_warnings.h"
