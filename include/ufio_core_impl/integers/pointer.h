﻿#pragma once

namespace ufio
{

/*
we do not accept char const* since we never know whether it has null terminator.
This avoids security vulneralbilities for
		char * str = 0;
		print(str);
Instead, we print out its pointer value

We extend print pointers to print contiguous_iterator. No we can write things like

::std::vector<::std::size_t> vec(100,2);
println("vec.begin():",ufio::mnp::funcvw(vec.begin())," vec.end()",ufio::mnp::funcvw(vec.end()));
*/
namespace manipulators
{
template <typename T>
struct chvw_t
{
	using manip_tag = manip_tag_t;
	T reference;
};

template <::std::integral ch_type, ::std::size_t N>
struct small_scatter_t
{
	using manip_tag = manip_tag_t;
	ch_type const *base{};
	::std::size_t len{};
};

template <::std::integral T>
inline constexpr chvw_t<T> chvw(T ch) noexcept
{
	return {ch};
}

template <::std::integral char_type>
inline constexpr basic_io_scatter_t<char_type> print_alias_define(io_alias_t, basic_os_c_str<char_type> bas) noexcept
{
	auto ptr{bas.ptr};
	return {ptr, ::ufio::cstr_len(ptr)};
}

template <::std::integral char_type>
inline constexpr basic_io_scatter_t<char_type>
print_alias_define(io_alias_t, basic_os_c_str_with_known_size<char_type> bas) noexcept
{
	return {bas.ptr, bas.n};
}

template <::std::integral char_type>
inline constexpr basic_io_scatter_t<char_type>
print_alias_define(io_alias_t, basic_os_str_known_size_without_null_terminated<char_type> bas) noexcept
{
	return {bas.ptr, bas.n};
}

template <::std::integral char_type>
inline constexpr basic_os_str_known_size_without_null_terminated<char_type> os_c_str(char_type const *ch, ::std::size_t n) noexcept
{
	return {ch, ::ufio::cstr_nlen(ch, n)};
}

template <::std::integral char_type, ::std::size_t n>
	requires(n != 0)
inline constexpr basic_os_str_known_size_without_null_terminated<char_type> os_c_str_carr(char_type const (&cstr)[n]) noexcept
{
	constexpr ::std::size_t nm1{static_cast<::std::size_t>(n - 1u)};
	return os_c_str(cstr, nm1);
}

template <::std::integral char_type>
inline constexpr basic_os_c_str_with_known_size<char_type> os_c_str_null_terminated(char_type const *ch, ::std::size_t n) noexcept
{
	return {ch, n};
}

template <::std::integral char_type, ::std::size_t n>
	requires(n != 0)
inline constexpr basic_os_str_known_size_without_null_terminated<char_type> os_c_str_null_terminated_carr(char_type const (&cstr)[n]) noexcept
{
	constexpr ::std::size_t nm1{static_cast<::std::size_t>(n - 1u)};
	return os_c_str_null_terminated(cstr, nm1);
}

template <::std::integral char_type, ::std::size_t n>
	requires(n != 0)
inline constexpr auto small_scatter(char_type const (&s)[n]) noexcept
{
	constexpr bool not_char_literal{::std::is_const_v<char_type>};
	if constexpr (not_char_literal)
	{
		constexpr ::std::size_t nm1{n - 1};
		constexpr ::std::size_t boundary{64}, boundaryp1{boundary + 1};
		if constexpr (n == 2)
		{
			return manipulators::chvw_t<::std::remove_const_t<char_type>>{*s};
		}
		else if constexpr (n < boundaryp1)
		{
			return ::ufio::manipulators::small_scatter_t<::std::remove_const_t<char_type>, boundary>{s, nm1};
		}
		else
		{
			return basic_io_scatter_t<::std::remove_const_t<char_type>>{s, nm1};
		}
	}
	else
	{
		static_assert(not_char_literal, "The type is an array but not char array literal. Reject.");
		return;
	}
}

template <::std::integral T>
inline constexpr void os_c_str(decltype(nullptr), ::std::size_t) noexcept = delete;

template <::std::contiguous_iterator Iter>
	requires ::std::integral<::std::iter_value_t<Iter>>
inline constexpr basic_io_scatter_t<::std::remove_cvref_t<::std::iter_value_t<Iter>>> strvw(Iter first,
																							Iter last) noexcept
{
	return {::std::to_address(first), static_cast<::std::size_t>(last - first)};
}

template <::std::ranges::contiguous_range rg>
	requires ::std::integral<::std::ranges::range_value_t<rg>>
inline constexpr basic_io_scatter_t<::std::remove_cvref_t<::std::ranges::range_value_t<rg>>> strvw(rg &&r) noexcept
{
	return {::std::ranges::data(r), ::std::ranges::size(r)};
}

template <::std::ranges::contiguous_range rg>
	requires(::std::integral<::std::ranges::range_value_t<rg>>)
inline constexpr basic_os_str_known_size_without_null_terminated<::std::remove_cvref_t<::std::ranges::range_value_t<rg>>>
os_c_str(rg &&r) noexcept
{
	auto p{::std::ranges::data(r)};
	return {p, ::ufio::cstr_nlen(p, ::std::ranges::size(r))};
}

template <typename enumtype>
	requires(::std::is_enum_v<enumtype>)
inline constexpr ::std::underlying_type_t<enumtype> enum_int_view(enumtype enm) noexcept
{
	return static_cast<::std::underlying_type_t<enumtype>>(enm);
}

} // namespace manipulators

template <::std::integral char_type>
inline constexpr basic_io_scatter_t<char_type>
print_scatter_define(io_reserve_type_t<char_type, basic_io_scatter_t<char_type>>,
					 basic_io_scatter_t<char_type> iosc) noexcept
{
	return iosc;
}

namespace details
{

template <typename T, ::std::size_t N>
struct my_constant_passer
{
	using value_type = T;
	static inline constexpr ::std::size_t value{N};
};

template <::std::integral char_type, ::std::size_t n>
inline consteval my_constant_passer<char_type, n> compute_char_literal_array_type(char_type (&)[n]) noexcept
{
	return {};
}

template <typename T>
concept printaliascarray = ::std::is_array_v<::std::remove_reference_t<T>> &&
						   ::std::integral<::std::remove_extent_t<::std::remove_cvref_t<T>>> &&
						   requires(T const &s) { ::ufio::details::compute_char_literal_array_type(s); };

} // namespace details

template <typename T>
	requires(::ufio::details::printaliascarray<T>)
inline constexpr auto print_alias_define(io_alias_t, T const &s) noexcept
{
	using constanttype = decltype(::ufio::details::compute_char_literal_array_type(s));
	using char_type = typename constanttype::value_type;
	using no_const_char_type = ::std::remove_const_t<char_type>;

	constexpr bool not_char_literal{::std::is_const_v<char_type>};
	constexpr ::std::size_t n{constanttype::value};
	constexpr ::std::size_t nm1{n - 1};
	static_assert(n != 0);
	static_assert(not_char_literal, "The type is an array but not char array literal. Reject.");

	if constexpr (n == 2)
	{
		return manipulators::chvw_t<no_const_char_type>{*s};
	}
	else
	{
		return basic_io_scatter_t<no_const_char_type>{s, nm1};
	}
}

template <typename T>
	requires(::std::ranges::contiguous_range<T> && requires(T &&t) { t.substr(); })
inline constexpr basic_io_scatter_t<::std::remove_cvref_t<::std::ranges::range_value_t<T>>>
print_alias_define(io_alias_t, T &&svw) noexcept
{
	return {::std::ranges::data(svw), ::std::ranges::size(svw)};
}

template <::std::integral char_type, ::std::integral pchar_type>
inline constexpr ::std::size_t
print_reserve_size(io_reserve_type_t<char_type, manipulators::chvw_t<pchar_type>>) noexcept
{
	return 1;
}

template <::std::integral char_type, ::std::integral pchar_type, typename T>
inline constexpr char_type *print_reserve_define(io_reserve_type_t<char_type, manipulators::chvw_t<pchar_type>>,
												 char_type *iter, T ch) noexcept
{
	using unsigned_char_type = ::std::make_unsigned_t<char_type>;
	*iter = static_cast<char_type>(static_cast<unsigned_char_type>(ch.reference));
	return ++iter;
}

template <::std::integral char_type, ::std::size_t N>
inline constexpr ::std::size_t
print_reserve_size(io_reserve_type_t<char_type, ::ufio::manipulators::small_scatter_t<char_type, N>>) noexcept
{
	return N;
}

namespace details
{

template <::std::integral char_type>
inline constexpr char_type *small_scatter_print_reserve_define_impl(char_type *iter, char_type const *base,
																	::std::size_t len) noexcept
{
	return ::ufio::details::non_overlapped_copy_n(base, len, iter);
}

} // namespace details

template <::std::integral char_type, ::std::size_t N>
inline constexpr char_type *
print_reserve_define(io_reserve_type_t<char_type, ::ufio::manipulators::small_scatter_t<char_type, N>>,
					 char_type *iter, ::ufio::manipulators::small_scatter_t<char_type, N> scatter) noexcept
{

	return ::ufio::details::small_scatter_print_reserve_define_impl(iter, scatter.base, scatter.len);
}

template <::std::integral char_type, ::std::size_t N>
inline constexpr ::std::size_t
print_reserve_precise_size(io_reserve_type_t<char_type, ::ufio::manipulators::small_scatter_t<char_type, N>>,
						   ::ufio::manipulators::small_scatter_t<char_type, N> scatter) noexcept
{
	return scatter.len;
}

template <::std::integral char_type, ::std::size_t N>
inline constexpr char_type *
print_reserve_precise_define(io_reserve_type_t<char_type, ::ufio::manipulators::small_scatter_t<char_type, N>>,
							 char_type *iter, ::std::size_t,
							 ::ufio::manipulators::small_scatter_t<char_type, N> scatter) noexcept
{
	return ::ufio::details::small_scatter_print_reserve_define_impl(iter, scatter.base, scatter.len);
}

} // namespace ufio
