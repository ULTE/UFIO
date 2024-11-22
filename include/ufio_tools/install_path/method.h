#pragma once

namespace ufio
{
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
#if __has_cpp_attribute(__gnu__::__const__)
[[__gnu__::__const__]]
#endif
inline ::ufio::install_path get_module_install_path()
{
	return ::ufio::details::get_module_install_path();
}

#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
#if __has_cpp_attribute(__gnu__::__const__)
[[__gnu__::__const__]]
#endif
inline ::ufio::install_path get_module_install_path_from_argv0(char const *argv0)
{
	return ::ufio::details::get_module_install_path_from_argv0(argv0);
}
}
