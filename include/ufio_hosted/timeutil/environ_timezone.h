#pragma once

#include <cstdlib>

namespace ufio
{

struct environ_timezone_name
{
	using char8_const_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= char8_t const *;
	char8_const_may_alias_ptr name{u8"Etc/GMT"};
};

namespace details
{
inline environ_timezone_name environ_localtimezone_impl() noexcept
{
	auto ptr{reinterpret_cast<::ufio::environ_timezone_name::char8_const_may_alias_ptr>(
#if !defined(__has_builtin)
#if __has_builtin(__builtin_getenv)
		__builtin_getenv
#else
		::std::getenv
#endif
#else
		::std::getenv
#endif
		(reinterpret_cast<char const *>(u8"TZ")))};
	if (ptr == nullptr)
	{
		return {};
	}
	return {ptr};
}
} // namespace details

struct environ_local_timezone
{
	inline environ_timezone_name operator()() noexcept
	{
		return ::ufio::details::environ_localtimezone_impl();
	}
};

inline constexpr cross_code_cvt_t<char8_t> print_alias_define(::ufio::io_alias_t, environ_timezone_name enm) noexcept
{
	return ::ufio::cross_code_cvt_t<char8_t>{{enm.name, ::ufio::details::dummy_cstr_len(enm.name)}};
}

using native_local_timezone = environ_local_timezone;

} // namespace ufio
