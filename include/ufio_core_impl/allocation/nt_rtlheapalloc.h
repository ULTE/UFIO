﻿#pragma once

#include "../../ufio_hosted/platforms/nt/nt_preliminary_definition.h"

namespace ufio
{

namespace details
{

#if __has_cpp_attribute(__gnu__::__returns_nonnull__)
[[__gnu__::__returns_nonnull__]]
#endif
inline void *nt_rtlallocate_heap_handle_common_impl(void *heaphandle, ::std::size_t n, ::std::uint_least32_t flag) noexcept
{
	if (n == 0)
	{
		n = 1;
	}
	auto p{::ufio::win32::nt::RtlAllocateHeap(heaphandle, flag, n)};
	if (p == nullptr)
	{
		::ufio::fast_terminate();
	}
	return p;
}

#if __has_cpp_attribute(__gnu__::__returns_nonnull__)
[[__gnu__::__returns_nonnull__]]
#endif
inline void *nt_rtlreallocate_heap_handle_common_impl(void *heaphandle, void *addr, ::std::size_t n, ::std::uint_least32_t flag) noexcept
{
	if (n == 0)
	{
		n = 1;
	}
	if (addr == nullptr)
#if __has_cpp_attribute(unlikely)
		[[unlikely]]
#endif
	{
		return ::ufio::details::nt_rtlallocate_heap_handle_common_impl(heaphandle, n, flag);
	}
	auto p{::ufio::win32::nt::RtlReAllocateHeap(heaphandle, flag, addr, n)};
	if (p == nullptr)
	{
		::ufio::fast_terminate();
	}
	return p;
}

#if __has_cpp_attribute(__gnu__::__returns_nonnull__)
[[__gnu__::__returns_nonnull__]]
#endif
inline void *nt_rtlallocate_heap_common_impl(::std::size_t n, ::std::uint_least32_t flag) noexcept
{
	return ::ufio::details::nt_rtlallocate_heap_handle_common_impl(::ufio::win32::nt::rtl_get_process_heap(), n, flag);
}

#if __has_cpp_attribute(__gnu__::__returns_nonnull__)
[[__gnu__::__returns_nonnull__]]
#endif
inline void *nt_rtlreallocate_heap_common_impl(void *addr, ::std::size_t n, ::std::uint_least32_t flag) noexcept
{
	return ::ufio::details::nt_rtlreallocate_heap_handle_common_impl(::ufio::win32::nt::rtl_get_process_heap(), addr, n, flag);
}

inline ::ufio::allocation_least_result nt_rtlallocate_heap_least_common_impl(::std::size_t n, ::std::uint_least32_t flag) noexcept
{
	auto processheap{::ufio::win32::nt::rtl_get_process_heap()};
	auto ptr{::ufio::details::nt_rtlallocate_heap_handle_common_impl(processheap, n, flag)};
	return {ptr, ::ufio::win32::nt::RtlSizeHeap(processheap, 0, ptr)};
}

inline ::ufio::allocation_least_result nt_rtlreallocate_heap_least_common_impl(void *addr, ::std::size_t n, ::std::uint_least32_t flag) noexcept
{
	auto processheap{::ufio::win32::nt::rtl_get_process_heap()};
	auto ptr{::ufio::details::nt_rtlreallocate_heap_handle_common_impl(processheap, addr, n, flag)};
	return {ptr, ::ufio::win32::nt::RtlSizeHeap(processheap, 0, ptr)};
}

} // namespace details

class nt_rtlallocateheap_allocator
{
public:
#if __has_cpp_attribute(__gnu__::__malloc__)
	[[__gnu__::__malloc__]]
#endif
	static inline void *allocate(::std::size_t n) noexcept
	{
		return ::ufio::details::nt_rtlallocate_heap_common_impl(n, 0u);
	}
#if __has_cpp_attribute(__gnu__::__malloc__)
	[[__gnu__::__malloc__]]
#endif
	static inline void *allocate_zero(::std::size_t n) noexcept
	{
		return ::ufio::details::nt_rtlallocate_heap_common_impl(n, 0x00000008u);
	}
	static inline void *reallocate(void *addr, ::std::size_t n) noexcept
	{
		return ::ufio::details::nt_rtlreallocate_heap_common_impl(addr, n, 0u);
	}
	static inline void *reallocate_zero(void *addr, ::std::size_t n) noexcept
	{
		return ::ufio::details::nt_rtlreallocate_heap_common_impl(addr, n, 0x00000008u);
	}
	static inline void deallocate(void *addr) noexcept
	{
		if (addr == nullptr)
		{
			return;
		}
		::ufio::win32::nt::RtlFreeHeap(::ufio::win32::nt::rtl_get_process_heap(), 0u, addr);
	}
#if 0
	static inline ::ufio::allocation_least_result allocate_at_least(::std::size_t n) noexcept
	{
		return ::ufio::details::nt_rtlallocate_heap_least_common_impl(n, 0u);
	}
	static inline ::ufio::allocation_least_result allocate_zero_at_least(::std::size_t n) noexcept
	{
		return ::ufio::details::nt_rtlallocate_heap_least_common_impl(n, 0x00000008u);
	}
	static inline ::ufio::allocation_least_result reallocate_at_least(void *addr, ::std::size_t n) noexcept
	{
		return ::ufio::details::nt_rtlreallocate_heap_least_common_impl(addr, n, 0u);
	}
	static inline ::ufio::allocation_least_result reallocate_zero_at_least(void *addr, ::std::size_t n) noexcept
	{
		return ::ufio::details::nt_rtlreallocate_heap_least_common_impl(addr, n, 0x00000008u);
	}
#endif
};

} // namespace ufio