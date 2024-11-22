#pragma once

namespace ufio
{

namespace details
{

template <::std::integral char_type, typename traits_type>
inline ::std::byte *filebuf_pread_bytes_impl(::std::basic_filebuf<char_type, traits_type> *fb, ::std::byte *first,
											 ::std::byte *last, ::ufio::intfpos_t off)
{
	return ::ufio::details::c_pread_bytes_impl<::ufio::c_family::native_unlocked>(
		::ufio::details::streambuf_hack::fp_hack(fb), first, last, off);
}

template <::std::integral char_type, typename traits_type>
inline ::std::byte const *filebuf_pwrite_bytes_impl(::std::basic_filebuf<char_type, traits_type> *fb,
													::std::byte const *first, ::std::byte const *last,
													::ufio::intfpos_t off)
{
	return ::ufio::details::c_pwrite_bytes_impl<::ufio::c_family::native_unlocked>(
		::ufio::details::streambuf_hack::fp_hack(fb), first, last, off);
}

template <::std::integral char_type, typename traits_type>
inline ::ufio::io_scatter_status_t filebuf_scatter_pread_bytes_impl(::std::basic_filebuf<char_type, traits_type> *fb,
																	   ::ufio::io_scatter_t const *pscatter,
																	   ::std::size_t n, ::ufio::intfpos_t off)
{
	return ::ufio::details::c_pwrite_bytes_impl<::ufio::c_family::native_unlocked>(
		::ufio::details::streambuf_hack::fp_hack(fb), pscatter, n, off);
}

template <::std::integral char_type, typename traits_type>
inline ::std::byte const *filebuf_scatter_pwrite_bytes_impl(::std::basic_filebuf<char_type, traits_type> *fb,
															::ufio::io_scatter_t const *pscatter, ::std::size_t n,
															::ufio::intfpos_t off)
{
	return ::ufio::details::c_pwrite_bytes_impl<::ufio::c_family::native_unlocked>(
		::ufio::details::streambuf_hack::fp_hack(fb), pscatter, n, off);
}

} // namespace details

template <::std::integral char_type, typename traits_type>
	requires ::ufio::operations::decay::defines::has_pread_some_bytes_underflow_define<
		::ufio::basic_c_io_observer_unlocked<char_type>>
inline ::std::byte *pread_some_bytes_underflow_define(::ufio::basic_filebuf_io_observer<char_type, traits_type> fiob,
													  ::std::byte *first, ::std::byte *last, ::ufio::intfpos_t off)
{
	return ::ufio::details::filebuf_pread_bytes_impl(fiob.fb, first, last, off);
}

template <::std::integral char_type, typename traits_type>
	requires ::ufio::operations::decay::defines::has_pwrite_some_bytes_overflow_define<
		::ufio::basic_c_io_observer_unlocked<char_type>>
inline ::std::byte const *
pwrite_some_bytes_overflow_define(::ufio::basic_filebuf_io_observer<char_type, traits_type> fiob,
								  ::std::byte const *first, ::std::byte const *last, ::ufio::intfpos_t off)
{
	return ::ufio::details::filebuf_pwrite_bytes_impl(fiob.fb, first, last, off);
}

template <::std::integral char_type, typename traits_type>
	requires ::ufio::operations::decay::defines::has_scatter_pread_some_bytes_underflow_define<
		::ufio::basic_c_io_observer_unlocked<char_type>>
inline ::ufio::io_scatter_status_t
scatter_pread_some_bytes_underflow_define(::ufio::basic_filebuf_io_observer<char_type, traits_type> fiob,
										  ::ufio::io_scatter_t const *pscatters, ::std::size_t n,
										  ::ufio::intfpos_t fpos)
{
	return ::ufio::details::filebuf_scatter_pread_bytes_impl(fiob.fb, pscatters, n, fpos);
}

template <::std::integral char_type, typename traits_type>
	requires ::ufio::operations::decay::defines::has_scatter_pwrite_some_bytes_overflow_define<
		::ufio::basic_c_io_observer_unlocked<char_type>>
inline ::ufio::io_scatter_status_t
scatter_pwrite_some_bytes_overflow_define(::ufio::basic_filebuf_io_observer<char_type, traits_type> fiob,
										  ::ufio::io_scatter_t const *pscatters, ::std::size_t n,
										  ::ufio::intfpos_t fpos)
{
	return ::ufio::details::filebuf_scatter_pwrite_bytes_impl(fiob.fb, pscatters, n, fpos);
}

} // namespace ufio
