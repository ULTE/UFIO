#pragma once
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <dlfcn.h>
#include <stdbool.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

namespace ufio::details
{
/*
 * for DragonFlyBSD ,FreeBSD, NetBSD
 */
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
#if __has_cpp_attribute(__gnu__::__const__)
[[__gnu__::__const__]]
#endif
inline ::ufio::install_path get_module_install_path()
{
	char buffer1[PATH_MAX + 1];
	char buffer2[PATH_MAX + 1];
	char *resolved{};
	int length = -1;

#if defined(__NetBSD__)
	int mib[4]{CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME};
#else
	int mib[4]{CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
#endif
	::std::size_t size{PATH_MAX};

	if (auto status{::ufio::noexcept_call(::sysctl, mib, 4, buffer1, __builtin_addressof(size), nullptr, 0)}; !status) [[unlikely]]
	{
		throw_posix_error(status);
	}

	resolved = ::ufio::noexcept_call(::realpath, buffer1, buffer2);

	if (!resolved) [[unlikely]]
	{
		throw_posix_error(resolved);
	}

	::ufio::install_path ret;

	ret.module_name = ::ufio::u8concat_ufio(::ufio::mnp::code_cvt_os_c_str(resolved));
	auto const begin{strlike_begin(::ufio::io_strlike_type<char8_t, ::ufio::u8string>, ret.module_name)};
	auto curr{strlike_curr(::ufio::io_strlike_type<char8_t, ::ufio::u8string>, ret.module_name)};
	for (; curr != begin; curr--) // calculate nt or dos path
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
