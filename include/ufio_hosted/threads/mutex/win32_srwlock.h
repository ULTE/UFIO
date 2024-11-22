#pragma once
/*
Referenced from
https://learn.microsoft.com/en-us/archive/msdn-magazine/2012/november/windows-with-c-the-evolution-of-synchronization-in-windows-and-c
*/
namespace ufio
{

struct win32_srwlock
{
	using native_handle_type = ::ufio::win32::nt::rtl_srwlock;
	native_handle_type h{.Ptr = nullptr};
	explicit constexpr win32_srwlock() noexcept = default;
	win32_srwlock(win32_srwlock const &) = delete;
	win32_srwlock &operator=(win32_srwlock const &) = delete;
	void lock() noexcept
	{
		::ufio::win32::AcquireSRWLockExclusive(__builtin_addressof(h));
	}
	bool try_lock() noexcept
	{
		return ::ufio::win32::TryAcquireSRWLockExclusive(__builtin_addressof(h)) != 0;
	}
	void unlock() noexcept
	{
		::ufio::win32::ReleaseSRWLockExclusive(__builtin_addressof(h));
	}
};

} // namespace ufio