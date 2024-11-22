#pragma once

namespace ufio
{
namespace details
{
inline ::ufio::intfpos_t posix_seek_impl(int fd, ::ufio::intfpos_t offset, seekdir s)
{
#if defined(__MSDOS__)
	if constexpr (sizeof(off_t) < sizeof(::ufio::intfpos_t))
	{
		if (offset < static_cast<::ufio::intfpos_t>(::std::numeric_limits<off_t>::min()) ||
			offset > static_cast<::ufio::intfpos_t>(::std::numeric_limits<off_t>::max()))
		{
			throw_posix_error(EINVAL);
		}
	}
	auto ret{noexcept_call(::lseek, fd, static_cast<off_t>(offset), static_cast<int>(s))};
	if (ret == -1)
	{
		throw_posix_error();
	}
	return static_cast<::ufio::intfpos_t>(static_cast<my_make_unsigned_t<off_t>>(ret));
#elif defined(__linux__)
#if defined(__NR_llseek)
	if constexpr (sizeof(off_t) <= sizeof(::std::int_least32_t))
	{
		::std::uint_least64_t result{};
		::std::uint_least64_t offset64_val{
			static_cast<::std::uint_least64_t>(static_cast<::ufio::intfpos_t>(offset))};
		auto ret{system_call<__NR_llseek, int>(fd, static_cast<::std::uint_least32_t>(offset >> 32u),
											   static_cast<::std::uint_least32_t>(offset), __builtin_addressof(result),
											   static_cast<int>(s))};
		system_call_throw_error(ret);
		return static_cast<::ufio::intfpos_t>(static_cast<::std::uint_least64_t>(result));
	}
	else
#endif
	{
		if constexpr (sizeof(off_t) <= sizeof(::std::int_least32_t))
		{
			if (offset < static_cast<::ufio::intfpos_t>(::std::numeric_limits<off_t>::min()) ||
				offset > static_cast<::ufio::intfpos_t>(::std::numeric_limits<off_t>::max()))
			{
				throw_posix_error(EOVERFLOW);
			}
		}
		auto ret{system_call<__NR_lseek, ::std::ptrdiff_t>(fd, offset, static_cast<int>(s))};
		system_call_throw_error(ret);
		return static_cast<::ufio::intfpos_t>(static_cast<::std::uint_least64_t>(ret));
	}
#else
	if constexpr (sizeof(off_t) <= sizeof(::std::int_least32_t))
	{
		if (offset < static_cast<::ufio::intfpos_t>(::std::numeric_limits<off_t>::min()) ||
			offset > static_cast<::ufio::intfpos_t>(::std::numeric_limits<off_t>::max()))
		{
			throw_posix_error(EOVERFLOW);
		}
	}
	auto ret(
#if (defined(_WIN32) && !defined(__WINE__) && !defined(__BIONIC__)) && !defined(__CYGWIN__)
		::_lseeki64
#else
		::lseek
#endif
		(fd, static_cast<off_t>(offset), static_cast<int>(s)));
	system_call_throw_error(ret);
	return static_cast<::ufio::intfpos_t>(static_cast<::std::uint_least64_t>(ret));
#endif
}
} // namespace details

template <::ufio::posix_family family, ::std::integral char_type>
inline ::ufio::intfpos_t io_stream_seek_bytes_define(::ufio::basic_posix_family_io_observer<family, char_type> bpiob,
														::ufio::intfpos_t off, ::ufio::seekdir sdir)
{
	return ::ufio::details::posix_seek_impl(bpiob.fd, off, sdir);
}

} // namespace ufio
