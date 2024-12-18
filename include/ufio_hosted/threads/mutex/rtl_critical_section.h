﻿#pragma once

namespace ufio
{

struct rtl_critical_section
{
	using native_handle_type = ::ufio::win32::nt::rtl_critical_section;
	native_handle_type critical_section;
	explicit rtl_critical_section() noexcept
	{
		::ufio::win32::nt::RtlInitializeCriticalSection(__builtin_addressof(critical_section));
	}
	rtl_critical_section(rtl_critical_section const &) = delete;
	rtl_critical_section &operator=(rtl_critical_section const &) = delete;
	void lock() noexcept
	{
		::ufio::win32::nt::RtlEnterCriticalSection(__builtin_addressof(critical_section));
	}
	bool try_lock() noexcept
	{
		return ::ufio::win32::nt::RtlTryEnterCriticalSection(__builtin_addressof(critical_section)) != 0;
	}
	void unlock() noexcept
	{
		::ufio::win32::nt::RtlLeaveCriticalSection(__builtin_addressof(critical_section));
	}
	~rtl_critical_section()
	{
		::ufio::win32::nt::RtlDeleteCriticalSection(__builtin_addressof(critical_section));
	}
};

} // namespace ufio