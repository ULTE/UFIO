#pragma once

namespace ufio
{

struct win32_critical_section
{
	using native_handle_type = ::ufio::win32::nt::rtl_critical_section;
	native_handle_type critical_section;
	explicit win32_critical_section() noexcept
	{
		::ufio::win32::InitializeCriticalSection(__builtin_addressof(critical_section));
	}
	win32_critical_section(win32_critical_section const &) = delete;
	win32_critical_section &operator=(win32_critical_section const &) = delete;
	void lock() noexcept
	{
		::ufio::win32::EnterCriticalSection(__builtin_addressof(critical_section));
	}
	bool try_lock() noexcept
	{
		return ::ufio::win32::TryEnterCriticalSection(__builtin_addressof(critical_section)) != 0;
	}
	void unlock() noexcept
	{
		::ufio::win32::LeaveCriticalSection(__builtin_addressof(critical_section));
	}
	~win32_critical_section()
	{
		::ufio::win32::DeleteCriticalSection(__builtin_addressof(critical_section));
	}
};

} // namespace ufio