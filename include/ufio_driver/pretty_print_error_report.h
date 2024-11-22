#pragma once

#if !((defined(__cpp_static_assert) && __cpp_static_assert >= 202306L) && (defined(_GLIBCXX_STRING) || defined(_LIBCPP_STRING) || defined(_STRING_)))
#error "pretty error needs user-defined string literal for static_assert"
#endif

namespace ufio
{

template <::std::size_t index, ::std::integral char_type, typename T, typename... Args>
struct print_freestanding_params_assert_okay_type
{
	inline static constexpr bool type_ok{::ufio::operations::defines::print_freestanding_params_okay<char_type, T>};
	inline static constexpr bool value{print_freestanding_params_assert_okay_type<index + 1, char_type, Args...>::value && type_ok};
	static_assert(type_ok, ::ufio::concat("the ", ::ufio::mnp::ordinal(index), " parameter is not printable on this char type"));
};

template <::std::size_t index, ::std::integral char_type, typename T>
struct print_freestanding_params_assert_okay_type<index, char_type, T>
{
	inline static constexpr bool type_ok{::ufio::operations::defines::print_freestanding_params_okay<char_type, T>};
	static constexpr bool value{type_ok};
	static_assert(type_ok, ::ufio::concat("the ", ::ufio::mnp::ordinal(index), " parameter is not printable on this char type"));
};

template <::std::integral char_type, typename... Args>
inline constexpr bool print_freestanding_params_assert_okay_v{print_freestanding_params_assert_okay_type<0, char_type, Args...>::value};

template <typename output, typename... Args>
inline constexpr bool print_freestanding_params_assert_okay(output &&, Args &&...) noexcept
{
	return print_freestanding_params_assert_okay_v<typename ::ufio::details::print_freestanding_output_decay_t<output>::output_char_type, Args...>;
}

} // namespace ufio
