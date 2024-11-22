#pragma once

namespace ufio
{
enum class win9x_at_flags : ::std::uint_least32_t
{
	eaccess = static_cast<::std::uint_least32_t>(1),
	symlink_nofollow = static_cast<::std::uint_least32_t>(1) << 1,
	no_automount = static_cast<::std::uint_least32_t>(1) << 2,
	removedir = static_cast<::std::uint_least32_t>(1) << 3,
	empty_path = static_cast<::std::uint_least32_t>(1) << 4,
	nt_path = 0
};

constexpr win9x_at_flags operator&(win9x_at_flags x, win9x_at_flags y) noexcept
{
	using utype = typename ::std::underlying_type<win9x_at_flags>::type;
	return static_cast<win9x_at_flags>(static_cast<utype>(x) & static_cast<utype>(y));
}

constexpr win9x_at_flags operator|(win9x_at_flags x, win9x_at_flags y) noexcept
{
	using utype = typename ::std::underlying_type<win9x_at_flags>::type;
	return static_cast<win9x_at_flags>(static_cast<utype>(x) | static_cast<utype>(y));
}

constexpr win9x_at_flags operator^(win9x_at_flags x, win9x_at_flags y) noexcept
{
	using utype = typename ::std::underlying_type<win9x_at_flags>::type;
	return static_cast<win9x_at_flags>(static_cast<utype>(x) ^ static_cast<utype>(y));
}

constexpr win9x_at_flags operator~(win9x_at_flags x) noexcept
{
	using utype = typename ::std::underlying_type<win9x_at_flags>::type;
	return static_cast<win9x_at_flags>(~static_cast<utype>(x));
}

inline constexpr win9x_at_flags &operator&=(win9x_at_flags &x, win9x_at_flags y) noexcept
{
	return x = x & y;
}

inline constexpr win9x_at_flags &operator|=(win9x_at_flags &x, win9x_at_flags y) noexcept
{
	return x = x | y;
}

inline constexpr win9x_at_flags &operator^=(win9x_at_flags &x, win9x_at_flags y) noexcept
{
	return x = x ^ y;
}

namespace win32::details
{

::ufio::tlc::u8string concat_tlc_win9x_path_uncheck_whether_exist(::ufio::win9x_dir_handle const &dirhd, char8_t const *path_c_str, ::std::size_t path_size) noexcept
{
	auto const beg{path_c_str};
	auto curr{beg};

	if (auto const fc{*curr++}; fc == u8'+' ||
								fc == u8'-' ||
								fc == u8'.') [[unlikely]]
	{
		throw_win32_error(3221225530);
	}

	for (; curr != beg + path_size; ++curr)
	{
		auto fc{*curr};
		if (fc == u8'/' ||
			fc == u8'\\' ||
			fc == u8'\t' ||
			fc == u8'\b' ||
			fc == u8'@' ||
			fc == u8'#' ||
			fc == u8'$' ||
			fc == u8'%' ||
			fc == u8'^' ||
			fc == u8'&' ||
			fc == u8'*' ||
			fc == u8'(' ||
			fc == u8')' ||
			fc == u8'[' ||
			fc == u8']') [[unlikely]]
		{
			throw_win32_error(3221225530);
		}
	}

	return ::ufio::tlc::u8concat_ufio_tlc(::ufio::mnp::code_cvt(dirhd.path), u8"\\", ::ufio::mnp::os_c_str_with_known_size(beg, path_size));
}

inline void win9x_unlinkat_impl(::ufio::win9x_dir_handle const &dirhd, char8_t const *path_c_str, ::std::size_t path_size, win9x_at_flags flags)
{
	auto file_or_path{concat_tlc_win9x_path_uncheck_whether_exist(dirhd, path_c_str, path_size)};

	switch (flags)
	{
	case ::ufio::win9x_at_flags::removedir:
		if (!::ufio::win32::RemoveDirectoryA(reinterpret_cast<char const *>(file_or_path.c_str()))) [[unlikely]]
		{
			throw_win32_error();
		}
		break;
	default:
		if (!::ufio::win32::DeleteFileA(reinterpret_cast<char const *>(file_or_path.c_str()))) [[unlikely]]
		{
			throw_win32_error();
		}
		break;
	}
}

inline void win9x_mkdirat_impl(::ufio::win9x_dir_handle const &dirhd, char8_t const *path_c_str, ::std::size_t path_size, perms pm)
{
	auto path{concat_tlc_win9x_path_uncheck_whether_exist(dirhd, path_c_str, path_size)};

	if (!::ufio::win32::CreateDirectoryA(reinterpret_cast<char const *>(path.c_str()), nullptr)) [[unlikely]]
	{
		throw_win32_error();
	}

	auto const attr{::ufio::win32::GetFileAttributesA(reinterpret_cast<char const *>(path.c_str()))};

	if (attr == -1) [[unlikely]]
	{
		throw_win32_error(0x2);
	}

	if ((pm & perms::owner_write) == perms::none)
	{
		if (!::ufio::win32::SetFileAttributesA(reinterpret_cast<char const *>(path.c_str()), attr | 0x00000001)) [[unlikely]]
		{
			throw_win32_error();
		}
	}
	else
	{
		if (!::ufio::win32::SetFileAttributesA(reinterpret_cast<char const *>(path.c_str()), attr & ~static_cast<::std::uint_least32_t>(0x00000001))) [[unlikely]]
		{
			throw_win32_error();
		}
	}
}

inline void win9x_faccessat_impl(::ufio::win9x_dir_handle const &dirhd, char8_t const *path_c_str, ::std::size_t path_size, access_how mode)
{
	switch (mode)
	{
	case ::ufio::access_how::f_ok:
		[[fallthrough]];
	case ::ufio::access_how::x_ok:
		[[fallthrough]];
	case ::ufio::access_how::w_ok:
		[[fallthrough]];
	case ::ufio::access_how::r_ok:
		break;
	default:
		throw_win32_error(0x57);
	}

	auto path{concat_tlc_win9x_path_uncheck_whether_exist(dirhd, path_c_str, path_size)};

	auto const attr{::ufio::win32::GetFileAttributesA(reinterpret_cast<char const *>(path.c_str()))};

	if (attr == -1) [[unlikely]]
	{
		throw_win32_error(0x2);
	}

	switch (mode)
	{
	case ::ufio::access_how::f_ok:
		return;
	case ::ufio::access_how::x_ok:
		// Like mounted ntfs in wsl, all files and dirs are executable
		return;
	case ::ufio::access_how::w_ok:
	{
		if ((attr & 0x00000001) == 0x00000001) [[unlikely]]
		{
			throw_win32_error(0x57); // no access
		}
		return;
	}
	case ::ufio::access_how::r_ok:
		return;
	default:
		::ufio::unreachable();
	}
}

inline void win9x_fchmodat_impl(::ufio::win9x_dir_handle const &dirhd, char8_t const *path_c_str, ::std::size_t path_size, perms pm)
{
	auto path{concat_tlc_win9x_path_uncheck_whether_exist(dirhd, path_c_str, path_size)};

	auto const attr{::ufio::win32::GetFileAttributesA(reinterpret_cast<char const *>(path.c_str()))};

	if (attr == -1) [[unlikely]]
	{
		throw_win32_error(0x2);
	}

	if ((pm & perms::owner_write) == perms::none)
	{
		if (!::ufio::win32::SetFileAttributesA(reinterpret_cast<char const *>(path.c_str()), attr | 0x00000001))
		{
			throw_win32_error();
		}
	}
	else
	{
		if (!::ufio::win32::SetFileAttributesA(reinterpret_cast<char const *>(path.c_str()), attr & ~static_cast<::std::uint_least32_t>(0x00000001)))
		{
			throw_win32_error();
		}
	}
}

[[noreturn]] inline void win9x_fchownat_impl(::ufio::win9x_dir_handle const &dirhd, char8_t const *path_c_str, ::std::size_t path_size,
											 [[maybe_unused]] ::std::uintmax_t owner, [[maybe_unused]] ::std::uintmax_t group)
{
	auto path{concat_tlc_win9x_path_uncheck_whether_exist(dirhd, path_c_str, path_size)};

	auto const attr{::ufio::win32::GetFileAttributesA(reinterpret_cast<char const *>(path.c_str()))};

	if (attr == -1) [[unlikely]]
	{
		throw_win32_error(0x2);
	}

	// Windows does not use POSIX user group system. stub it and it is perfectly fine.
	// But nt_fchownat, zw_fchownat will not be provided since they do not exist.
	throw_win32_error(0x1);
}

inline constexpr auto calculate_win9x_onlyread_open_mode(bool write_attribute, bool fsymlink_nofollow) noexcept
{
	::ufio::details::win32_open_mode md;
	md.dwShareMode = 3;
	md.dwDesiredAccess = 0x40000000 | 0x80000000 | 0x0080;
	md.dwCreationDisposition = 3;

	if (write_attribute)
	{
		md.dwDesiredAccess |= 0x0100;
	}

	if (fsymlink_nofollow)
	{
		md.dwFlagsAndAttributes = 0x00200000;
	}
	return md;
}

inline posix_file_status win9x_fstatat_impl(::ufio::win9x_dir_handle const &dirhd, char8_t const *path_c_str, ::std::size_t path_size, win9x_at_flags flags)
{
	auto path{concat_tlc_win9x_path_uncheck_whether_exist(dirhd, path_c_str, path_size)};
	auto md{calculate_win9x_onlyread_open_mode(false, (flags & win9x_at_flags::symlink_nofollow) != win9x_at_flags::symlink_nofollow)};
	::ufio::win32_file_9xa f{::ufio::details::win32_family_create_file_internal_impl<win32_family::ansi_9x>(reinterpret_cast<char const *>(path.c_str()), md)};

	return ::ufio::win32::details::win32_status_impl(f.native_handle());
	
}

inline void win9x_utimensat_impl(::ufio::win9x_dir_handle const &dirhd, char8_t const *path_c_str, ::std::size_t path_size, unix_timestamp_option creation_time,
								 unix_timestamp_option last_access_time, unix_timestamp_option last_modification_time, win9x_at_flags flags)
{
	auto path{concat_tlc_win9x_path_uncheck_whether_exist(dirhd, path_c_str, path_size)};
	auto md{calculate_win9x_onlyread_open_mode(true, (flags & win9x_at_flags::symlink_nofollow) != win9x_at_flags::symlink_nofollow)};
	::ufio::win32_file_9xa f{::ufio::details::win32_family_create_file_internal_impl<win32_family::ansi_9x>(reinterpret_cast<char const *>(path.c_str()), md)};

	::ufio::win32::filetime ftm;
	::ufio::win32::GetSystemTimeAsFileTime(__builtin_addressof(ftm));

	::std::uint_least64_t current_time{(static_cast<::std::uint_least64_t>(ftm.dwHighDateTime) << 32) | ftm.dwLowDateTime};

	constexpr ::std::uint_least64_t mul_factor{::ufio::uint_least64_subseconds_per_second / 10000000ULL};
	
	::ufio::win32::filetime CreationTime;
	::ufio::win32::filetime *pCreationTime{__builtin_addressof(CreationTime)};
	::ufio::win32::filetime LastAccessTime;
	::ufio::win32::filetime *pLastAccessTime{__builtin_addressof(LastAccessTime)};
	::ufio::win32::filetime LastWriteTime;
	::ufio::win32::filetime *pLastWriteTime{__builtin_addressof(LastWriteTime)};

	switch (creation_time.flags)
	{
	case ::ufio::utime_flags::none:
	{
		auto const win32_time{static_cast<::ufio::win32_timestamp>(creation_time.timestamp)};
		CreationTime = ::ufio::win32::win32_timestamp_to_filetime(win32_time);
		break;
	}
	case ::ufio::utime_flags::now:
		CreationTime = ftm;
		break;
	case ::ufio::utime_flags::omit:
		pCreationTime = nullptr;
		break;
	default:
		throw_win32_error(0x57);
	}

	switch (last_access_time.flags)
	{
	case ::ufio::utime_flags::none:
	{
		auto const win32_time{static_cast<::ufio::win32_timestamp>(last_access_time.timestamp)};
		LastAccessTime = ::ufio::win32::win32_timestamp_to_filetime(win32_time);
		break;
	}
	case ::ufio::utime_flags::now:
		LastAccessTime = ftm;
		break;
	case ::ufio::utime_flags::omit:
		pLastAccessTime = nullptr;
		break;
	default:
		throw_win32_error(0x57);
	}

	switch (last_modification_time.flags)
	{
	case ::ufio::utime_flags::none:
	{
		auto const win32_time{static_cast<::ufio::win32_timestamp>(last_modification_time.timestamp)};
		LastWriteTime = ::ufio::win32::win32_timestamp_to_filetime(win32_time);
		break;
	}
	case ::ufio::utime_flags::now:
		LastWriteTime = ftm;
		break;
	case ::ufio::utime_flags::omit:
		pLastWriteTime = nullptr;
		break;
	default:
		throw_win32_error(0x57);
	}

	if (!::ufio::win32::SetFileTime(f.native_handle(), pCreationTime, pLastAccessTime, pLastWriteTime))
	{
		throw_win32_error();
	}
}

inline void win9x_symlinkat_impl(char8_t const *oldpath_c_str, ::std::size_t oldpath_size,
								 ::ufio::win9x_dir_handle const &newdirhd, char8_t const *newpath_c_str, ::std::size_t newpath_size)
{
	::ufio::u8cstring_view path{::ufio::containers::null_terminated, oldpath_c_str, oldpath_size};

	::ufio::u8win32_file_9xa f{::ufio::win32::details::basic_win9x_create_file_at_fs_dirent_impl(
		__builtin_addressof(newdirhd), reinterpret_cast<char const *>(newpath_c_str), newpath_size,
		{::ufio::open_mode::out | ::ufio::open_mode::excl, static_cast<perms>(436)})};

	char8_t buffer[510];
	::ufio::freestanding::my_memset(buffer, u8' ', 510);
	::ufio::u8obuffer_view u8obv{buffer, buffer + 510};

	::ufio::operations::print_freestanding<false>(u8obv, u8"!<symlink>", path, u8"\nThis is just a text to force symlink file to be 510 bytes long. Do not delete it nor spaces following it.");

	::ufio::operations::write_all(f, buffer, buffer + 510);
}

inline void win9x_linkat_impl(::ufio::win9x_dir_handle const &olddirhd, char8_t const *oldpath_c_str, ::std::size_t oldpath_size, 
	::ufio::win9x_dir_handle const &newdirhd, char8_t const *newpath_c_str, ::std::size_t newpath_size)
{
	auto oldpath{concat_tlc_win9x_path_uncheck_whether_exist(olddirhd, oldpath_c_str, oldpath_size)};
	auto newpath{concat_tlc_win9x_path_uncheck_whether_exist(newdirhd, newpath_c_str, newpath_size)};
	
	// Because of limitations of win9x, this function doesn't really link two files together. 
	// However, it simulates a real link by copying the file at exists to new.

	if (!::ufio::win32::CopyFileA(reinterpret_cast<char const *>(oldpath.c_str()), reinterpret_cast<char const *>(newpath.c_str()), 1))
	{
		throw_win32_error();
	}
}

inline void win9x_renameat_impl(::ufio::win9x_dir_handle const &olddirhd, char8_t const *oldpath_c_str, ::std::size_t oldpath_size,
								::ufio::win9x_dir_handle const &newdirhd, char8_t const *newpath_c_str, ::std::size_t newpath_size)
{
	auto oldpath{concat_tlc_win9x_path_uncheck_whether_exist(olddirhd, oldpath_c_str, oldpath_size)};
	auto newpath{concat_tlc_win9x_path_uncheck_whether_exist(newdirhd, newpath_c_str, newpath_size)};

	if (!::ufio::win32::MoveFileA(reinterpret_cast<char const *>(oldpath.c_str()), reinterpret_cast<char const *>(newpath.c_str())))
	{
		throw_win32_error();
	}
}

template <::ufio::details::posix_api_22 dsp, typename... Args>
inline auto win9x_22_api_dispatcher(::ufio::win9x_dir_handle const &olddirhd, char8_t const *oldpath_c_str, ::std::size_t oldpath_size,
									::ufio::win9x_dir_handle const &newdirhd, char8_t const *newpath_c_str, ::std::size_t newpath_size, Args... args)
{
	if constexpr (dsp == ::ufio::details::posix_api_22::renameat)
	{
		win9x_renameat_impl(olddirhd, oldpath_c_str, oldpath_size, newdirhd, newpath_c_str, newpath_size, args...);
	}
	else if constexpr (dsp == ::ufio::details::posix_api_22::linkat)
	{
		win9x_linkat_impl(olddirhd, oldpath_c_str, oldpath_size, newdirhd, newpath_c_str, newpath_size, args...);
	}
}

template <::ufio::details::posix_api_12 dsp, typename... Args>
inline auto win9x_12_api_dispatcher(char8_t const *oldpath_c_str, ::std::size_t oldpath_size,
									::ufio::win9x_dir_handle const &newdirhd, char8_t const *newpath_c_str, ::std::size_t newpath_size, Args... args)
{
	if constexpr (dsp == ::ufio::details::posix_api_12::symlinkat)
	{
		win9x_symlinkat_impl(oldpath_c_str, oldpath_size, newdirhd, newpath_c_str, newpath_size, args...);
	}
}

template <::ufio::details::posix_api_1x dsp, typename... Args>
inline auto win9x_1x_api_dispatcher(::ufio::win9x_dir_handle const &dir_handle, char8_t const *path_c_str, ::std::size_t path_size, Args... args)
{

	if constexpr (dsp == ::ufio::details::posix_api_1x::faccessat)
	{
		win9x_faccessat_impl(dir_handle, path_c_str, path_size, args...);
	}
	else if constexpr (dsp == ::ufio::details::posix_api_1x::fchmodat)
	{
		win9x_fchmodat_impl(dir_handle, path_c_str, path_size, args...);
	}
	else if constexpr (dsp == ::ufio::details::posix_api_1x::fchownat)
	{
		win9x_fchownat_impl(dir_handle, path_c_str, path_size, args...);
	}
	else if constexpr (dsp == ::ufio::details::posix_api_1x::fstatat)
	{
		return win9x_fstatat_impl(dir_handle, path_c_str, path_size, args...);
	}
	else if constexpr (dsp == ::ufio::details::posix_api_1x::mkdirat)
	{
		win9x_mkdirat_impl(dir_handle, path_c_str, path_size, args...);
	}
	else if constexpr (dsp == ::ufio::details::posix_api_1x::unlinkat)
	{
		win9x_unlinkat_impl(dir_handle, path_c_str, path_size, args...);
	}
	else if constexpr (dsp == ::ufio::details::posix_api_1x::utimensat)
	{
		win9x_utimensat_impl(dir_handle, path_c_str, path_size, args...);
	}
}

template <::ufio::details::posix_api_1x dsp, typename path_type, typename... Args>
inline auto win9x_deal_with1x(::ufio::win9x_dir_handle const &dir_handle, path_type const &path, Args... args)
{
	using char8_t_const_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= char8_t const *;

	return win32_api_common_9xa(
		path, [&](char const *path_c_str, ::std::size_t path_size) { return win9x_1x_api_dispatcher<dsp>(dir_handle, reinterpret_cast<char8_t_const_may_alias_ptr>(path_c_str), path_size, args...); });
}

template <::ufio::details::posix_api_12 dsp, ::ufio::constructible_to_os_c_str old_path_type,
		  ::ufio::constructible_to_os_c_str new_path_type, typename... Args>
inline auto win9x_deal_with12(old_path_type const &oldpath, ::ufio::win9x_dir_handle const &newdirfd, new_path_type const &newpath, Args... args)
{
	using char8_t_const_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= char8_t const *;

	return win32_api_common_9xa(
		oldpath,
		[&](char const *oldpath_c_str, ::std::size_t oldpath_size) {
			return win32_api_common_9xa(
				newpath, [&](char const *newpath_c_str, ::std::size_t newpath_size) { 
					return win9x_12_api_dispatcher<dsp>(reinterpret_cast<char8_t_const_may_alias_ptr>(oldpath_c_str), oldpath_size, newdirfd, reinterpret_cast<char8_t_const_may_alias_ptr>(newpath_c_str), newpath_size, args...); 
				});
		});
}

template <::ufio::details::posix_api_22 dsp, typename oldpath_type, typename newpath_type, typename... Args>
inline auto win9x_deal_with22(::ufio::win9x_dir_handle const &olddirhd, oldpath_type const &oldpath, ::ufio::win9x_dir_handle const &newdirhd, newpath_type const &newpath, Args... args)
{
	using char8_t_const_may_alias_ptr
#if __has_cpp_attribute(__gnu__::__may_alias__)
		[[__gnu__::__may_alias__]]
#endif
		= char8_t const *;

	return win32_api_common_9xa(oldpath,
								[&](char const *oldpath_c_str, ::std::size_t oldpath_size) {
									return win32_api_common_9xa(newpath,
																[&](char const *newpath_c_str, ::std::size_t newpath_size) {
																	return win9x_22_api_dispatcher<dsp>(olddirhd, reinterpret_cast<char8_t_const_may_alias_ptr>(oldpath_c_str), oldpath_size, newdirhd,
																										reinterpret_cast<char8_t_const_may_alias_ptr>(newpath_c_str), newpath_size, args...);
																});
								});
}

} // namespace win32::details

using native_at_flags = win9x_at_flags;

// 1x
template <::ufio::constructible_to_os_c_str path_type>
inline void win9x_unlinkat(::ufio::win9x_at_entry const &ent, path_type &&path, win9x_at_flags flags = {})
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::unlinkat>(ent.handle, path, flags);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void native_unlinkat(::ufio::win9x_at_entry const &ent, path_type &&path, win9x_at_flags flags = {})
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::unlinkat>(ent.handle, path, flags);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void win9x_mkdirat(::ufio::win9x_at_entry const &ent, path_type &&path, perms pm = static_cast<perms>(436), [[maybe_unused]] win9x_at_flags flags = {})
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::mkdirat>(ent.handle, path, pm);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void native_mkdirat(::ufio::win9x_at_entry const &ent, path_type &&path, perms pm = static_cast<perms>(436), [[maybe_unused]] win9x_at_flags flags = {})
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::mkdirat>(ent.handle, path, pm);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void win9x_faccessat(::ufio::win9x_at_entry const &ent, path_type const &path, access_how mode, [[maybe_unused]] win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::faccessat>(ent.handle, path, mode);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void native_faccessat(::ufio::win9x_at_entry const &ent, path_type const &path, access_how mode, [[maybe_unused]] win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::faccessat>(ent.handle, path, mode);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void win9x_fchmodat(::ufio::win9x_at_entry const &ent, path_type const &path, perms mode, [[maybe_unused]] win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::fchmodat>(ent.handle, path, mode);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void native_fchmodat(::ufio::win9x_at_entry const &ent, path_type const &path, perms mode, [[maybe_unused]] win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::fchmodat>(ent.handle, path, mode);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void win9x_fchownat(::ufio::win9x_at_entry const &ent, path_type const &path, ::std::uintmax_t owner, ::std::uintmax_t group, [[maybe_unused]] win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::fchownat>(ent.handle, path, owner, group);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void native_fchownat(::ufio::win9x_at_entry const &ent, path_type const &path, ::std::uintmax_t owner, ::std::uintmax_t group, [[maybe_unused]] win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::fchownat>(ent.handle, path, owner, group);
}

template <::ufio::constructible_to_os_c_str path_type>
inline posix_file_status win9x_fstatat(::ufio::win9x_at_entry const &ent, path_type const &path, win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	return ::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::fstatat>(ent.handle, path, flags);
}

template <::ufio::constructible_to_os_c_str path_type>
inline posix_file_status native_fstatat(::ufio::win9x_at_entry const &ent, path_type const &path, win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	return ::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::fstatat>(ent.handle, path, flags);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void win9x_utimensat(::ufio::win9x_at_entry const &ent, path_type const &path, unix_timestamp_option creation_time,
						 unix_timestamp_option last_access_time, unix_timestamp_option last_modification_time,
							win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::utimensat>(ent.handle, path, creation_time, last_access_time, last_modification_time, flags);
}

template <::ufio::constructible_to_os_c_str path_type>
inline void native_utimensat(::ufio::win9x_at_entry const &ent, path_type const &path, unix_timestamp_option creation_time,
							unix_timestamp_option last_access_time, unix_timestamp_option last_modification_time,
							win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	::ufio::win32::details::win9x_deal_with1x<details::posix_api_1x::utimensat>(ent.handle, path, creation_time, last_access_time, last_modification_time, flags);
}

// 12
template <::ufio::constructible_to_os_c_str old_path_type, ::ufio::constructible_to_os_c_str new_path_type>
inline void win9x_symlinkat(old_path_type &&oldpath, win9x_at_entry const &newdirfd, new_path_type &&newpath, [[maybe_unused]] win9x_at_flags flags = {})
{
	::ufio::win32::details::win9x_deal_with12<details::posix_api_12::symlinkat>(oldpath, newdirfd.handle, newpath);
}

template <::ufio::constructible_to_os_c_str old_path_type, ::ufio::constructible_to_os_c_str new_path_type>
inline void native_symlinkat(old_path_type &&oldpath, win9x_at_entry const &newdirfd, new_path_type &&newpath, [[maybe_unused]] win9x_at_flags flags = {})
{
	::ufio::win32::details::win9x_deal_with12<details::posix_api_12::symlinkat>(oldpath, newdirfd.handle, newpath);
}

// 22
template <::ufio::constructible_to_os_c_str old_path_type, ::ufio::constructible_to_os_c_str new_path_type>
inline void win9x_linkat(win9x_at_entry const &oldent, old_path_type &&oldpath, win9x_at_entry const &newent, new_path_type &&newpath, [[maybe_unused]] win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	::ufio::win32::details::win9x_deal_with22<::ufio::details::posix_api_22::linkat>(oldent.handle, oldpath, newent.handle, newpath);
}

template <::ufio::constructible_to_os_c_str old_path_type, ::ufio::constructible_to_os_c_str new_path_type>
inline void native_linkat(win9x_at_entry const &oldent, old_path_type &&oldpath, win9x_at_entry const &newent, new_path_type &&newpath, [[maybe_unused]] win9x_at_flags flags = win9x_at_flags::symlink_nofollow)
{
	::ufio::win32::details::win9x_deal_with22<::ufio::details::posix_api_22::linkat>(oldent.handle, oldpath, newent.handle, newpath);
}

template <::ufio::constructible_to_os_c_str old_path_type, ::ufio::constructible_to_os_c_str new_path_type>
inline void win9x_renameat(win9x_at_entry const &oldent, old_path_type &&oldpath, win9x_at_entry const &newent, new_path_type &&newpath, [[maybe_unused]] win9x_at_flags flags = {})
{
	::ufio::win32::details::win9x_deal_with22<::ufio::details::posix_api_22::renameat>(oldent.handle, oldpath, newent.handle, newpath);
}

template <::ufio::constructible_to_os_c_str old_path_type, ::ufio::constructible_to_os_c_str new_path_type>
inline void native_renameat(win9x_at_entry const &oldent, old_path_type &&oldpath, win9x_at_entry const &newent, new_path_type &&newpath, [[maybe_unused]] win9x_at_flags flags = {})
{
	::ufio::win32::details::win9x_deal_with22<::ufio::details::posix_api_22::renameat>(oldent.handle, oldpath, newent.handle, newpath);
}

} // namespace ufio
