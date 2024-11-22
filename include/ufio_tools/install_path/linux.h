#pragma once

#if defined(__linux__)
#include <linux/limits.h>
#else
#include <limits.h>
#endif

namespace ufio::details
{
/*
 * for linux, cygwin and solaris
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
	::ufio::install_path ret;

#if defined(__linux__) && defined(__NR_readlink)
	auto resolved{::ufio::system_call<__NR_readlink, int>("/proc/self/exe", buffer, PATH_MAX)};
	system_call_throw_error(resolved);
	buffer[resolved] = '\0';
	ret.module_name = ::ufio::u8concat_ufio(::ufio::mnp::code_cvt(::ufio::mnp::os_c_str_with_known_size(buffer, resolved)));
#else
	char *resolved{
		::ufio::noexcept_call(::realpath,
#if defined(__sun)
								 "/proc/self/path/a.out"
#else
								 "/proc/self/exe"
#endif
								 ,
								 buffer)};
	if (!resolved) [[unlikely]]
	{
		return;
	}
	ret.module_name = ::ufio::u8concat_ufio(::ufio::mnp::code_cvt_os_c_str(resolved));
#endif
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
} // namespace uwvm::path
