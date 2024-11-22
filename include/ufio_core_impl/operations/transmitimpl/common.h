#pragma once

namespace ufio
{

namespace details
{

template <typename T>
concept transmit_integer_wrapper = requires(T t, ::std::size_t off, ::ufio::uintfpos_t uoff) {
	transmit_integer_add_define(t, off);
	transmit_integer_assign_from_uintfpos_define(t, uoff);
};

template <::std::size_t sz>
inline constexpr ::std::size_t calculate_transmit_buffer_size() noexcept
{
#ifdef UFIO_BUFFER_SIZE
	static_assert(sz >= UFIO_BUFFER_SIZE);
	static_assert(UFIO_BUFFER_SIZE < SIZE_MAX);
	return UFIO_BUFFER_SIZE / sz;
#else
	if constexpr (sizeof(::std::size_t) <= sizeof(::std::uint_least16_t))
	{
		return 4096 / sz;
	}
	else
	{
		return 131072 / sz;
	}
#endif
}

template <::std::size_t sz>
inline constexpr ::std::size_t transmit_buffer_size_cache{calculate_transmit_buffer_size<sz>()};

} // namespace details

struct uintfpos_transmit_reference_wrapper
{
	::ufio::uintfpos_t *pfpos{};
};

inline constexpr void transmit_integer_assign_from_uintfpos_define(uintfpos_transmit_reference_wrapper t,
																   ::std::size_t off) noexcept
{
	*t.pfpos = off;
}

inline constexpr void transmit_integer_add_define(uintfpos_transmit_reference_wrapper t, ::std::size_t off) noexcept
{
	using commontype = ::std::common_type_t<::ufio::uintfpos_t, ::std::size_t>;
	commontype val{static_cast<commontype>(*t.pfpos)};
	constexpr commontype mx{::std::numeric_limits<::ufio::uintfpos_t>::max()};
	if constexpr (sizeof(::ufio::uintfpos_t) < sizeof(::std::size_t))
	{
		if (mx < off)
		{
			*t.pfpos = mx;
			return;
		}
	}
	commontype mxval{static_cast<commontype>(static_cast<commontype>(mx) - off)};
	if (mxval < val)
	{
		*t.pfpos = mx;
	}
	else
	{
		*t.pfpos = val + off;
	}
}

struct transmit_result
{
	::ufio::uintfpos_t transmitted{};
	inline constexpr bool is_overflowed() noexcept
	{
		constexpr auto mxval{::std::numeric_limits<::ufio::uintfpos_t>::max()};
		return transmitted == mxval;
	}
};

template <::std::integral char_type>
inline constexpr ::std::size_t print_reserve_size(::ufio::io_reserve_type_t<char_type, transmit_result>)
{
	constexpr ::std::size_t sz{print_reserve_size(::ufio::io_reserve_type<char_type, ::ufio::uintfpos_t>) + 1};
	return sz;
}

template <::std::integral char_type>
inline constexpr char_type *print_reserve_define(::ufio::io_reserve_type_t<char_type, transmit_result>,
												 char_type *iter, transmit_result r)
{
	::ufio::uintfpos_t transmittedsz{r.transmitted};
	constexpr auto mxval{::std::numeric_limits<::ufio::uintfpos_t>::max()};
	iter = print_reserve_define(::ufio::io_reserve_type<char_type, ::ufio::uintfpos_t>, iter, transmittedsz);
	if (transmittedsz == mxval)
	{
		*iter = ::ufio::char_literal_v<u8'+', char_type>;
		++iter;
	}
	return iter;
}

} // namespace ufio
