#pragma once

namespace ufio
{

namespace operations
{

template <typename instmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr char_type *read_some(instmtype &&instm, char_type *first, char_type *last)
{
	return ::ufio::details::read_some_impl(::ufio::operations::input_stream_ref(instm), first, last);
}

template <typename instmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void read_all(instmtype &&instm, char_type *first, char_type *last)
{
	return ::ufio::details::read_all_impl(::ufio::operations::input_stream_ref(instm), first, last);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::std::byte *read_some_bytes(instmtype &&instm, ::std::byte *first, ::std::byte *last)
{
	return ::ufio::details::read_some_bytes_impl(::ufio::operations::input_stream_ref(instm), first, last);
}
template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void read_all_bytes(instmtype &&instm, ::std::byte *first, ::std::byte *last)
{
	return ::ufio::details::read_all_bytes_impl(::ufio::operations::input_stream_ref(instm), first, last);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr io_scatter_status_t scatter_read_some_bytes(instmtype &&instm, io_scatter_t const* pscatter,
															 ::std::size_t len)
{
	return ::ufio::details::scatter_read_some_bytes_impl(::ufio::operations::input_stream_ref(instm), pscatter,
															len);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void scatter_read_all_bytes(instmtype &&instm, io_scatter_t const* pscatter, ::std::size_t len)
{
	::ufio::details::scatter_read_all_bytes_impl(::ufio::operations::input_stream_ref(instm), pscatter, len);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr io_scatter_status_t scatter_read_some(
	instmtype &&instm,
	basic_io_scatter_t<typename decltype(::ufio::operations::input_stream_ref(instm))::input_char_type> const
		*pscatter,
	::std::size_t len)
{
	return ::ufio::details::scatter_read_some_impl(::ufio::operations::input_stream_ref(instm), pscatter, len);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void scatter_read_all(
	instmtype &&instm,
	basic_io_scatter_t<typename decltype(::ufio::operations::input_stream_ref(instm))::input_char_type> const
		*pscatter,
	::std::size_t len)
{
	return ::ufio::details::scatter_read_all_impl(::ufio::operations::input_stream_ref(instm), pscatter, len);
}

template <typename instmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr char_type *pread_some(instmtype &&instm, char_type *first, char_type *last, ::ufio::intfpos_t off)
{
	return ::ufio::details::pread_some_impl(::ufio::operations::input_stream_ref(instm), first, last, off);
}

template <typename instmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void pread_all(instmtype &&instm, char_type *first, char_type *last, ::ufio::intfpos_t off)
{
	return ::ufio::details::pread_all_impl(::ufio::operations::input_stream_ref(instm), first, last, off);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::std::byte *pread_some_bytes(instmtype &&instm, ::std::byte *first, ::std::byte *last,
											   ::ufio::intfpos_t off)
{
	return ::ufio::details::pread_some_bytes_impl(::ufio::operations::input_stream_ref(instm), first, last, off);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void pread_all_bytes(instmtype &&instm, ::std::byte *first, ::std::byte *last,
									  ::ufio::intfpos_t off)
{
	return ::ufio::details::pread_all_bytes_impl(::ufio::operations::input_stream_ref(instm), first, last, off);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr io_scatter_status_t scatter_pread_some_bytes(instmtype &&instm, io_scatter_t const* pscatter,
															  ::std::size_t len, ::ufio::intfpos_t off)
{
	return ::ufio::details::scatter_pread_some_bytes_impl(::ufio::operations::input_stream_ref(instm), pscatter,
															 len, off);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void scatter_pread_all_bytes(instmtype &&instm, io_scatter_t const* pscatter, ::std::size_t len,
											  ::ufio::intfpos_t off)
{
	::ufio::details::scatter_pread_all_bytes_impl(::ufio::operations::input_stream_ref(instm), pscatter, len,
													 off);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr io_scatter_status_t scatter_pread_some(
	instmtype &&instm,
	basic_io_scatter_t<typename decltype(::ufio::operations::input_stream_ref(instm))::input_char_type> const
		*pscatter,
	::std::size_t len, ::ufio::intfpos_t off)
{
	return ::ufio::details::scatter_pread_some_impl(::ufio::operations::input_stream_ref(instm), pscatter, len,
													   off);
}

template <typename instmtype>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void scatter_pread_all(
	instmtype &&instm,
	basic_io_scatter_t<typename decltype(::ufio::operations::input_stream_ref(instm))::input_char_type> const
		*pscatter,
	::std::size_t len, ::ufio::intfpos_t off)
{
	return ::ufio::details::scatter_pread_all_impl(::ufio::operations::input_stream_ref(instm), pscatter, len,
													  off);
}

} // namespace operations

} // namespace ufio
