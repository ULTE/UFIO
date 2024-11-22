#pragma once

namespace ufio
{

namespace details
{
inline ::std::byte *posix_pread_bytes_impl(int fd, ::std::byte *first, ::std::byte *last, ::ufio::intfpos_t off);
inline ::std::byte const *posix_pwrite_bytes_impl(int fd, ::std::byte const *first, ::std::byte const *last,
												  ::ufio::intfpos_t off);
inline ::ufio::io_scatter_status_t posix_scatter_pread_bytes_impl(int fd, ::ufio::io_scatter_t const *pscatter,
																	 ::std::size_t n, ::ufio::intfpos_t off);
inline ::ufio::io_scatter_status_t posix_scatter_pwrite_bytes_impl(int fd, ::ufio::io_scatter_t const *pscatter,
																	  ::std::size_t n, ::ufio::intfpos_t off);

template <::ufio::c_family family>
inline ::std::byte *c_pread_bytes_impl(FILE *fp, ::std::byte *first, ::std::byte *last, ::ufio::intfpos_t off)
{
	return posix_pread_bytes_impl(::ufio::details::my_fileno_impl<family>(fp), first, last, off);
}

template <::ufio::c_family family>
inline ::std::byte const *c_pwrite_bytes_impl(FILE *fp, ::std::byte const *first, ::std::byte const *last,
											  ::ufio::intfpos_t off)
{
	return posix_pwrite_bytes_impl(::ufio::details::my_fileno_impl<family>(fp), first, last, off);
}

template <::ufio::c_family family>
inline ::ufio::io_scatter_status_t c_scatter_pread_bytes_impl(FILE *fp, ::ufio::io_scatter_t const *pscatter,
																 ::std::size_t n, ::ufio::intfpos_t off)
{
	return posix_scatter_pread_bytes_impl(::ufio::details::my_fileno_impl<family>(fp), pscatter, n, off);
}

template <::ufio::c_family family>
inline ::std::byte const *c_scatter_pwrite_bytes_impl(FILE *fp, ::ufio::io_scatter_t const *pscatter,
													  ::std::size_t n, ::ufio::intfpos_t off)
{
	return posix_scatter_pwrite_bytes_impl(::ufio::details::my_fileno_impl<family>(fp), pscatter, n, off);
}

} // namespace details

template <::ufio::c_family family, ::std::integral char_type>
	requires ::ufio::operations::decay::defines::has_pread_some_bytes_underflow_define<
		::ufio::basic_posix_io_observer<char_type>>
inline ::std::byte *pread_some_bytes_underflow_define(::ufio::basic_c_family_io_observer<family, char_type> piob,
													  ::std::byte *first, ::std::byte *last, ::ufio::intfpos_t off)
{
	return ::ufio::details::c_pread_bytes_impl<family>(piob.fp, first, last, off);
}

template <::ufio::c_family family, ::std::integral char_type>
	requires ::ufio::operations::decay::defines::has_pwrite_some_bytes_overflow_define<
		::ufio::basic_posix_io_observer<char_type>>
inline ::std::byte const *
pwrite_some_bytes_overflow_define(::ufio::basic_c_family_io_observer<family, char_type> piob,
								  ::std::byte const *first, ::std::byte const *last, ::ufio::intfpos_t off)
{
	return ::ufio::details::c_pwrite_bytes_impl<family>(piob.fp, first, last, off);
}

template <::ufio::c_family family, ::std::integral char_type>
	requires ::ufio::operations::decay::defines::has_scatter_pread_some_bytes_underflow_define<
		::ufio::basic_posix_io_observer<char_type>>
inline ::ufio::io_scatter_status_t
scatter_pread_some_bytes_underflow_define(::ufio::basic_c_family_io_observer<family, char_type> piob,
										  ::ufio::io_scatter_t const *pscatters, ::std::size_t n,
										  ::ufio::intfpos_t fpos)
{
	return ::ufio::details::c_scatter_pread_bytes_impl<family>(piob.fp, pscatters, n, fpos);
}

template <::ufio::c_family family, ::std::integral char_type>
	requires ::ufio::operations::decay::defines::has_scatter_pwrite_some_bytes_overflow_define<
		::ufio::basic_posix_io_observer<char_type>>
inline ::ufio::io_scatter_status_t
scatter_pwrite_some_bytes_overflow_define(::ufio::basic_c_family_io_observer<family, char_type> piob,
										  ::ufio::io_scatter_t const *pscatters, ::std::size_t n,
										  ::ufio::intfpos_t fpos)
{
	return ::ufio::details::c_scatter_pwrite_bytes_impl<family>(piob.fp, pscatters, n, fpos);
}

} // namespace ufio
