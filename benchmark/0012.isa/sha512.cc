/*
Use sha512 to measure performance of ISA
*/

#include <ufio_crypto.h>

#if __has_cpp_attribute(__gnu__::__flatten__)
[[__gnu__::__flatten__]]
#endif
void sha512_invoker(::std::uint_least64_t *state, ::std::byte const *first, ::std::byte const *last) noexcept
{
	::ufio::details::sha512::sha512_runtime_routine(state, first, last);
}
