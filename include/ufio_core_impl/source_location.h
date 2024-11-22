#pragma once

namespace ufio
{

template <::std::integral char_type>
	requires(sizeof(char_type) == 1)
inline constexpr reserve_scatters_size_result
	print_reserve_scatters_size(::ufio::io_reserve_type_t<char_type, ::std::source_location>) noexcept
{
	constexpr ::std::size_t ulint32_rsv_size{
		print_reserve_size(::ufio::io_reserve_type<char_type, ::std::uint_least32_t>)};
	constexpr ::std::size_t total_uint_least32_t_rsv_size{ulint32_rsv_size * 2 + 3};
	return {3, total_uint_least32_t_rsv_size};
}

namespace details
{

template <::std::integral char_type>
	requires(sizeof(char_type) == 1)
inline constexpr basic_reserve_scatters_define_result<char_type>
prrsv_reserve_scatters_source_location_define_impl(::ufio::basic_io_scatter_t<char_type> *pscatters,
												   char_type *pbuffer, ::std::source_location const &location) noexcept
{
	using chartypeconstaliasptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= char_type const *;
	if constexpr (::std::same_as<char_type, char>)
	{
		char const *fnm{location.file_name()};
		*pscatters = ::ufio::basic_io_scatter_t<char_type>{fnm, ::ufio::cstr_len(fnm)};
	}
	else
	{
		char_type const *fnm{reinterpret_cast<chartypeconstaliasptr>(location.file_name())};
		*pscatters = ::ufio::basic_io_scatter_t<char_type>{fnm, ::ufio::cstr_len(fnm)};
	}
	++pscatters;
	char_type *iter{pbuffer};
	*iter = ::ufio::char_literal_v<u8':', char_type>;
	++iter;
	iter = print_reserve_define(::ufio::io_reserve_type<char_type, ::std::uint_least32_t>, iter, location.line());
	*iter = ::ufio::char_literal_v<u8':', char_type>;
	++iter;
	iter = print_reserve_define(::ufio::io_reserve_type<char_type, ::std::uint_least32_t>, iter, location.column());
	*iter = ::ufio::char_literal_v<u8':', char_type>;
	++iter;
	*pscatters = ::ufio::basic_io_scatter_t<char_type>{pbuffer, static_cast<::std::size_t>(iter - pbuffer)};
	++pscatters;
	if constexpr (::std::same_as<char_type, char>)
	{
		char const *fnm{location.function_name()};
		*pscatters = ::ufio::basic_io_scatter_t<char_type>{fnm, ::ufio::cstr_len(fnm)};
	}
	else
	{
		char_type const *fnm{reinterpret_cast<chartypeconstaliasptr>(location.function_name())};
		*pscatters = ::ufio::basic_io_scatter_t<char_type>{fnm, ::ufio::cstr_len(fnm)};
	}
	++pscatters;
	return {pscatters, iter};
}

} // namespace details

template <::std::integral char_type>
	requires(sizeof(char_type) == 1)
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr basic_reserve_scatters_define_result<char_type>
print_reserve_scatters_define(::ufio::io_reserve_type_t<char_type, ::std::source_location>,
							  ::ufio::basic_io_scatter_t<char_type> *pscatters, char_type *pbuffer,
							  ::std::source_location const &location) noexcept
{
	return ::ufio::details::prrsv_reserve_scatters_source_location_define_impl(pscatters, pbuffer, location);
}

namespace manipulators
{

inline
#ifdef __cpp_consteval
	consteval
#else
	constexpr
#endif
	::std::source_location
	cur_src_loc(::std::source_location loc = ::std::source_location::current()) noexcept
{
	return loc;
}

} // namespace manipulators

} // namespace ufio
