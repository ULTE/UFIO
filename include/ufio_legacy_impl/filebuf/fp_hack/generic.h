#pragma once

namespace ufio::details
{

template <typename char_type, typename traits_type>
inline FILE *fp_hack(::std::basic_filebuf<char_type, traits_type> *fbuf) noexcept
{
	return nullptr;
}

template <typename CharT, typename Traits>
#if __has_cpp_attribute(nodiscard)
[[nodiscard]]
#endif
inline ::std::basic_filebuf<CharT, Traits> *open_hacked_basic_filebuf(FILE *, ::ufio::open_mode)
{
	throw_posix_error(EINVAL);
}

} // namespace ufio::details
