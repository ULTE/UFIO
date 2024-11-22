#pragma once

/*
Referenced from
https://github.com/sunfishcode/wasm-reference-manual/blob/master/WebAssembly.md#primitive-encoding-types
*/

namespace ufio
{

namespace manipulators
{

template <::std::floating_point T>
inline constexpr auto wasm_float_put(T t)
{
	return ::ufio::manipulators::iec559_le_put(t);
}

template <::std::floating_point T>
inline constexpr auto wasm_float_get(T &t)
{
	return ::ufio::manipulators::iec559_le_get(t);
}

template <::ufio::details::my_integral T>
inline constexpr auto wasm_varint_put(T t)
{
	return ::ufio::manipulators::leb128_put(t);
}

template <::ufio::details::my_integral T>
inline constexpr auto wasm_varint_get(T &t)
{
	return ::ufio::manipulators::leb128_get(t);
}

template <::ufio::details::my_integral T>
inline constexpr auto wasm_uint32_put(T t)
{
	return ::ufio::manipulators::le_put<32>(t);
}

template <::ufio::details::my_integral T>
inline constexpr auto wasm_uint32_get(T &t)
{
	return ::ufio::manipulators::le_get<32>(t);
}

template <::ufio::details::my_integral T>
inline constexpr auto wasm_uint64_put(T t)
{
	return ::ufio::manipulators::le_put<64>(t);
}

template <::ufio::details::my_integral T>
inline constexpr auto wasm_uint64_get(T &t)
{
	return ::ufio::manipulators::le_get<64>(t);
}

} // namespace manipulators

} // namespace ufio
