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
#include "../ufio_core.h"
#include "impl/freestanding.h"
#include "impl/common.h"
#include "impl/string_view.h"
#include "impl/cstring_view.h"
#include "impl/string.h"

#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))

namespace ufio
{

using string = ::ufio::containers::basic_string<char, ::ufio::native_global_allocator>;
using wstring = ::ufio::containers::basic_string<wchar_t, ::ufio::native_global_allocator>;
using u8string = ::ufio::containers::basic_string<char8_t, ::ufio::native_global_allocator>;
using u16string = ::ufio::containers::basic_string<char16_t, ::ufio::native_global_allocator>;
using u32string = ::ufio::containers::basic_string<char32_t, ::ufio::native_global_allocator>;

namespace tlc
{

using string = ::ufio::containers::basic_string<char, ::ufio::native_thread_local_allocator>;
using wstring = ::ufio::containers::basic_string<wchar_t, ::ufio::native_thread_local_allocator>;
using u8string = ::ufio::containers::basic_string<char8_t, ::ufio::native_thread_local_allocator>;
using u16string = ::ufio::containers::basic_string<char16_t, ::ufio::native_thread_local_allocator>;
using u32string = ::ufio::containers::basic_string<char32_t, ::ufio::native_thread_local_allocator>;

} // namespace tlc

template <typename... Args>
constexpr inline ::ufio::string concat_ufio(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<false, char, ::ufio::string>(::ufio::io_print_forward<char>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concat ::ufio::string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::wstring wconcat_ufio(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<wchar_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<false, wchar_t, ::ufio::wstring>(::ufio::io_print_forward<wchar_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concat ::ufio::wstring");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::u8string u8concat_ufio(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char8_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<false, char8_t, ::ufio::u8string>(::ufio::io_print_forward<char8_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concat ::ufio::FFFstring");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::u16string u16concat_ufio(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char16_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<false, char16_t, ::ufio::u16string>(::ufio::io_print_forward<char16_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concat ::ufio::u16string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::u32string u32concat_ufio(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char32_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<false, char32_t, ::ufio::u32string>(::ufio::io_print_forward<char32_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concat ::ufio::u32string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::string concatln_ufio(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<true, char, ::ufio::string>(::ufio::io_print_forward<char>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concatln ::ufio::string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::wstring wconcatln_ufio(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<wchar_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<true, wchar_t, ::ufio::wstring>(::ufio::io_print_forward<wchar_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concatln ::ufio::wstring");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::u8string u8concatln_ufio(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char8_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<true, char8_t, ::ufio::u8string>(::ufio::io_print_forward<char8_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concatln ::ufio::u8string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::u16string u16concatln_ufio(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char16_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<true, char16_t, ::ufio::u16string>(::ufio::io_print_forward<char16_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concatln ::ufio::u16string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::u32string u32concatln_ufio(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char32_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<true, char32_t, ::ufio::u32string>(::ufio::io_print_forward<char32_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concatln ::ufio::u32string");
		return {};
	}
}

namespace tlc
{

template <typename... Args>
constexpr inline ::ufio::tlc::string concat_ufio_tlc(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<false, char, ::ufio::tlc::string>(::ufio::io_print_forward<char>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concat ::ufio::tlc::string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::tlc::wstring wconcat_ufio_tlc(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<wchar_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<false, wchar_t, ::ufio::tlc::wstring>(::ufio::io_print_forward<wchar_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concat ::ufio::tlc::wstring");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::tlc::u8string u8concat_ufio_tlc(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char8_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<false, char8_t, ::ufio::tlc::u8string>(::ufio::io_print_forward<char8_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concat ::ufio::tlc::u8string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::tlc::u16string u16concat_ufio_tlc(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char16_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<false, char16_t, ::ufio::tlc::u16string>(::ufio::io_print_forward<char16_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concat ::ufio::tlc::u16string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::tlc::u32string u32concat_ufio_tlc(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char32_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<false, char32_t, ::ufio::tlc::u32string>(::ufio::io_print_forward<char32_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concat ::ufio::tlc::u32string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::tlc::string concatln_ufio_tlc(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<true, char, ::ufio::tlc::string>(::ufio::io_print_forward<char>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concatln ::ufio::tlc::string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::tlc::wstring wconcatln_ufio_tlc(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<wchar_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<true, wchar_t, ::ufio::tlc::wstring>(::ufio::io_print_forward<wchar_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concatln ::ufio::tlc::wstring");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::tlc::u8string u8concatln_ufio_tlc(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char8_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<true, char8_t, ::ufio::tlc::u8string>(::ufio::io_print_forward<char8_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concatln ::ufio::tlc::u8string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::tlc::u16string u16concatln_ufio_tlc(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char16_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<true, char16_t, ::ufio::tlc::u16string>(::ufio::io_print_forward<char16_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concatln ::ufio::tlc::u16string");
		return {};
	}
}

template <typename... Args>
constexpr inline ::ufio::tlc::u32string u32concatln_ufio_tlc(Args &&...args)
{
	constexpr bool type_error{::ufio::operations::defines::print_freestanding_okay<::ufio::details::dummy_buffer_output_stream<char32_t>, Args...>};
	if constexpr (type_error)
	{
		return ::ufio::basic_general_concat<true, char32_t, ::ufio::tlc::u32string>(::ufio::io_print_forward<char32_t>(::ufio::io_print_alias(args))...);
	}
	else
	{
		static_assert(type_error, "some types are not printable, so we cannot concatln ::ufio::tlc::u32string");
		return {};
	}
}

} // namespace tlc

} // namespace ufio

#endif

#include "impl/misc/pop_macros.h"
#include "impl/misc/pop_warnings.h"
