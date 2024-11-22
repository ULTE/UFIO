#pragma once

namespace ufio
{

inline constexpr ::std::size_t domain_define(error_type_t<::ufio::freestanding::errc>) noexcept
{
	if constexpr (sizeof(::std::size_t) <= sizeof(::std::uint_least16_t))
	{
		return 52386u;
	}
	else if constexpr (sizeof(::std::size_t) <= sizeof(::std::uint_least32_t))
	{
		return 1105291838u;
	}
	else
	{
		return 11138730069487200664ULL;
	}
}

inline constexpr ::std::size_t posix_domain_value{domain_define(error_type<::ufio::freestanding::errc>)};

[[noreturn]] inline void throw_posix_error()
{
#ifdef __cpp_exceptions
#if defined(_MSC_VER) && (!defined(_HAS_EXCEPTIONS) || _HAS_EXCEPTIONS == 0)
	fast_terminate();
#else
	throw ::ufio::error{posix_domain_value, static_cast<::std::size_t>(static_cast<unsigned>(errno))};
#endif
#else
	fast_terminate();
#endif
}
[[noreturn]] inline void throw_posix_error([[maybe_unused]] int err)
{
#ifdef __cpp_exceptions
#if defined(_MSC_VER) && (!defined(_HAS_EXCEPTIONS) || _HAS_EXCEPTIONS == 0)
	fast_terminate();
#else
	throw ::ufio::error{posix_domain_value, static_cast<::std::size_t>(static_cast<unsigned>(err))};
#endif
#else
	fast_terminate();
#endif
}

template <::std::integral char_type>
inline constexpr basic_io_scatter_t<char_type> status_io_print_forward(io_alias_type_t<char_type>,
																	   ::ufio::freestanding::errc perr) noexcept
{
	return get_posix_errno_scatter<char_type>(static_cast<int>(perr));
}

#if !((defined(_WIN32) && !defined(__WINE__)) || defined(__CYGWIN__))

namespace details
{
inline constexpr bool posix_code_equivalent_impl(::std::size_t domain, ::std::size_t code, int e) noexcept
{
	if (posix_domain_value != domain)
	{
		return false;
	}
	else
	{
		using common_type = ::std::common_type_t<::std::size_t, unsigned>;
		return code == static_cast<common_type>(static_cast<unsigned>(e));
	}
}

inline constexpr int to_posix_code_impl(::std::size_t domain, ::std::size_t code) noexcept
{
	if (posix_domain_value != domain)
	{
#if defined(EOTHER)
		return EOTHER;
#else
		return EINVAL;
#endif
	}
	else
	{
		return static_cast<int>(static_cast<unsigned>(code));
	}
}

} // namespace details

inline constexpr bool equivalent_define(error_type_t<::ufio::freestanding::errc>, ::ufio::error e,
										::ufio::freestanding::errc p)
{
	return ::ufio::details::posix_code_equivalent_impl(e.domain, e.code, static_cast<int>(p));
}

inline constexpr ::ufio::freestanding::errc to_code_define(error_type_t<::ufio::freestanding::errc>,
															  error e) noexcept
{
	return ::ufio::freestanding::errc{::ufio::details::to_posix_code_impl(e.domain, e.code)};
}

using native_code = ::ufio::freestanding::errc;

inline constexpr ::ufio::freestanding::errc print_alias_define(::ufio::io_alias_t, ::ufio::error e) noexcept
{
	return to_code_define(error_type<::ufio::freestanding::errc>, e);
}

#endif

} // namespace ufio
