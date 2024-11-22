#pragma once

#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))
#include "defined_types.h"
#endif

namespace ufio
{

inline namespace io
{

template <typename T, typename... Args>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void print(T &&t, Args &&...args)
{
	constexpr bool device_and_type_ok{::ufio::operations::defines::print_freestanding_okay<T, Args...>};
	if constexpr (device_and_type_ok)
	{
		using char_type = typename decltype(::ufio::operations::output_stream_ref(t))::output_char_type;
		::ufio::operations::decay::print_freestanding_decay<false>(
			::ufio::operations::output_stream_ref(t),
			::ufio::io_print_forward<char_type>(::ufio::io_print_alias(args))...);
	}
	else
	{
#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES)) &&                                     \
	__has_include(<stdio.h>)
		constexpr bool type_ok{::ufio::operations::defines::print_freestanding_params_okay<char, Args...>};
		if constexpr (type_ok)
		{
			::ufio::details::print_after_io_print_forward<false>(
				::ufio::io_print_forward<char>(::ufio::io_print_alias(t)),
				::ufio::io_print_forward<char>(::ufio::io_print_alias(args))...);
		}
		else
		{
			// clang-format off
static_assert(type_ok, "some types are not printable for print on default C's stdout");
			// clang-format on
		}
#else
		constexpr bool device_ok{::ufio::operations::defines::has_output_or_io_stream_ref_define<T>};
		// clang-format off
static_assert(device_ok, "freestanding environment must provide IO device for print");
static_assert(device_and_type_ok, "some types are not printable for print");
		// clang-format on
#endif
	}
}

template <typename T, typename... Args>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void println(T &&t, Args &&...args)
{
	constexpr bool device_and_type_ok{::ufio::operations::defines::print_freestanding_okay<T, Args...>};
	if constexpr (device_and_type_ok)
	{
		using char_type = typename decltype(::ufio::operations::output_stream_ref(t))::output_char_type;
		::ufio::operations::decay::print_freestanding_decay<true>(
			::ufio::operations::output_stream_ref(t),
			::ufio::io_print_forward<char_type>(::ufio::io_print_alias(args))...);
	}
	else
	{
#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES)) &&                                     \
	__has_include(<stdio.h>)
		constexpr bool type_ok{::ufio::operations::defines::print_freestanding_params_okay<char, Args...>};
		if constexpr (type_ok)
		{
			::ufio::details::print_after_io_print_forward<true>(
				::ufio::io_print_forward<char>(::ufio::io_print_alias(t)),
				::ufio::io_print_forward<char>(::ufio::io_print_alias(args))...);
		}
		else
		{
			static_assert(type_ok, "some types are not printable for print on default C's stdout");
		}
#else
		constexpr bool device_ok{::ufio::operations::defines::has_output_or_io_stream_ref_define<T>};
		// clang-format off
static_assert(device_ok, "freestanding environment must provide IO device for println");
static_assert(device_and_type_ok, "some types are not printable for println");
		// clang-format on
#endif
	}
}

template <typename T, typename... Args>
inline constexpr void perr(T &&t, Args &&...args)
{
	constexpr bool device_and_type_ok{::ufio::operations::defines::print_freestanding_okay<T, Args...>};
	if constexpr (device_and_type_ok)
	{
		using char_type = typename decltype(::ufio::operations::output_stream_ref(t))::output_char_type;
		::ufio::operations::decay::print_freestanding_decay_cold<false>(
			::ufio::operations::output_stream_ref(t),
			::ufio::io_print_forward<char_type>(::ufio::io_print_alias(args))...);
	}
	else
	{
#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && !defined(_LIBCPP_FREESTANDING) && \
	  !defined(__AVR__)) ||                                                                                            \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))
		constexpr bool type_ok{::ufio::operations::defines::print_freestanding_params_okay<char, Args...>};
		if constexpr (type_ok)
		{
			::ufio::details::perr_after_io_print_forward<false>(
				ufio::io_print_forward<char>(ufio::io_print_alias(t)),
				ufio::io_print_forward<char>(ufio::io_print_alias(args))...);
		}
		else
		{
			// clang-format off
static_assert(type_ok, "some types are not printable for perr on native err");
			// clang-format on
		}
#else
		constexpr bool device_ok{::ufio::operations::defines::has_output_or_io_stream_ref_define<T>};
		// clang-format off
static_assert(device_ok, "freestanding environment must provide IO device for perr");
static_assert(device_and_type_ok, "some types are not printable for perr");
		// clang-format on
#endif
	}
}

