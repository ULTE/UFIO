#pragma once

#if !defined(__cplusplus)
#error "You must be using a C++ compiler"
#endif

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
#if __cpp_lib_three_way_comparison >= 201907L
#include <compare>
#endif
#include "../ufio_core.h"
#include "impl/common.h"
#include "impl/span.h"

namespace ufio
{

using ::ufio::containers::span;

namespace tlc
{
using ::ufio::containers::span;
} // namespace tlc

} // namespace ufio

#include "impl/misc/pop_macros.h"
#include "impl/misc/pop_warnings.h"
