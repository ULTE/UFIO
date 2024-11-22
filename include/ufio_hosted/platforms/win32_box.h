#pragma once

#if defined(_MSC_VER) && !defined(_KERNEL_MODE)
#pragma comment(lib, "user32.lib")
#endif

namespace ufio
{

template <::ufio::win32_family family, ::std::integral ch_type>
struct basic_win32_family_box_t
{
	using char_type = ch_type;
	using output_char_type = char_type;
	using family_char_type = ::std::conditional_t<family == ::ufio::win32_family::ansi_9x, char8_t, char16_t>;
	family_char_type const *lpCaption{};
	::std::uint_least32_t uType{};
#if 0
//to do support wLanguageId
	::std::uint_least16_t wLanguageId{};
#endif
};

template <::std::integral char_type>
using basic_win32_box_9xa_t = basic_win32_family_box_t<::ufio::win32_family::ansi_9x, char_type>;
using win32_box_9xa_t = basic_win32_box_9xa_t<char>;
using wwin32_box_9xa_t = basic_win32_box_9xa_t<wchar_t>;
using u8win32_box_9xa_t = basic_win32_box_9xa_t<char8_t>;
using u16win32_box_9xa_t = basic_win32_box_9xa_t<char16_t>;
using u32win32_box_9xa_t = basic_win32_box_9xa_t<char32_t>;

template <::std::integral char_type>
using basic_win32_box_ntw_t = basic_win32_family_box_t<::ufio::win32_family::wide_nt, char_type>;
using win32_box_ntw_t = basic_win32_box_ntw_t<char>;
using wwin32_box_ntw_t = basic_win32_box_ntw_t<wchar_t>;
using u8win32_box_ntw_t = basic_win32_box_ntw_t<char8_t>;
using u16win32_box_ntw_t = basic_win32_box_ntw_t<char16_t>;
using u32win32_box_ntw_t = basic_win32_box_ntw_t<char32_t>;

template <::std::integral char_type>
using basic_win32_box_t = basic_win32_family_box_t<::ufio::win32_family::native, char_type>;
using win32_box_t = basic_win32_box_t<char>;
using wwin32_box_t = basic_win32_box_t<wchar_t>;
using u8win32_box_t = basic_win32_box_t<char8_t>;
using u16win32_box_t = basic_win32_box_t<char16_t>;
using u32win32_box_t = basic_win32_box_t<char32_t>;

namespace details
{

template <::ufio::win32_family family, ::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline void win32_box_converter_path_impl(char_type const *first, char_type const *last)
{
	win32_family_api_encoding_converter<family> converter(first, static_cast<::std::size_t>(last - first));
	win32_box_write_impl<family>(converter.buffer_data, converter.buffer_data_end);
}

template <::ufio::win32_family family, ::std::integral ch_type, ::std::integral write_ch_type>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline void win32_box_converter_scatter_path_impl(basic_win32_family_box_t<family, ch_type> bx,
												  basic_io_scatter_t<write_ch_type> const *scatters, ::std::size_t n)
{
	using chtypenocref = ::std::remove_cvref_t<write_ch_type>;
	if constexpr (family == ::ufio::win32_family::ansi_9x &&
				  ((!::std::same_as<chtypenocref, char8_t>) && sizeof(chtypenocref) == sizeof(char8_t) &&
				   ::ufio::execution_charset_encoding_scheme<chtypenocref>() == ::ufio::encoding_scheme::utf))
	{
		using scatter_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= basic_io_scatter_t<char8_t> const *;
		::ufio::details::win32_box_converter_scatter_path_impl(bx, reinterpret_cast<scatter_may_alias_ptr>(scatters), n);
	}
	else if constexpr (family == ::ufio::win32_family::wide_nt &&
					   ((!::std::same_as<chtypenocref, char16_t>) && sizeof(chtypenocref) == sizeof(char16_t) &&
						::ufio::execution_charset_encoding_scheme<chtypenocref>() ==
							::ufio::encoding_scheme::utf))
	{
		using scatter_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= basic_io_scatter_t<char16_t> const *;
		::ufio::details::win32_box_converter_scatter_path_impl(bx, reinterpret_cast<scatter_may_alias_ptr>(scatters), n);
	}
	else
	{
		if (n == 0)
		{
			return;
		}
		auto [totalsize, position] = ::ufio::find_scatter_total_size_overflow(scatters, n);
		if (totalsize == SIZE_MAX || position != n)
		{
			throw_win32_error(0x00000057);
		}
		::ufio::details::buffer_alloc_arr_ptr<chtypenocref, true> buffer(totalsize + 1u);
		chtypenocref *dest{buffer.ptr};
		for (auto i{scatters}, e{i + n}; i != e; ++i)
		{
			auto [scbs, sclen] = *i;
			dest = ::ufio::details::non_overlapped_copy_n(scbs, sclen, dest);
		}
		dest = ::ufio::freestanding::remove(buffer.ptr, dest, 0);
		if constexpr (family == ::ufio::win32_family::ansi_9x &&
					  (sizeof(chtypenocref) == sizeof(char8_t) &&
					   ::ufio::execution_charset_encoding_scheme<chtypenocref>() == ::ufio::encoding_scheme::utf))
		{
			*dest = 0;
			if (!::ufio::win32::MessageBoxA(nullptr, reinterpret_cast<char const *>(buffer.ptr),
											   reinterpret_cast<char const *>(bx.lpCaption), bx.uType))
			{
				throw_win32_error();
			}
		}
		else if constexpr (family == ::ufio::win32_family::wide_nt &&
						   (sizeof(chtypenocref) == sizeof(char16_t) &&
							::ufio::execution_charset_encoding_scheme<chtypenocref>() ==
								::ufio::encoding_scheme::utf))
		{
			*dest = 0;
			using char16_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
				[[__gnu__::__may_alias__]]
#endif
				= char16_t const *;
			if (!::ufio::win32::MessageBoxW(nullptr, reinterpret_cast<char16_may_alias_ptr>(buffer.ptr),
											   reinterpret_cast<char16_may_alias_ptr>(bx.lpCaption), bx.uType))
			{
				throw_win32_error();
			}
		}
		else
		{
			win32_family_api_encoding_converter<family> converter(buffer.ptr,
																  static_cast<::std::size_t>(dest - buffer.ptr));
			if constexpr (family == ::ufio::win32_family::ansi_9x)
			{
				if (!::ufio::win32::MessageBoxA(nullptr, reinterpret_cast<char const *>(converter.buffer_data),
												   reinterpret_cast<char const *>(bx.lpCaption), bx.uType))
				{
					throw_win32_error();
				}
			}
			else
			{
				using char16_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
					[[__gnu__::__may_alias__]]
#endif
					= char16_t const *;
				if (!::ufio::win32::MessageBoxW(nullptr,
												   reinterpret_cast<char16_may_alias_ptr>(converter.buffer_data),
												   reinterpret_cast<char16_may_alias_ptr>(bx.lpCaption), bx.uType))
				{
					throw_win32_error();
				}
			}
		}
	}
}

} // namespace details

template <::ufio::win32_family family, ::std::integral ch_type>
inline constexpr basic_win32_family_box_t<family, ch_type>
output_stream_ref_define(basic_win32_family_box_t<family, ch_type> other) noexcept
{
	return other;
}

template <::ufio::win32_family family, ::std::integral ch_type>
inline void scatter_write_all_overflow_define(basic_win32_family_box_t<family, ch_type> bx,
											  basic_io_scatter_t<ch_type> const *scatters, ::std::size_t n)
{
	::ufio::details::win32_box_converter_scatter_path_impl<family>(bx, scatters, n);
}

} // namespace ufio
