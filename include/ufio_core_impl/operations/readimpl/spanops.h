#pragma once


namespace ufio::operations
{

template <typename outstmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::containers::span<char_type> read_some_span(outstmtype &&outstm, ::ufio::containers::span<char_type> sp)
{
	auto first{sp.data()};
	auto last{first + sp.size()};
	return ::ufio::containers::span<char_type>(first, ::ufio::details::read_some_impl(::ufio::operations::input_stream_ref(outstm), first, last));
}

template <typename outstmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void read_all_span(outstmtype &&outstm, ::ufio::containers::span<char_type> sp)
{
	auto first{sp.data()};
	auto last{first + sp.size()};
	::ufio::details::read_some_impl(::ufio::operations::input_stream_ref(outstm), first, last);
}

template <typename outstmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::containers::span<::std::byte const> read_some_bytes_span(outstmtype &&outstm, ::ufio::containers::span<::std::byte const> sp)
{
	auto first{sp.data()};
	auto last{first + sp.size()};
	return ::ufio::containers::span<::std::byte const>(first, ::ufio::details::read_some_bytes_impl(::ufio::operations::input_stream_ref(outstm), first, last));
}

template <typename outstmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void read_all_bytes_span(outstmtype &&outstm, ::ufio::containers::span<::std::byte const> sp)
{
	auto first{sp.data()};
	auto last{first + sp.size()};
	::ufio::details::read_all_bytes_impl(::ufio::operations::input_stream_ref(outstm), first, last);
}

template <typename outstmtype>
inline constexpr io_scatter_status_t scatter_read_some_bytes_span(outstmtype &&outstm, ::ufio::containers::span<::ufio::io_scatter_t const> sp)
{
	using io_scatter_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= io_scatter_t const *;
	return ::ufio::details::scatter_read_some_bytes_impl(::ufio::operations::input_stream_ref(outstm),
															 reinterpret_cast<io_scatter_may_alias_const_ptr>(sp.data()),
															 sp.size());
}

template <typename outstmtype>
inline constexpr void scatter_read_all_bytes_span(outstmtype &&outstm, ::ufio::containers::span<::ufio::io_scatter_t const> sp)
{
	using io_scatter_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= io_scatter_t const *;
	::ufio::details::scatter_read_all_bytes_impl(::ufio::operations::input_stream_ref(outstm),
													 reinterpret_cast<io_scatter_may_alias_const_ptr>(sp.data()),
													 sp.size());
}

template <typename outstmtype>
inline constexpr io_scatter_status_t scatter_read_some_span(outstmtype &&outstm, ::ufio::containers::span<::ufio::basic_io_scatter_t<typename decltype(::ufio::operations::input_stream_ref(outstm))::input_char_type> const> sp)
{
	using io_scatter_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= basic_io_scatter_t<typename decltype(::ufio::operations::input_stream_ref(outstm))::input_char_type> const *;
	return ::ufio::details::scatter_read_some_impl(::ufio::operations::input_stream_ref(outstm),
													   reinterpret_cast<io_scatter_may_alias_const_ptr>(sp.data()),
													   sp.size());
}

template <typename outstmtype>
inline constexpr void scatter_read_all_span(outstmtype &&outstm, ::ufio::containers::span<::ufio::basic_io_scatter_t<typename decltype(::ufio::operations::input_stream_ref(outstm))::input_char_type> const> sp)
{
	using io_scatter_may_alias_const_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= basic_io_scatter_t<typename decltype(::ufio::operations::input_stream_ref(outstm))::input_char_type> const *;
	::ufio::details::scatter_read_all_impl(::ufio::operations::input_stream_ref(outstm),
											   reinterpret_cast<io_scatter_may_alias_const_ptr>(sp.data()),
											   sp.size());
}

template <typename outstmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::containers::span<char_type> pread_some_span(outstmtype &&outstm, ::ufio::containers::span<char_type> sp, ::ufio::intfpos_t off)
{
	auto first{sp.data()};
	auto last{first + sp.size()};
	return ::ufio::containers::span<char_type>(first, ::ufio::details::pread_some_impl(::ufio::operations::input_stream_ref(outstm), first, last, off));
}

template <typename outstmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void pread_all_span(outstmtype &&outstm, ::ufio::containers::span<char_type> sp, ::ufio::intfpos_t off)
{
	auto first{sp.data()};
	auto last{first + sp.size()};
	::ufio::details::pread_all_impl(::ufio::operations::input_stream_ref(outstm), first, last, off);
}

template <typename outstmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr ::ufio::containers::span<::std::byte const> pread_some_bytes_span(outstmtype &&outstm, ::ufio::containers::span<::std::byte const> sp, ::ufio::intfpos_t off)
{
	auto first{sp.data()};
	auto last{first + sp.size()};
	return ::ufio::containers::span<::std::byte const>(first, ::ufio::details::pread_some_bytes_impl(::ufio::operations::input_stream_ref(outstm), first, last, off));
}

template <typename outstmtype, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__always_inline__)
[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
[[msvc::forceinline]]
#endif
inline constexpr void pread_all_bytes_span(outstmtype &&outstm, ::ufio::containers::span<::std::byte const> sp, ::ufio::intfpos_t off)
{
	auto first{sp.data()};
	auto last{first + sp.size()};
	::ufio::details::pread_all_bytes_impl(::ufio::operations::input_stream_ref(outstm), first, last, off);
}

template <typename outstmtype>
inline constexpr io_scatter_status_t scatter_pread_some_bytes_span(outstmtype &&outstm, ::ufio::containers::span<::ufio::io_scatter_t const> sp, ::ufio::intfpos_t off)
{

	return ::ufio::details::scatter_pread_some_bytes_impl(::ufio::operations::input_stream_ref(outstm),
															  sp.data(), sp.size(), off);
}

template <typename outstmtype>
inline constexpr void scatter_pread_all_bytes_span(outstmtype &&outstm, ::ufio::containers::span<::ufio::io_scatter_t const> sp, ::ufio::intfpos_t off)
{
	::ufio::details::scatter_pread_all_bytes_impl(::ufio::operations::input_stream_ref(outstm),
													  sp.data(), sp.size(), off);
}

template <typename outstmtype>
inline constexpr io_scatter_status_t scatter_pread_some_span(outstmtype &&outstm, ::ufio::containers::span<::ufio::basic_io_scatter_t<typename decltype(::ufio::operations::input_stream_ref(outstm))::input_char_type> const> sp, ::ufio::intfpos_t off)
{
	return ::ufio::details::scatter_pread_some_impl(::ufio::operations::input_stream_ref(outstm),
														sp.data(), sp.size(), off);
}

template <typename outstmtype>
inline constexpr void scatter_pread_all_span(outstmtype &&outstm, ::ufio::containers::span<::ufio::basic_io_scatter_t<typename decltype(::ufio::operations::input_stream_ref(outstm))::input_char_type> const> sp, ::ufio::intfpos_t off)
{

	::ufio::details::scatter_pread_all_impl(::ufio::operations::input_stream_ref(outstm), sp.data(), sp.size(), off);
}

} // namespace ufio::operations
