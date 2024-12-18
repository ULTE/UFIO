﻿#pragma once

#if __has_include(<stdio.h>)
#include "c/impl.h"
#endif

namespace ufio
{
#if !defined(__AVR__)

inline
#if defined(__WINE__) || !defined(_WIN32)
	constexpr
#endif
	native_io_observer
	in() noexcept
{
	return native_stdin();
}

inline
#if defined(__WINE__) || !defined(_WIN32)
	constexpr
#endif
	native_io_observer
	out() noexcept
{
	return native_stdout();
}

inline
#if defined(__WINE__) || !defined(_WIN32)
	constexpr
#endif
	native_io_observer
	err() noexcept
{
	return native_stderr();
}

inline
#if defined(__WINE__) || !defined(_WIN32)
	constexpr
#endif
	decltype(auto)
	u8in() noexcept
{
	return native_stdin<char8_t>();
}

inline
#if defined(__WINE__) || !defined(_WIN32)
	constexpr
#endif
	decltype(auto)
	u8out() noexcept
{
	return native_stdout<char8_t>();
}

inline
#if defined(__WINE__) || !defined(_WIN32)
	constexpr
#endif
	decltype(auto)
	u8err() noexcept
{
	return native_stderr<char8_t>();
}

using in_buf_type = basic_ibuf<native_io_observer>;
using out_buf_type = basic_obuf<native_io_observer>;

using u8in_buf_type = basic_ibuf<u8native_io_observer>;
using u8out_buf_type = basic_obuf<u8native_io_observer>;

using in_buf_type_lockable = basic_io_lockable<in_buf_type>;
using out_buf_type_lockable = basic_io_lockable<out_buf_type>;

using u8in_buf_type_lockable = basic_io_lockable<u8in_buf_type>;
using u8out_buf_type_lockable = basic_io_lockable<u8out_buf_type>;

#endif

namespace details
{

template <bool line, typename... Args>
inline constexpr void print_after_io_print_forward(Args... args)
{
#if __has_include(<stdio.h>)
	::ufio::operations::decay::print_freestanding_decay<line>(c_stdout(), args...);
#else
	::ufio::operations::decay::print_freestanding_decay<line>(out(), args...);
#endif
}

template <bool line, typename... Args>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void perr_after_io_print_forward(Args... args)
{
#if defined(__AVR__)
	::ufio::operations::decay::print_freestanding_decay<line>(c_stderr(), args...);
#else
	::ufio::operations::decay::print_freestanding_decay<line>(err(), args...);
#endif
}

template <bool line, typename... Args>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline constexpr void debug_print_after_io_print_forward(Args... args)
{
#if defined(__AVR__)
	::ufio::operations::decay::print_freestanding_decay<line>(c_stdout(), args...);
#else
	::ufio::operations::decay::print_freestanding_decay<line>(out(), args...);
#endif
}

template <bool report, typename... Args>
inline constexpr ::std::conditional_t<report, bool, void> scan_after_io_scan_forward(Args... args)
{
#if __has_include(<stdio.h>)
	if constexpr (report)
	{
		return ::ufio::operations::decay::scan_freestanding_decay(c_stdin(), args...);
	}
	else
	{
		if (!::ufio::operations::decay::scan_freestanding_decay(c_stdin(), args...))
		{
			::ufio::throw_parse_code(ufio::parse_code::end_of_file);
		}
	}
#endif
}

} // namespace details

} // namespace ufio
