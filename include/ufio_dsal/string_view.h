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
#include <algorithm>
#include "../ufio_core.h"
#include "impl/common.h"
#include "impl/string_view.h"
#include "impl/cstring_view.h"

namespace ufio
{

using ::ufio::containers::null_terminated;
using ::ufio::containers::null_terminated_t;

using string_view = ::ufio::containers::basic_string_view<char>;
using wstring_view = ::ufio::containers::basic_string_view<wchar_t>;
using u8string_view = ::ufio::containers::basic_string_view<char8_t>;
using u16string_view = ::ufio::containers::basic_string_view<char16_t>;
using u32string_view = ::ufio::containers::basic_string_view<char32_t>;

using cstring_view = ::ufio::containers::basic_cstring_view<char>;
using wcstring_view = ::ufio::containers::basic_cstring_view<wchar_t>;
using u8cstring_view = ::ufio::containers::basic_cstring_view<char8_t>;
using u16cstring_view = ::ufio::containers::basic_cstring_view<char16_t>;
using u32cstring_view = ::ufio::containers::basic_cstring_view<char32_t>;

namespace tlc
{
using string_view = ::ufio::containers::basic_string_view<char>;
using wstring_view = ::ufio::containers::basic_string_view<wchar_t>;
using u8string_view = ::ufio::containers::basic_string_view<char8_t>;
using u16string_view = ::ufio::containers::basic_string_view<char16_t>;
using u32string_view = ::ufio::containers::basic_string_view<char32_t>;

using cstring_view = ::ufio::containers::basic_cstring_view<char>;
using wcstring_view = ::ufio::containers::basic_cstring_view<wchar_t>;
using u8cstring_view = ::ufio::containers::basic_cstring_view<char8_t>;
using u16cstring_view = ::ufio::containers::basic_cstring_view<char16_t>;
using u32cstring_view = ::ufio::containers::basic_cstring_view<char32_t>;
} // namespace tlc

} // namespace ufio

#include "impl/misc/pop_macros.h"
#include "impl/misc/pop_warnings.h"
