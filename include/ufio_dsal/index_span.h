#pragma once

#if !defined(__cplusplus)
#error "You must be using a C++ compiler"
#endif

#if !defined(__cplusplus)
#error "You must be using a C++ compiler"
#endif

#include "impl/misc/push_macros.h"
#include "impl/misc/push_warnings.h"

#include "span.h"
#include "impl/index_span.h"

namespace ufio
{

using ::ufio::containers::index_unchecked;
using ::ufio::containers::index_span;

namespace tlc
{
using ::ufio::containers::index_span;
} // namespace tlc

} // namespace ufio

#include "impl/misc/pop_macros.h"
#include "impl/misc/pop_warnings.h"