template <typename T, typename... Args>
inline constexpr void perrln(T &&t, Args &&...args)
{
	constexpr bool device_and_type_ok{::ufio::operations::defines::print_freestanding_okay<T, Args...>};
	if constexpr (device_and_type_ok)
	{
		using char_type = typename decltype(::ufio::operations::output_stream_ref(t))::output_char_type;
		::ufio::operations::decay::print_freestanding_decay_cold<true>(
			::ufio::operations::output_stream_ref(t),
			::ufio::io_print_forward<char_type>(::ufio::io_print_alias(args))...);
	}
	else
	{
#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && !defined(_LIBCPP_FREESTANDING) && \
	  !defined(__AVR__)) ||                                                                                            \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))
		constexpr bool type_ok{::ufio::operations::defines::print_freestanding_params_okay<char, Args...>};
		if constexpr (type_ok)
		{
			::ufio::details::perr_after_io_print_forward<true>(
				ufio::io_print_forward<char>(ufio::io_print_alias(t)),
				ufio::io_print_forward<char>(ufio::io_print_alias(args))...);
		}
		else
		{
			// clang-format off
static_assert(type_ok, "some types are not printable for perrln on native err");
			// clang-format on
		}
#else
		constexpr bool device_ok{::ufio::operations::defines::has_output_or_io_stream_ref_define<T>};
		// clang-format off
static_assert(device_ok, "freestanding environment must provide IO device for perrln");
static_assert(device_and_type_ok, "some types are not printable for perrln");
		// clang-format on
#endif
	}
}

template <typename... Args>
[[noreturn]] inline constexpr void panic(Args &&...args) noexcept
{
	if constexpr (sizeof...(Args) != 0)
	{
#ifdef __cpp_exceptions
		try
		{
#endif
			::ufio::io::perr(::std::forward<Args>(args)...);
#ifdef __cpp_exceptions
		}
		catch (...)
		{
		}
#endif
	}
	::ufio::fast_terminate();
}

template <typename... Args>
	requires(sizeof...(Args) != 0)
[[noreturn]] inline constexpr void panicln(Args &&...args) noexcept
{
#ifdef __cpp_exceptions
	try
	{
#endif
		::ufio::io::perrln(::std::forward<Args>(args)...);
#ifdef __cpp_exceptions
	}
	catch (...)
	{
	}
#endif
	::ufio::fast_terminate();
}

// Allow debug print
#ifndef UFIO_DISABLE_DEBUG_PRINT
// With debugging. We output to POSIX fd or Win32 Handle directly instead of C's stdout.
template <typename T, typename... Args>
inline constexpr void debug_print(T &&t, Args &&...args)
{
	constexpr bool device_and_type_ok{::ufio::operations::defines::print_freestanding_okay<T, Args...>};
	if constexpr (device_and_type_ok)
	{
		using char_type = typename decltype(::ufio::operations::output_stream_ref(t))::output_char_type;
		::ufio::operations::decay::print_freestanding_decay<false>(
			::ufio::operations::output_stream_ref(t),
			ufio::io_print_forward<char_type>(ufio::io_print_alias(args))...);
	}
	else
	{
#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))
		constexpr bool type_ok{::ufio::operations::defines::print_freestanding_params_okay<char, Args...>};
		if constexpr (type_ok)
		{
			ufio::details::debug_print_after_io_print_forward<false>(
				ufio::io_print_forward<char>(ufio::io_print_alias(t)),
				ufio::io_print_forward<char>(ufio::io_print_alias(args))...);
		}
		else
		{
			// clang-format off
static_assert(type_ok, "some types are not printable for debug_print on native out");
			// clang-format on
		}
#else
		constexpr bool device_ok{::ufio::operations::defines::has_output_or_io_stream_ref_define<T>};
		// clang-format off
static_assert(device_ok, "freestanding environment must provide IO device for debug_print");
static_assert(device_and_type_ok, "some types are not printable for debug_print on native out");
		// clang-format on
#endif
	}
}

