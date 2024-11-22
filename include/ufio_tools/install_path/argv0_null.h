#pragma once

namespace ufio::details
{
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
#if __has_cpp_attribute(__gnu__::__const__)
[[__gnu__::__const__]]
#endif
[[noreturn]]
inline ::ufio::install_path get_module_install_path_from_argv0(char const *argv0) 
{
	throw_win32_error(0);
}
} // namespace uwvm::path
