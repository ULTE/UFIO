#pragma once

#include <stdlib.h>

namespace ufio::details
{
/*
 * for win9x
 */
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
#if __has_cpp_attribute(__gnu__::__const__)
[[__gnu__::__const__]]
#endif
inline ::ufio::install_path get_module_install_path()
{
	char *pgmptr{};
	if (::ufio::noexcept_call(::_get_pgmptr, __builtin_addressof(pgmptr)))
	{
		throw_win32_error(24);
	}
	
	/* Will be affected by regional encoding settings, and _get_wpgmptr may not succeed, so only use on windows 9x */
	::ufio::install_path ret;
	ret.module_name = ::ufio::u8concat_ufio(::ufio::mnp::code_cvt_os_c_str(pgmptr));
	auto const begin{strlike_begin(::ufio::io_strlike_type<char8_t, ::ufio::u8string>, ret.module_name)};
	auto curr{strlike_curr(::ufio::io_strlike_type<char8_t, ::ufio::u8string>, ret.module_name)};
	for (; curr != begin; curr--) // calculate dos path
	{
		if (auto const c{*curr}; c == u8'\\' || c == u8':'  || c == u8'/')
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
