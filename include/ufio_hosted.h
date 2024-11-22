#pragma once
/*
https://en.cppreference.com/w/cpp/freestanding
There are two kinds of implementations defined by the C++ standard:
hosted and freestanding implementations.
For hosted implementations the set of standard library headers required by the C++ standard is much larger than for
freestanding ones.
*/
// ufio_hosted defines what we could use in a hosted environment.

#if !defined(__cplusplus)
#error "You are not using a C++ compiler"
#endif

#if !defined(__cpp_concepts)
#error "ufio requires at least C++20 standard compiler."
#else

#include "ufio_freestanding.h"

#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))

#if __has_include(<stdio.h>)
#if __has_include(<bits/error_constants.h>)
#include <bits/error_constants.h>
#include "ufio_hosted/platforms/errc_default_impl.h"
#elif __has_include(<__errc>) && !defined(__clang__)
#include <__errc>
#include "ufio_hosted/platforms/errc_default_impl.h"
#elif __has_include(<xerrc.h>) && !defined(__BIONIC__)
#include <xerrc.h>
#include "ufio_hosted/platforms/errc_default_impl.h"
#elif __has_include(<system_error>)
#include <system_error>
#include "ufio_hosted/platforms/errc_default_impl.h"
#else
#include "ufio_hosted/platforms/errc_impl.h"
#endif

#include "ufio_dsal/impl/misc/push_warnings.h"

#include "ufio_hosted/posix_error_scatter/impl.h"
#include "ufio_hosted/posix_error.h"
#ifdef __MSDOS__
#undef __STRICT_ANSI__
#endif

#include "ufio_hosted/api_encoding_converter/impl.h"
#include "ufio_hosted/mmap.h"
#include "ufio_hosted/mmap/impl.h"
#include "ufio_hosted/posix_status.h"
#if __has_include(<ctime>)
#include <ctime>
#include "ufio_unit/timespec.h"
#elif __has_include(<time.h>)
#include <time.h>
#include "ufio_unit/timespec.h"
#endif

#if !defined(__AVR__)
#include "ufio_dsal/string_view.h"
#include "ufio_dsal/string.h"

#include "ufio_hosted/platforms/native.h"
#include "ufio_hosted/file_loaders/impl.h"
#include "ufio_hosted/wrapper.h"
#include "ufio_hosted/white_hole/white_hole.h"
#include "ufio_hosted/dbg/impl.h"
#endif
#if __has_include(<ctime>) || __has_include(<time.h>)
#include "ufio_hosted/timeutil/impl.h"
#endif

#include "ufio_hosted/threads/threads.h"

#include "ufio_dsal/impl/common.h"
#include "ufio_dsal/impl/vector.h"

#include "ufio_hosted/filesystem/native.h"
#include "ufio_hosted/dll/dll.h"
#include "ufio_hosted/process/process.h"

#include "ufio_hosted/io_file.h"

#if defined(_MSVC_EXECUTION_CHARACTER_SET)
#if _MSVC_EXECUTION_CHARACTER_SET == 936 || _MSVC_EXECUTION_CHARACTER_SET == 54936
#include "ufio_unit/gb18030.h"
#endif
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
#include "ufio_hosted/platforms/win32_box.h"
#endif

#if defined(_GLIBCXX_STRING) || defined(_LIBCPP_STRING) || defined(_STRING_)
#include "ufio_unit/string.h"
#endif

#if defined(_GLIBCXX_CHRONO) || defined(_LIBCPP_CHRONO) || defined(_CHRONO_)
#include "ufio_unit/chrono.h"
#endif

#if defined(_GLIBCXX_COMPLEX) || defined(_LIBCPP_COMPLEX) || defined(_COMPLEX_)
#include "ufio_unit/complex.h"
#endif

#if defined(_GLIBCXX_FILESYSTEM) || defined(_LIBCPP_FILESYSTEM) || defined(_FILESYSTEM_)
#include "ufio_unit/filesystem.h"
#endif

#if defined(_LIBCPP_BITSET) || defined(_BITSET_)
#include "ufio_unit/bitset.h"
#endif

#if defined(_WIN32) && defined(WINRT_BASE_H)
#if __has_include(<winrt/base.h>)
#include "ufio_driver/cppwinrt_impl/impl.h"
#endif
#endif

#endif

#endif

#include "ufio_dsal/impl/misc/pop_warnings.h"

#endif
