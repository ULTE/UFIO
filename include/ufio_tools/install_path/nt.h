#pragma once

namespace ufio::details
{
/*
 * for Windows NT
 */
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
#if __has_cpp_attribute(__gnu__::__const__)
[[__gnu__::__const__]]
#endif
inline ::ufio::install_path get_module_install_path()
{
	auto c_peb{::ufio::win32::nt::nt_get_current_peb()};
	auto const &NtImagePath{c_peb->ProcessParameters->ImagePathName};
	if (!NtImagePath.Buffer) [[unlikely]]
	{
		::ufio::throw_nt_error(0xC0000106);
	}

	::ufio::install_path ret;

	ret.module_name = ::ufio::u8concat_ufio(::ufio::mnp::code_cvt(::ufio::mnp::os_c_str_with_known_size(NtImagePath.Buffer, NtImagePath.Length / sizeof(char16_t))));
	auto const begin{strlike_begin(::ufio::io_strlike_type<char8_t, ::ufio::u8string>, ret.module_name)};
	auto curr{strlike_curr(::ufio::io_strlike_type<char8_t, ::ufio::u8string>, ret.module_name)};
	for (; curr != begin; curr--) // calculate nt, dos or (nt) device path
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
