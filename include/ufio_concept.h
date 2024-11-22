#pragma once
// ufio_concept.h allows you define your device and type without compilation time penalty
#if !defined(__cplusplus)
#error "You must be using a C++ compiler"
#endif
#if !defined(__cpp_concepts)
#error "ufio requires at least a C++20 standard compiler."
#else

#include <version>
#include <cstddef>
#include <type_traits>
#include <concepts>
#include <cstdint>

#include "ufio_dsal/impl/misc/push_macros.h"
#include "ufio_dsal/impl/misc/push_warnings.h"

#include "ufio_core_impl/freestanding/addressof.h"
#include "ufio_core_impl/concepts/impl.h"

#include "ufio_dsal/impl/misc/pop_macros.h"
#include "ufio_dsal/impl/misc/pop_warnings.h"

#endif
