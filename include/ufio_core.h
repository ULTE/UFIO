#pragma once
// ufio_core.h is required to be usable in freestanding environment with EVEN dynamic memory allocation and
// exceptions are disabled.

#if !defined(__cplusplus)
#error "You are not using a C++ compiler"
#endif

#if !defined(__cpp_concepts)
#error "ufio requires at least C++20 standard compiler."
#else
#include <bit>
#include <limits>
#include <cstdint>

#if __cpp_lib_three_way_comparison >= 201907L
#include <compare>
#endif

#include "ufio_concept.h"

#include "ufio_dsal/impl/misc/push_warnings.h"

#include "ufio_core_impl/empty.h"
#if defined(_MSC_VER) && !defined(__clang__)
#include "ufio_core_impl/intrinsics/msvc/impl.h"
#endif
#include "ufio_core_impl/bitops/impl.h"
#include "ufio_core_impl/freestanding/impl.h"
#include "ufio_core_impl/terminate.h"
#include "ufio_dsal/impl/freestanding.h"
#include "ufio_core_impl/allocation/impl.h"

#include "ufio_core_impl/error.h"
#include "ufio_core_impl/asan_support.h"
// ufio core
#include "ufio_core_impl/utils.h"
#include "ufio_core_impl/intrinsics/impl.h"
#include "ufio_core_impl/intrinsics.h"
#include "ufio_core_impl/parse_code.h"

#include "ufio_core_impl/ebcdic.h"
#include "ufio_core_impl/literals/literal.h"
#include "ufio_core_impl/char_category.h"

#if __cpp_lib_three_way_comparison >= 201907L
#include "ufio_core_impl/compare.h"
#endif

#include "ufio_core_impl/alias.h"
#include "ufio_core_impl/pr_rsv.h"

#include "ufio_core_impl/secure_clear_guard.h"
#include "ufio_core_impl/local_new_array_ptr.h"
#include "ufio_core_impl/dynamic_output_buffer.h"
// Although ::std::ranges is not freestanding, you can use the function by constructing a range_view_t, which relies on
// iterators not ranges
#include "ufio_core_impl/range_view.h"
// #include"ufio_core_impl/manip/impl.h"
#include "ufio_core_impl/mode.h"
#include "ufio_core_impl/perms.h"
#include "ufio_dsal/impl/common.h"
#include "ufio_dsal/impl/span.h"
#include "ufio_core_impl/operations/impl.h"

// This should provide an option macro to disable any generation for table in freestanding environments.
#include "ufio_core_impl/integers/integer.h"

#include "ufio_core_impl/black_hole.h"
#include "ufio_core_impl/buffer_view.h"

#ifdef __cpp_lib_source_location
#include <source_location>
#include "ufio_core_impl/source_location.h"
#endif

#include "ufio_core_impl/simd/impl.h"
#include "ufio_core_impl/simd_find.h"
#include "ufio_core_impl/integers/sto/sto_contiguous.h"

#include "ufio_core_impl/integers/chrono.h"
#include "ufio_core_impl/iso/isos.h"
#include "ufio_core_impl/enums/impl.h"

#ifndef UFIO_DISABLE_CODECVT
#include "ufio_core_impl/codecvt/impl.h"
#endif
#include "ufio_core_impl/io_deco_ref.h"

#include "ufio_core_impl/timestamp_counter.h"
#include "ufio_core_impl/dll_mode.h"
#include "ufio_core_impl/socket/impl.h"

#include "ufio_core_impl/concat/impl.h"
#include "ufio_core_impl/to.h"

#include "ufio_core_impl/http_header.h"
#include "ufio_core_impl/io_lockable.h"

#include "ufio_dsal/impl/misc/pop_warnings.h"

#endif
