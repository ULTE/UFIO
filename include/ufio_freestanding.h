#pragma once

// ufio_freestanding.h is usable when the underlining system implements dynamic memory allocations and exceptions
#if !defined(__cplusplus)
#error "You are not using a C++ compiler"
#endif

#if !defined(__cpp_concepts)
#error "ufio requires at least C++20 standard compiler."
#else

#include "ufio_core.h"

#include "ufio_dsal/impl/misc/push_warnings.h"

#include "ufio_freestanding_impl/exception.h"
// #include"ufio_freestanding_impl/posix_error.h"
// compile floating point is slow since it requires algorithms like ryu
#ifndef UFIO_DISABLE_FLOATING_POINT
#include "ufio_unit/floating/impl.h"
#endif
#include "ufio_freestanding_impl/io_buffer/impl.h"
#include "ufio_freestanding_impl/io_deco_filter/impl.h"
#include "ufio_freestanding_impl/decorators/impl.h"
#include "ufio_freestanding_impl/auto_indent.h"
#include "ufio_freestanding_impl/serializations/impl.h"
#include "ufio_freestanding_impl/space_reserve.h"
#include "ufio_freestanding_impl/width.h"
#if 0
#include "ufio_freestanding_impl/scanners/impl.h"
#endif
#include "ufio_freestanding_impl/cond.h"

#if defined(_GLIBCXX_BITSET)
#include "ufio_unit/bitset.h"
#endif

#include "ufio_dsal/impl/misc/pop_warnings.h"

#endif