template <typename T, typename... Args>
inline constexpr void debug_println(T &&t, Args &&...args)
{
	constexpr bool device_and_type_ok{::ufio::operations::defines::print_freestanding_okay<T, Args...>};
	if constexpr (device_and_type_ok)
	{
		using char_type = typename decltype(::ufio::operations::output_stream_ref(t))::output_char_type;
		::ufio::operations::decay::print_freestanding_decay<true>(
			::ufio::operations::output_stream_ref(t),
			ufio::io_print_forward<char_type>(ufio::io_print_alias(args))...);
	}
	else
	{
#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES))
		constexpr bool type_ok{::ufio::operations::defines::print_freestanding_params_okay<char, Args...>};
		if constexpr (type_ok)
		{
			ufio::details::debug_print_after_io_print_forward<true>(
				ufio::io_print_forward<char>(ufio::io_print_alias(t)),
				ufio::io_print_forward<char>(ufio::io_print_alias(args))...);
		}
		else
		{
			// clang-format off
static_assert(type_ok, "some types are not printable for debug_println on native out");
			// clang-format on
		}
#else
		constexpr bool device_ok{::ufio::operations::defines::has_output_or_io_stream_ref_define<T>};
		// clang-format off
static_assert(device_ok, "freestanding environment must provide IO device for debug_println");
static_assert(device_and_type_ok, "some types are not printable for debug_println on native out");
		// clang-format on
#endif
	}
}

template <typename... Args>
	requires(sizeof...(Args) != 0)
inline constexpr void debug_perr(Args &&...args)
{
	::ufio::io::perr(::std::forward<Args>(args)...);
}

template <typename... Args>
	requires(sizeof...(Args) != 0)
inline constexpr void debug_perrln(Args &&...args)
{
	::ufio::io::perrln(::std::forward<Args>(args)...);
}
#endif

template <bool report = false, typename input, typename... Args>
inline constexpr ::std::conditional_t<report, bool, void> scan(input &&in, Args &&...args)
{
	constexpr bool device_error{::ufio::operations::defines::has_input_or_io_stream_ref_define<input>};
	if constexpr (device_error)
	{
		using char_type = typename decltype(::ufio::operations::input_stream_ref(in))::input_char_type;
		if constexpr (report)
		{
			return ::ufio::operations::decay::scan_freestanding_decay(
				::ufio::operations::input_stream_ref(in),
				::ufio::io_scan_forward<char_type>(::ufio::io_scan_alias(args))...);
		}
		else
		{
			if (!::ufio::operations::decay::scan_freestanding_decay(
					::ufio::operations::input_stream_ref(in),
					::ufio::io_scan_forward<char_type>(::ufio::io_scan_alias(args))...))
			{
				::ufio::throw_parse_code(::ufio::parse_code::end_of_file);
			}
		}
	}
	else
	{
#if ((__STDC_HOSTED__ == 1 && (!defined(_GLIBCXX_HOSTED) || _GLIBCXX_HOSTED == 1) && \
	  !defined(_LIBCPP_FREESTANDING)) ||                                             \
	 defined(UFIO_ENABLE_HOSTED_FEATURES)) &&                                     \
	__has_include(<stdio.h>)
		return ::ufio::details::scan_after_io_scan_forward<report>(
			::ufio::io_scan_forward<char>(::ufio::io_scan_alias(in)),
			::ufio::io_scan_forward<char>(::ufio::io_scan_alias(args))...);
#else
		// clang-format off
static_assert(device_error, "freestanding environment must provide IO device");
		// clang-format on
#endif
	}
}

} // namespace io

} // namespace ufio
