#pragma once

#include <mach-o/dyld.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <stdbool.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

namespace ufio::details
{
/*
 * unknown-apple-darwin
 * https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/dyld.3.html
 * for Mac OS, IOS, watch os, ...
 */
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
#if __has_cpp_attribute(__gnu__::__const__)
[[__gnu__::__const__]]
#endif
inline ::ufio::install_path get_module_install_path()
{
	char buffer[PATH_MAX + 1];
	::std::uint_least32_t size{PATH_MAX};
	if (::ufio::noexcept_call(::_NSGetExecutablePath, buffer, __builtin_addressof(size)) == -1) [[unlikely]]
	{
		throw_posix_error();
	}
	char buffer2[PATH_MAX + 1];
	char *resolved{::ufio::noexcept_call(::realpath, buffer, buffer2)};
	if (!resolved) [[unlikely]]
	{
		throw_posix_error();
	}

	::ufio::install_path ret;

	ret.module_name = ::ufio::u8concat_ufio(::ufio::mnp::code_cvt_os_c_str(resolved));
	auto const begin{strlike_begin(::ufio::io_strlike_type<char8_t, ::ufio::u8string>, ret.module_name)};
	auto curr{strlike_curr(::ufio::io_strlike_type<char8_t, ::ufio::u8string>, ret.module_name)};
	for (; curr != begin; curr--)
	{
		if (auto const c{*curr}; c == u8'/')
		{
			curr++;
			break;
		}
	}
	ret.path_name = ::ufio::u8string{begin, curr - 1};
	ret.module_name.erase(begin, curr);
	return ret;
}
} // namespace ufio::details
