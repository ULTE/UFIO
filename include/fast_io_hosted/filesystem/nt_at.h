﻿#pragma once

namespace fast_io
{

enum class nt_at_flags : ::std::uint_least32_t
{
	eaccess = static_cast<::std::uint_least32_t>(1),
	symlink_nofollow = static_cast<::std::uint_least32_t>(1) << 1,
	no_automount = static_cast<::std::uint_least32_t>(1) << 2,
	removedir = static_cast<::std::uint_least32_t>(1) << 3,
	empty_path = static_cast<::std::uint_least32_t>(1) << 4
};

constexpr nt_at_flags operator&(nt_at_flags x, nt_at_flags y) noexcept
{
	using utype = typename ::std::underlying_type<nt_at_flags>::type;
	return static_cast<nt_at_flags>(static_cast<utype>(x) & static_cast<utype>(y));
}

constexpr nt_at_flags operator|(nt_at_flags x, nt_at_flags y) noexcept
{
	using utype = typename ::std::underlying_type<nt_at_flags>::type;
	return static_cast<nt_at_flags>(static_cast<utype>(x) | static_cast<utype>(y));
}

constexpr nt_at_flags operator^(nt_at_flags x, nt_at_flags y) noexcept
{
	using utype = typename ::std::underlying_type<nt_at_flags>::type;
	return static_cast<nt_at_flags>(static_cast<utype>(x) ^ static_cast<utype>(y));
}

constexpr nt_at_flags operator~(nt_at_flags x) noexcept
{
	using utype = typename ::std::underlying_type<nt_at_flags>::type;
	return static_cast<nt_at_flags>(~static_cast<utype>(x));
}

inline constexpr nt_at_flags &operator&=(nt_at_flags &x, nt_at_flags y) noexcept
{
	return x = x & y;
}

inline constexpr nt_at_flags &operator|=(nt_at_flags &x, nt_at_flags y) noexcept
{
	return x = x | y;
}

inline constexpr nt_at_flags &operator^=(nt_at_flags &x, nt_at_flags y) noexcept
{
	return x = x ^ y;
}

namespace win32::nt::details
{

inline constexpr nt_open_mode calculate_nt_delete_flag(nt_at_flags flags) noexcept
{
	nt_open_mode mode{
		.DesiredAccess = 0x00010000,     // FILE_GENERIC_READ
		.FileAttributes = 0x80,          // FILE_ATTRIBUTE_NORMAL
		.ShareAccess = 0x00000007,       // FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE
		.CreateDisposition = 0x00000001, /*OPEN_EXISTING	=>	FILE_OPEN*/
		.CreateOptions = 0x00001000      /*FILE_DELETE_ON_CLOSE*/
	};
	if ((flags & nt_at_flags::symlink_nofollow) != nt_at_flags::symlink_nofollow)
	{
		mode.CreateOptions |= 0x00200000; // FILE_FLAG_OPEN_REPARSE_POINT => FILE_OPEN_REPARSE_POINT (0x00200000)
	}
	if ((flags & nt_at_flags::removedir) == nt_at_flags::removedir)
	{
		mode.CreateOptions |= 0x00004000; // FILE_OPEN_FOR_BACKUP_INTENT
		mode.CreateOptions |= 0x00000001; // FILE_DIRECTORY_FILE
	}
	else
	{
		mode.CreateOptions |= 0x00000040; // FILE_NON_DIRECTORY_FILE 0x00000040
	}
	return mode;
}

template <bool zw>
inline void nt_unlinkat_impl(void *dirhd, char16_t const *path_c_str, ::std::size_t path_size, nt_at_flags flags)
{
	auto status{nt_close<zw>(
		nt_call_callback(dirhd, path_c_str, path_size, nt_create_callback<zw>{calculate_nt_delete_flag(flags)}))};
	if (status)
	{
		throw_nt_error(status);
	}
}

template <bool zw>
inline void nt_mkdirat_impl(void *dirhd, char16_t const *path_c_str, ::std::size_t path_size, perms pm)
{
	constexpr fast_io::win32::nt::details::nt_open_mode create_dir_mode{
		fast_io::win32::nt::details::calculate_nt_open_mode(
			{fast_io::open_mode::creat | fast_io::open_mode::directory})};
	auto m_dir_mode{create_dir_mode};
	if ((pm & perms::owner_write) == perms::none)
	{
		m_dir_mode.FileAttributes |= 0x00000001; // FILE_ATTRIBUTE_READONLY
	}
	auto status{nt_close<zw>(nt_call_callback(dirhd, path_c_str, path_size, nt_create_callback<zw>{m_dir_mode}))};
	if (status)
	{
		throw_nt_error(status);
	}
}

struct nt_create_file_nothrow_common_return_t
{
	void *handle;
	::std::uint_least32_t status;
};

template <bool zw>
inline nt_create_file_nothrow_common_return_t nt_create_file_nothrow_common(void *directory, ::fast_io::win32::nt::unicode_string *relative_path, nt_open_mode const &mode) noexcept
{
	::fast_io::win32::security_attributes sec_attr{sizeof(::fast_io::win32::security_attributes), nullptr, true};
	::fast_io::win32::nt::object_attributes obj{.Length = sizeof(::fast_io::win32::nt::object_attributes),
												.RootDirectory = directory,
												.ObjectName = relative_path,
												.Attributes = mode.ObjAttributes,
												.SecurityDescriptor =
													mode.ObjAttributes & 0x00000002 ? __builtin_addressof(sec_attr) : nullptr,
												.SecurityQualityOfService = nullptr};
	void *handle;
	::fast_io::win32::nt::io_status_block block;
	auto const status{::fast_io::win32::nt::nt_create_file<zw>(
		__builtin_addressof(handle), mode.DesiredAccess, __builtin_addressof(obj), __builtin_addressof(block), nullptr,
		mode.FileAttributes, mode.ShareAccess, mode.CreateDisposition, mode.CreateOptions, nullptr, 0u)};
	return {handle, status};
}

template <bool zw>
struct nt_create_nothrow_callback
{
	nt_open_mode const &mode;
#if __has_cpp_attribute(__gnu__::__always_inline__)
	[[__gnu__::__always_inline__]]
#elif __has_cpp_attribute(msvc::forceinline)
	[[msvc::forceinline]]
#endif
	auto operator()(void *directory_handle, ::fast_io::win32::nt::unicode_string *relative_path) const
	{
		return nt_create_file_nothrow_common<zw>(directory_handle, relative_path, mode); // get rid of this pointer
	}
};
template <bool zw>
inline void nt_symlinkat_impl(char16_t const *oldpath_c_str, ::std::size_t oldpath_size,
							  void *newdirhd, char16_t const *newpath_c_str, ::std::size_t newpath_size)
{
	bool const is_root{oldpath_c_str[0] == u'\\' ||
					   (oldpath_size > 1 && ::fast_io::char_category::is_c_upper(oldpath_c_str[0]) && oldpath_c_str[1] == u':')};

	constexpr nt_open_mode md{
		.DesiredAccess = 0x00100000 | 0x0080, // SYNCHRONIZE | FILE_READ_ATTRIBUTES
		.FileAttributes = 0x80,               // FILE_ATTRIBUTE_NORMAL
		.ShareAccess = 0x00000007,            // FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE
		.CreateDisposition = 0x00000001,      // OPEN_EXISTING => FILE_OPEN
	};

	void *olddirhd{newdirhd};
	if (is_root)
	{
		olddirhd = reinterpret_cast<void *>(::std::ptrdiff_t(-3));
	}

	auto [handle, status]{nt_call_callback(olddirhd, oldpath_c_str, oldpath_size, nt_create_nothrow_callback<zw>{md})};
	
	::fast_io::basic_nt_family_file<zw ? nt_family::zw : nt_family::nt, char> check_file{};

	if (status)
	{
		if (status != 0xC0000034) [[unlikely]]
		{
			throw_nt_error(status);
		}
	}
	else
	{
		check_file.handle = handle;
	}

	// use nt path in root
	char16_t const *oldpath_real_c_str{oldpath_c_str};
	::std::size_t oldpath_real_size{oldpath_size};
	::fast_io::win32::nt::unicode_string us{};
	if (is_root)
	{
		if (::fast_io::win32::nt::rtl_dos_path_name_to_nt_path_name_u(oldpath_real_c_str, &us, nullptr, nullptr)) [[likely]]
		{
			oldpath_real_c_str = us.Buffer;
			oldpath_real_size = us.Length / 2;
		}
	}

	// Check if exists to set the file type
	::fast_io::win32::nt::io_status_block isb;
	::std::uint_least32_t attribute{};
	if (!status)
	{

		::fast_io::win32::nt::file_basic_information fbi;
		status = ::fast_io::win32::nt::nt_query_information_file<zw>(handle, __builtin_addressof(isb), __builtin_addressof(fbi),
																	 static_cast<::std::uint_least32_t>(sizeof(fbi)),
																	 ::fast_io::win32::nt::file_information_class::FileBasicInformation);
		if (status) [[unlikely]]
		{
			throw_nt_error(status);
		}

		check_file.close();

		attribute = fbi.FileAttributes;
	}

	nt_open_mode symbol_mode{
		.DesiredAccess = 0x00100000 | 0x0100 | 0x00010000, // SYNCHRONIZE | FILE_WRITE_ATTRIBUTES | DELETE
		.FileAttributes = 0x80,                            // FILE_ATTRIBUTE_NORMAL
		.ShareAccess = 0x00000007,                         // FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE
		.CreateDisposition = 0x00000002,                   // FILE_OVERWRITE_IF
		.CreateOptions = 0x00000020 | 0x00200000           // FILE_SYNCHRONOUS_IO_NONALERT | FILE_OPEN_REPARSE_POINT
	};

	if (status == 0xC0000034) // file not exit
	{
		symbol_mode.CreateOptions |= 0x00000040; // file
	}
	else
	{
		if ((attribute & 0x10) == 0x10)
		{
			symbol_mode.CreateOptions |= 0x00000001; // directory
		}
		else
		{
			symbol_mode.CreateOptions |= 0x00000040; // file
		}
	}
	constexpr ::std::size_t pathbufferoffset{
		__builtin_offsetof(reparse_data_buffer, SymbolicLinkReparseBuffer.PathBuffer)};
	::std::size_t const cbReparseData{pathbufferoffset + oldpath_real_size * sizeof(char16_t) * 2};

	using reparse_data_buffer_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= reparse_data_buffer *;

	::fast_io::details::local_operator_new_array_ptr<char> buffer(cbReparseData);

	reparse_data_buffer_may_alias_ptr pReparseData{reinterpret_cast<reparse_data_buffer_may_alias_ptr>(buffer.get())};

	auto pBufTail{reinterpret_cast<char16_t *>(pReparseData->SymbolicLinkReparseBuffer.PathBuffer)};

	pReparseData->ReparseTag = 0xA000000CL; // IO_REPARSE_TAG_SYMLINK
	constexpr ::std::size_t reparsebufferoffset{__builtin_offsetof(reparse_data_buffer, GenericReparseBuffer)};
	pReparseData->ReparseDataLength = static_cast<::std::uint_least16_t>(cbReparseData - reparsebufferoffset);
	pReparseData->Reserved = 0;

	pReparseData->SymbolicLinkReparseBuffer.SubstituteNameOffset = 0;
	pReparseData->SymbolicLinkReparseBuffer.SubstituteNameLength = oldpath_real_size * sizeof(char16_t);
	::fast_io::freestanding::non_overlapped_copy_n(oldpath_real_c_str, oldpath_real_size, pBufTail);

	pReparseData->SymbolicLinkReparseBuffer.PrintNameOffset = oldpath_real_size * sizeof(char16_t);
	pReparseData->SymbolicLinkReparseBuffer.PrintNameLength = oldpath_real_size * sizeof(char16_t);
	pBufTail += oldpath_real_size;
	::fast_io::freestanding::non_overlapped_copy_n(oldpath_real_c_str, oldpath_real_size, pBufTail);

	// Check whether it is the root directory: nt[0] == u'\\', is_c_upper(win32[0]) && (win32[1] == u':')
	pReparseData->SymbolicLinkReparseBuffer.Flags =
		static_cast<::std::uint_least32_t>(!is_root);

	::fast_io::basic_nt_family_file<zw ? nt_family::zw : nt_family::nt, char> new_file(
		nt_call_callback(newdirhd, newpath_c_str, newpath_size, nt_create_callback<zw>{symbol_mode}));

	status = ::fast_io::win32::nt::nt_fs_control_file<zw>(
		new_file.native_handle(),
		nullptr,
		nullptr,
		nullptr,
		__builtin_addressof(isb),
		589988,
		pReparseData,
		cbReparseData,
		nullptr,
		0);

	if (status) [[unlikely]]
	{
		::fast_io::win32::nt::file_disposition_information DispInfo{1};
		::fast_io::win32::nt::nt_set_information_file<zw>(new_file.native_handle(), __builtin_addressof(isb), __builtin_addressof(DispInfo),
														  sizeof(DispInfo), ::fast_io::win32::nt::file_information_class::FileDispositionInformation);
		throw_nt_error(status);
	}
}

template <bool zw>
inline void nt_renameat_impl(void *olddirhd, char16_t const *oldpath_c_str, ::std::size_t oldpath_size,
							 void *newdirhd, char16_t const *newpath_c_str, ::std::size_t newpath_size)
{
	constexpr nt_open_mode md{
		.DesiredAccess = 0x00100000 | 0x0080 | 0x00010000, // SYNCHRONIZE | FILE_READ_ATTRIBUTES | DELETE
		.FileAttributes = 0x80,                            // FILE_ATTRIBUTE_NORMAL
		.ShareAccess = 0x00000007,                         // FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE
		.CreateDisposition = 0x00000001,                   // OPEN_EXISTING => FILE_OPEN
	};

	::fast_io::basic_nt_family_file<zw ? nt_family::zw : nt_family::nt, char> file(
		nt_call_callback(olddirhd, oldpath_c_str, oldpath_size, nt_create_callback<zw>{md}));

	nt_call_callback(
		newdirhd, newpath_c_str, newpath_size,
		[&](void *directory_hd, win32::nt::unicode_string const *ustr) {
			char16_t const *pth_cstr{ustr->Buffer};
			::std::uint_least32_t pth_size2{ustr->Length};
			::fast_io::details::local_operator_new_array_ptr<char> buffer(sizeof(::fast_io::win32::nt::file_rename_information) + pth_size2 + sizeof(char16_t));

			using file_rename_information_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
				[[__gnu__::__may_alias__]]
#endif
				= file_rename_information *;

			::fast_io::win32::nt::file_rename_information *info{reinterpret_cast<file_rename_information_may_alias_ptr>(buffer.get())};
			info->ReplaceIfExists = 1;
			info->RootDirectory = directory_hd;
			info->FileNameLength = pth_size2;
			::fast_io::freestanding::my_memcpy(info->FileName, pth_cstr, pth_size2 + sizeof(char16_t));

			::fast_io::win32::nt::io_status_block block;
			::std::uint_least32_t status{::fast_io::win32::nt::nt_set_information_file<zw>(
				file.handle, __builtin_addressof(block), info,
				static_cast<::std::uint_least32_t>(sizeof(::fast_io::win32::nt::file_rename_information) + pth_size2 + sizeof(char16_t)), file_information_class::FileRenameInformation)};
			if (status) [[unlikely]]
			{
				throw_nt_error(status);
			}
		});
}

inline constexpr nt_open_mode calculate_nt_link_flag(nt_at_flags flags) noexcept
{
	nt_open_mode mode{
		.DesiredAccess = 0x00100000 | 0x0080, // SYNCHRONIZE | FILE_WRITE_ATTRIBUTES | FILE_READ_ATTRIBUTES
		.FileAttributes = 0x80,               // FILE_ATTRIBUTE_NORMAL
		.ShareAccess = 0x00000007,            // FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE
		.CreateDisposition = 0x00000001,      /*OPEN_EXISTING	=>	FILE_OPEN*/
	};
	if ((flags & nt_at_flags::symlink_nofollow) != nt_at_flags::symlink_nofollow)
	{
		mode.CreateOptions |= 0x00200000; // FILE_FLAG_OPEN_REPARSE_POINT => FILE_OPEN_REPARSE_POINT (0x00200000)
	}
	return mode;
}

template <bool zw>
inline void nt_linkat_impl(void *olddirhd, char16_t const *oldpath_c_str, ::std::size_t oldpath_size, void *newdirhd,
						   char16_t const *newpath_c_str, ::std::size_t newpath_size, nt_at_flags flags)
{
	nt_open_mode const md{calculate_nt_link_flag(flags)};
	::fast_io::basic_nt_family_file<zw ? nt_family::zw : nt_family::nt, char> basic_file{};
	::fast_io::basic_nt_family_io_observer<zw ? nt_family::zw : nt_family::nt, char> file{};

	if ((flags & nt_at_flags::empty_path) == nt_at_flags::empty_path && oldpath_size == 0)
	{
		file = ::fast_io::basic_nt_family_io_observer<zw ? nt_family::zw : nt_family::nt, char>{olddirhd};
	}
	else
	{
		basic_file = ::fast_io::basic_nt_family_file<zw ? nt_family::zw : nt_family::nt, char>{nt_call_callback(olddirhd, oldpath_c_str, oldpath_size, nt_create_callback<zw>{md})};
		file = basic_file;
	}

	nt_call_callback(
		newdirhd, newpath_c_str, newpath_size,
		[&](void *directory_hd, win32::nt::unicode_string const *ustr) {
			char16_t const *pth_cstr{ustr->Buffer};
			::std::uint_least32_t pth_size2{ustr->Length};
			::fast_io::details::local_operator_new_array_ptr<char> buffer(sizeof(::fast_io::win32::nt::file_link_information) + pth_size2 + sizeof(char16_t));

			using file_link_information_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
				[[__gnu__::__may_alias__]]
#endif
				= file_link_information *;

			::fast_io::win32::nt::file_link_information *info{reinterpret_cast<file_link_information_may_alias_ptr>(buffer.get())};
			info->ReplaceIfExists = 0;
			info->RootDirectory = directory_hd;
			info->FileNameLength = pth_size2;

			::fast_io::freestanding::my_memcpy(info->FileName, pth_cstr, pth_size2 + sizeof(char16_t));

			::fast_io::win32::nt::io_status_block block;

			::std::uint_least32_t status{::fast_io::win32::nt::nt_set_information_file<zw>(
				file.handle, __builtin_addressof(block), info,
				static_cast<::std::uint_least32_t>(sizeof(::fast_io::win32::nt::file_link_information) + pth_size2 + sizeof(char16_t)), file_information_class::FileLinkInformation)};

			if (status) [[unlikely]]
			{
				throw_nt_error(status);
			}
		});
}

template <bool zw, ::fast_io::details::posix_api_22 dsp, typename... Args>
inline auto nt22_api_dispatcher(void *olddirhd, char16_t const *oldpath_c_str, ::std::size_t oldpath_size,
								void *newdirhd, char16_t const *newpath_c_str, ::std::size_t newpath_size, Args... args)
{
	if constexpr (dsp == ::fast_io::details::posix_api_22::renameat)
	{
		nt_renameat_impl<zw>(olddirhd, oldpath_c_str, oldpath_size, newdirhd, newpath_c_str, newpath_size, args...);
	}
	else if constexpr (dsp == ::fast_io::details::posix_api_22::linkat)
	{
		nt_linkat_impl<zw>(olddirhd, oldpath_c_str, oldpath_size, newdirhd, newpath_c_str, newpath_size, args...);
	}
}

template <bool zw, ::fast_io::details::posix_api_12 dsp, typename... Args>
inline auto nt12_api_dispatcher(char16_t const *oldpath_c_str, ::std::size_t oldpath_size,
								void *newdirhd, char16_t const *newpath_c_str, ::std::size_t newpath_size)
{
	if constexpr (dsp == ::fast_io::details::posix_api_12::symlinkat)
	{
		nt_symlinkat_impl<zw>(oldpath_c_str, oldpath_size, newdirhd, newpath_c_str, newpath_size);
	}
}

template <bool zw, ::fast_io::details::posix_api_1x dsp, typename... Args>
inline auto nt1x_api_dispatcher(void *dir_handle, char16_t const *path_c_str, ::std::size_t path_size, Args... args)
{
#if 0
	if constexpr(dsp==::fast_io::details::posix_api_1x::faccessat)
		nt_faccessat_impl<zw>(dir_handle,path_c_str,path_size,args...);
	else if constexpr(dsp==::fast_io::details::posix_api_1x::fchmodat)
		nt_fchmodat_impl<zw>(dir_handle,path_c_str,path_size,args...);
	else if constexpr(dsp==::fast_io::details::posix_api_1x::fstatat)
		nt_fstatat_impl<zw>(dir_handle,path_c_str,path_size,args...);
	else
#endif
	if constexpr (dsp == ::fast_io::details::posix_api_1x::mkdirat)
	{
		nt_mkdirat_impl<zw>(dir_handle, path_c_str, path_size, args...);
	}
	else if constexpr (dsp == ::fast_io::details::posix_api_1x::unlinkat)
	{
		nt_unlinkat_impl<zw>(dir_handle, path_c_str, path_size, args...);
	}
#if 0
	else if constexpr(dsp==::fast_io::details::posix_api_1x::unlinkat::utimensat)
		nt_utimensat_impl<zw>(dir_handle,path_c_str,path_size,args...);
#endif
}

template <nt_family family, ::fast_io::details::posix_api_1x dsp, typename path_type, typename... Args>
inline auto nt_deal_with1x(void *dir_handle, path_type const &path, Args... args)
{
	return nt_api_common(
		path, [&](char16_t const *path_c_str, ::std::size_t path_size) { return nt1x_api_dispatcher < family == nt_family::zw, dsp > (dir_handle, path_c_str, path_size, args...); });
}

template <nt_family family, ::fast_io::details::posix_api_12 dsp, ::fast_io::constructible_to_os_c_str old_path_type,
		  ::fast_io::constructible_to_os_c_str new_path_type>
inline auto nt_deal_with12(old_path_type const &oldpath, void *newdirfd, new_path_type const &newpath)
{
	return nt_api_common(
		oldpath,
		[&](char16_t const *oldpath_c_str, ::std::size_t oldpath_size) {
			return nt_api_common(
				newpath, [&](char16_t const *newpath_c_str, ::std::size_t newpath_size) { return nt12_api_dispatcher < family == nt_family::zw, dsp > (oldpath_c_str, oldpath_size, newdirfd, newpath_c_str, newpath_size); });
		});
}

template <nt_family family, ::fast_io::details::posix_api_22 dsp, typename oldpath_type, typename newpath_type, typename... Args>
inline auto nt_deal_with22(void *olddirhd, oldpath_type const &oldpath, void *newdirhd, newpath_type const &newpath, Args... args)
{
	return nt_api_common(oldpath,
						 [&](char16_t const *oldpath_c_str, ::std::size_t oldpath_size) {
							 return nt_api_common(newpath,
												  [&](char16_t const *newpath_c_str, ::std::size_t newpath_size) {
													  return nt22_api_dispatcher < family == nt_family::zw, dsp > (olddirhd, oldpath_c_str, oldpath_size, newdirhd,
																												   newpath_c_str, newpath_size, args...);
												  });
						 });
}

} // namespace win32::nt::details

// 1x
template <nt_family family, ::fast_io::constructible_to_os_c_str path_type>
	requires(family == nt_family::nt || family == nt_family::zw)
inline void nt_family_mkdirat(nt_at_entry ent, path_type &&path, perms pm = static_cast<perms>(436))
{
	::fast_io::win32::nt::details::nt_deal_with1x<family, details::posix_api_1x::mkdirat>(ent.handle, path, pm);
}

template <::fast_io::constructible_to_os_c_str path_type>
inline void nt_mkdirat(nt_at_entry ent, path_type &&path, perms pm = static_cast<perms>(436))
{
	::fast_io::win32::nt::details::nt_deal_with1x<nt_family::nt, details::posix_api_1x::mkdirat>(ent.handle, path, pm);
}

template <::fast_io::constructible_to_os_c_str path_type>
inline void zw_mkdirat(nt_at_entry ent, path_type &&path, perms pm = static_cast<perms>(436))
{
	::fast_io::win32::nt::details::nt_deal_with1x<nt_family::zw, details::posix_api_1x::mkdirat>(ent.handle, path, pm);
}

template <nt_family family, ::fast_io::constructible_to_os_c_str path_type>
	requires(family == nt_family::nt || family == nt_family::zw)
inline void nt_family_unlinkat(nt_at_entry ent, path_type &&path, nt_at_flags flags = {})
{
	::fast_io::win32::nt::details::nt_deal_with1x<family, details::posix_api_1x::unlinkat>(ent.handle, path, flags);
}

template <::fast_io::constructible_to_os_c_str path_type>
inline void nt_unlinkat(nt_at_entry ent, path_type &&path, nt_at_flags flags = {})
{
	::fast_io::win32::nt::details::nt_deal_with1x<nt_family::nt, details::posix_api_1x::unlinkat>(ent.handle, path,
																								  flags);
}

template <::fast_io::constructible_to_os_c_str path_type>
inline void zw_unlinkat(nt_at_entry ent, path_type &&path, nt_at_flags flags = {})
{
	::fast_io::win32::nt::details::nt_deal_with1x<nt_family::zw, details::posix_api_1x::unlinkat>(ent.handle, path,
																								  flags);
}

// 12
template <nt_family family, ::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
	requires(family == nt_family::nt || family == nt_family::zw)
inline void nt_family_symlinkat(old_path_type &&oldpath, nt_at_entry newdirfd, new_path_type &&newpath)
{
	::fast_io::win32::nt::details::nt_deal_with12<family, details::posix_api_12::symlinkat>(oldpath, newdirfd.handle, newpath);
}

template <::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void nt_symlinkat(old_path_type &&oldpath, nt_at_entry newdirfd, new_path_type &&newpath)
{
	::fast_io::win32::nt::details::nt_deal_with12<nt_family::nt, details::posix_api_12::symlinkat>(oldpath, newdirfd.handle, newpath);
}

template <::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void zw_symlinkat(old_path_type &&oldpath, nt_at_entry newdirfd, new_path_type &&newpath)
{
	::fast_io::win32::nt::details::nt_deal_with12<nt_family::zw, details::posix_api_12::symlinkat>(oldpath, newdirfd.handle, newpath);
}

// 22
template <nt_family family, ::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void nt_family_renameat(native_at_entry oldent, old_path_type &&oldpath, native_at_entry newent, new_path_type &&newpath)
{
	::fast_io::win32::nt::details::nt_deal_with22<family, ::fast_io::details::posix_api_22::renameat>(oldent.handle, oldpath,
																									  newent.handle, newpath);
}

template <::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void nt_renameat(native_at_entry oldent, old_path_type &&oldpath, native_at_entry newent, new_path_type &&newpath)
{
	::fast_io::win32::nt::details::nt_deal_with22<nt_family::nt, ::fast_io::details::posix_api_22::renameat>(oldent.handle, oldpath,
																											 newent.handle, newpath);
}

template <::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void zw_renameat(native_at_entry oldent, old_path_type &&oldpath, native_at_entry newent, new_path_type &&newpath)
{
	::fast_io::win32::nt::details::nt_deal_with22<nt_family::zw, ::fast_io::details::posix_api_22::renameat>(oldent.handle, oldpath,
																											 newent.handle, newpath);
}

template <nt_family family, ::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void nt_family_linkat(native_at_entry oldent, old_path_type &&oldpath, native_at_entry newent, new_path_type &&newpath, nt_at_flags flags = nt_at_flags::symlink_nofollow)
{
	::fast_io::win32::nt::details::nt_deal_with22<family, ::fast_io::details::posix_api_22::linkat>(oldent.handle, oldpath,
																									newent.handle, newpath, flags);
}

template <::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void nt_linkat(native_at_entry oldent, old_path_type &&oldpath, native_at_entry newent, new_path_type &&newpath, nt_at_flags flags = nt_at_flags::symlink_nofollow)
{
	::fast_io::win32::nt::details::nt_deal_with22<nt_family::nt, ::fast_io::details::posix_api_22::linkat>(oldent.handle, oldpath,
																										   newent.handle, newpath, flags);
}

template <::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void zw_linkat(native_at_entry oldent, old_path_type &&oldpath, native_at_entry newent, new_path_type &&newpath, nt_at_flags flags = nt_at_flags::symlink_nofollow)
{
	::fast_io::win32::nt::details::nt_deal_with22<nt_family::zw, ::fast_io::details::posix_api_22::linkat>(oldent.handle, oldpath,
																										   newent.handle, newpath, flags);
}

#if !defined(__CYGWIN__) && !defined(__WINE__)
using native_at_flags = nt_at_flags;

template <::fast_io::constructible_to_os_c_str path_type>
inline void native_mkdirat(nt_at_entry ent, path_type &&path, perms pm = static_cast<perms>(436))
{
	::fast_io::win32::nt::details::nt_deal_with1x<nt_family::nt, details::posix_api_1x::mkdirat>(ent.handle, path, pm);
}

template <::fast_io::constructible_to_os_c_str path_type>
inline void native_unlinkat(nt_at_entry ent, path_type &&path, native_at_flags flags = {})
{
	::fast_io::win32::nt::details::nt_deal_with1x<nt_family::nt, ::fast_io::details::posix_api_1x::unlinkat>(
		ent.handle, path, flags);
}

template <::fast_io::constructible_to_os_c_str path_type>
inline void native_fchownat(nt_at_entry, path_type &&, ::std::size_t, ::std::size_t,
							[[maybe_unused]] nt_at_flags flags = nt_at_flags::symlink_nofollow)
{
	// windows does not use POSIX user group system. stub it and it is perfectly fine. But nt_fchownat, zw_fchownat will
	// not be provided since they do not exist.
}

template <::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void native_symlinkat(old_path_type &&oldpath, nt_at_entry newdirfd, new_path_type &&newpath)
{
	::fast_io::win32::nt::details::nt_deal_with12<nt_family::nt, details::posix_api_12::symlinkat>(oldpath, newdirfd.handle, newpath);
}

template <::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void native_renameat(native_at_entry oldent, old_path_type &&oldpath, native_at_entry newent, new_path_type &&newpath)
{
	::fast_io::win32::nt::details::nt_deal_with22<nt_family::nt, ::fast_io::details::posix_api_22::renameat>(oldent.handle, oldpath,
																											 newent.handle, newpath);
}

template <::fast_io::constructible_to_os_c_str old_path_type, ::fast_io::constructible_to_os_c_str new_path_type>
inline void native_linkat(native_at_entry oldent, old_path_type &&oldpath, native_at_entry newent, new_path_type &&newpath, nt_at_flags flags = nt_at_flags::symlink_nofollow)
{
	::fast_io::win32::nt::details::nt_deal_with22<nt_family::nt, ::fast_io::details::posix_api_22::linkat>(oldent.handle, oldpath,
																										   newent.handle, newpath, flags);
}
#endif
} // namespace fast_io
