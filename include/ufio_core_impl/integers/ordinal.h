#pragma once

namespace ufio
{

namespace manipulators
{

template <typename T>
struct ordinal_t
{
	T reference;
};

template <::ufio::details::my_integral T>
inline constexpr auto ordinal(T t) noexcept
{
	using int_alias_type = typename ::ufio::details::integer_alias_type<T>;
	return ::ufio::manipulators::scalar_manip_t<::ufio::manipulators::integral_default_scalar_flags, ::ufio::manipulators::ordinal_t<int_alias_type>>{{static_cast<int_alias_type>(t)}};
}

} // namespace manipulators

namespace details
{

template <::std::size_t base, bool showbase, bool uppercase_showbase, bool showpos, bool uppercase, bool full, ::std::integral char_type, typename T>
inline constexpr char_type *prrsv_ordinal_impl(char_type *iter, T t) noexcept
{
	iter = ::ufio::details::print_reserve_integral_define<base, showbase, uppercase_showbase, showpos, uppercase, full>(iter, t);
	std::uint_least8_t prefix_kind{};
	if (t / 100 % 10 == 1)
	{
		prefix_kind = 0;
	}
	else
	{
		switch (t % 10)
		{
		case 1:
			prefix_kind = 1;
			break;
		case 2:
			prefix_kind = 2;
			break;
		case 3:
			prefix_kind = 3;
			break;
		default:
			prefix_kind = 0;
			break;
		}
	}
	switch (prefix_kind)
	{
	case 1:
		*iter++ = ::ufio::char_literal_v<u8's', char_type>;
		*iter++ = ::ufio::char_literal_v<u8't', char_type>;
		break;
	case 2:
		*iter++ = ::ufio::char_literal_v<u8'n', char_type>;
		*iter++ = ::ufio::char_literal_v<u8'd', char_type>;
		break;
	case 3:
		*iter++ = ::ufio::char_literal_v<u8'r', char_type>;
		*iter++ = ::ufio::char_literal_v<u8'd', char_type>;
		break;
	default:
		*iter++ = ::ufio::char_literal_v<u8't', char_type>;
		*iter++ = ::ufio::char_literal_v<u8'h', char_type>;
		break;
	}
	return iter;
}

} // namespace details

template <::std::integral char_type, ::ufio::manipulators::scalar_flags flags, ::ufio::details::my_integral T>
inline constexpr ::std::size_t print_reserve_size(::ufio::io_reserve_type_t<char_type, ::ufio::manipulators::scalar_manip_t<flags, ::ufio::manipulators::ordinal_t<T>>>)
{
	return ::ufio::details::print_integer_reserved_size_cache<flags.base, flags.showbase, flags.showpos, T> + 2u;
}

template <::std::integral char_type, ::ufio::manipulators::scalar_flags flags, typename T>
inline constexpr char_type *print_reserve_define(::ufio::io_reserve_type_t<char_type, ::ufio::manipulators::scalar_manip_t<flags, ::ufio::manipulators::ordinal_t<T>>>, char_type *iter, ::ufio::manipulators::scalar_manip_t<flags, ::ufio::manipulators::ordinal_t<T>> t) noexcept
{
	return ::ufio::details::prrsv_ordinal_impl<flags.base, flags.showbase, flags.uppercase_showbase, flags.showpos, flags.uppercase, flags.full>(iter, t.reference.reference);
}

} // namespace ufio
