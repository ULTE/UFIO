﻿#pragma once

namespace ufio
{

namespace win32
{
#if __has_cpp_attribute(__gnu__::__const__)
[[__gnu__::__const__]]
#endif
inline FILE *wincrt_acrt_iob_func(::std::uint_least32_t index) noexcept
{
#if defined(_MSC_VER) || defined(_UCRT)
	return noexcept_call(__acrt_iob_func, index);
#else
	return ::ufio::win32::wincrt_iob_func() + index;
#endif
}
} // namespace win32

namespace details
{
/*
the entire stdio on windows is too broken. I want to add tie semantics to stdin and stdout to avoid troubles.
*/

struct
#if __has_cpp_attribute(__gnu__::__may_alias__)
	[[__gnu__::__may_alias__]]
#endif
	crt_iobuf
{
	char *_ptr;
#if defined(_MSC_VER) || defined(_UCRT)
	// We only supported msvc with above C++20 support so it is always ucrt
	char *_base;
	::std::int_least32_t _cnt;
#else
	::std::int_least32_t _cnt;
	char *_base;
#endif
	::std::uint_least32_t _flag;
	::std::int_least32_t _file;
	::std::int_least32_t _charbuf;
	::std::int_least32_t _bufsiz;
	char *_tmpfname;
};

inline constexpr ::std::size_t wincrt_internal_buffer_size{4096};

inline constexpr ::std::uint_least32_t crt_dirty_value{0x0002};

inline constexpr ::std::uint_least32_t crt_mybuf_value{
#if defined(_MSC_VER) || defined(_UCRT)
	0x0040
#else
	0x0008
#endif
};

template <typename fileptr>
inline constexpr bool wincrt_fp_is_dirty_impl(fileptr *__restrict fp) noexcept
{
	return (static_cast<::std::uint_least32_t>(fp->_flag) & crt_dirty_value) == crt_dirty_value;
}

inline constexpr ::std::int_least32_t crt_block_flag{
#if defined(_CRT_BLOCK)
	_CRT_BLOCK
#else
	2 /*_CRT_BLOCK*/
#endif
};

inline void *my_malloc_crt(::std::size_t buffer_size) noexcept
{
	auto ptr{
#if defined(_DEBUG) && defined(_MSC_VER)

		/*
		https://docs.microsoft.com/en-us/visualstudio/debugger/crt-debug-heap-details
		_NORMAL_BLOCK A call to malloc or calloc creates a Normal block. If you intend to use Normal blocks only, and
		have no need for Client blocks, you may want to define _CRTDBG_MAP_ALLOC, which causes all heap allocation calls
		to be mapped to their debug equivalents in Debug builds. This will allow file name and line number information
		about each allocation call to be stored in the corresponding block header.

		_CRT_BLOCK The memory blocks allocated internally by many run-time library functions are marked as CRT blocks so
		they can be handled separately. As a result, leak detection and other operations need not be affected by them.
		An allocation must never allocate, reallocate, or free any block of CRT type.

		_CLIENT_BLOCK An application can keep special track of a given group of allocations for debugging purposes by
		allocating them as this type of memory block, using explicit calls to the debug heap functions. MFC, for
		example, allocates all CObjects as Client blocks; other applications might keep different memory objects in
		Client blocks. Subtypes of Client blocks can also be specified for greater tracking granularity. To specify
		subtypes of Client blocks, shift the number left by 16 bits and OR it with _CLIENT_BLOCK. For example:

		*/
		::ufio::noexcept_call(_malloc_dbg, buffer_size, crt_block_flag, __FILE__, __LINE__)
// Provide Debugging information to this file so if people find out issues with hacking they can report to ufio
// project
#else
/*
https://github.com/mirror/mingw-w64/blob/master/mingw-w64-headers/crt/crtdbg.h
CRT heap debugging does not exist on mingw-w64
*/
#if defined(__has_builtin)
#if __has_builtin(__builtin_malloc)
		__builtin_malloc(buffer_size)
#else
		malloc(buffer_size)
#endif
#else
		malloc(buffer_size)
#endif
#endif
	};
	// handling allocation failure is a historical mistake and it never happens on windows. Just let it crash.
	if (ptr == nullptr) [[unlikely]]
	{
		fast_terminate();
	}
	return ptr;
}

inline void wincrt_fp_allocate_buffer_impl(FILE *__restrict fpp) noexcept
{
	crt_iobuf *fp{reinterpret_cast<crt_iobuf *>(fpp)};
	if (fp->_bufsiz < 4)
	{
		fp->_bufsiz = wincrt_internal_buffer_size;
	}
	fp->_bufsiz >>= 2;
	fp->_bufsiz <<= 2;
	::std::size_t allocated_buffer_size{static_cast<::std::size_t>(static_cast<::std::uint_least32_t>(fp->_bufsiz))};
	auto new_buffer{my_malloc_crt(allocated_buffer_size)};
	fp->_ptr = fp->_base = reinterpret_cast<char *>(new_buffer);
	fp->_cnt = 0;
	fp->_flag |= crt_mybuf_value;
}

#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline void wincrt_fp_write_cold_malloc_case_impl(FILE *__restrict fpp, char const *__restrict first,
												  ::std::size_t diff)
{
	crt_iobuf *fp{reinterpret_cast<crt_iobuf *>(fpp)};
	if (diff == 0)
	{
		return;
	}
	::std::size_t allocated_buffer_size{wincrt_internal_buffer_size};
	if (fp->_bufsiz >= 4)
	{
		allocated_buffer_size = static_cast<::std::size_t>(static_cast<::std::uint_least32_t>(fp->_bufsiz));
		allocated_buffer_size >>= 2;
		allocated_buffer_size <<= 2;
	}
	if (diff >= allocated_buffer_size)
	{
#if 0
		posix_write_nolock_impl(static_cast<::std::int_least32_t>(fp->_file),first,diff);
#else
		::ufio::posix_io_observer piob{static_cast<::std::int_least32_t>(fp->_file)};
		::ufio::operations::decay::write_all_decay(piob, first, first + diff);
#endif
		return;
	}
	auto newbuffer{my_malloc_crt(allocated_buffer_size)};
	my_memcpy(newbuffer, first, diff);
	fp->_ptr = (fp->_base = reinterpret_cast<char *>(newbuffer)) + diff;
	fp->_flag |= crt_mybuf_value;
	fp->_bufsiz = static_cast<::std::int_least32_t>(allocated_buffer_size);
	fp->_cnt = fp->_bufsiz - static_cast<::std::int_least32_t>(diff);
	fp->_flag |= crt_dirty_value;
}

inline void wincrt_fp_write_cold_normal_case_impl(FILE *__restrict fpp, char const *__restrict first,
												  ::std::size_t diff)
{
	crt_iobuf *fp{reinterpret_cast<crt_iobuf *>(fpp)};
	::std::size_t remain{static_cast<::std::size_t>(static_cast<::std::uint_least32_t>(fp->_cnt))};
	non_overlapped_copy_n(first, remain, fp->_ptr);
	diff -= remain;
	first += remain;
	fp->_ptr += remain;
	fp->_cnt = 0;
	fp->_flag |= crt_dirty_value;
	::ufio::posix_io_observer piob{static_cast<::std::int_least32_t>(fp->_file)};
#if 0
	posix_write_simple_impl(static_cast<::std::int_least32_t>(fp->_file),fp->_base,static_cast<::std::size_t>(fp->_ptr-fp->_base));
#else
	::ufio::operations::decay::write_all_decay(piob, fp->_base, fp->_ptr);
#endif
	::std::size_t const bufsiz{static_cast<::std::size_t>(static_cast<::std::uint_least32_t>(fp->_bufsiz))};
	if (diff >= bufsiz)
	{
#if 0
		posix_write_nolock_impl(static_cast<::std::int_least32_t>(fp->_file),first,diff);
#else
		::ufio::operations::decay::write_all_decay(piob, first, first + diff);
#endif
	}
	else
	{
		fp->_ptr = non_overlapped_copy_n(first, diff, fp->_base);
		fp->_cnt = static_cast<::std::int_least32_t>(bufsiz - diff);
	}
}

#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline void wincrt_fp_write_cold_impl(FILE *__restrict fp, char const *first, char const *last)
{
	::std::size_t diff{static_cast<::std::size_t>(last - first)};
	crt_iobuf *fpp{reinterpret_cast<crt_iobuf *>(fp)};
	if (fpp->_base == nullptr)
	{
		wincrt_fp_write_cold_malloc_case_impl(fp, first, diff);
	}
	else
	{
		wincrt_fp_write_cold_normal_case_impl(fp, first, diff);
	}
}

template <::std::integral char_type>
	requires(sizeof(char_type) <= 4)
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline void wincrt_fp_overflow_impl(FILE *__restrict fpp, char_type ch)
{
	crt_iobuf *fp{reinterpret_cast<crt_iobuf *>(fpp)};
	if (fp->_base == nullptr)
	{
		wincrt_fp_allocate_buffer_impl(fpp);
	}
	else
	{
#if 0
		posix_write_simple_impl(static_cast<::std::int_least32_t>(fp->_file),fp->_base,static_cast<::std::size_t>(static_cast<::std::uint_least32_t>(fp->_bufsiz)));
#else
		::ufio::posix_io_observer piob{static_cast<::std::int_least32_t>(fp->_file)};
		::ufio::operations::decay::write_all_decay(piob, fp->_base, fp->_base + fp->_bufsiz);
#endif
	}
	fp->_ptr = fp->_base;
	my_memcpy(fp->_ptr, __builtin_addressof(ch), sizeof(ch));
	fp->_ptr += sizeof(ch);
	fp->_cnt = static_cast<::std::int_least32_t>(static_cast<::std::uint_least32_t>(fp->_bufsiz - static_cast<::std::int_least32_t>(sizeof(ch))));
	fp->_flag |= crt_dirty_value;
}

#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline void wincrt_fp_flush_stdout_impl()
{
	crt_iobuf *fp{reinterpret_cast<crt_iobuf *>(::ufio::win32::wincrt_acrt_iob_func(1))};
#if 1
	if (fp->_ptr == fp->_base)
	{
		return;
	}
	::ufio::posix_io_observer piob{static_cast<::std::int_least32_t>(fp->_file)};
	::ufio::operations::decay::write_all_decay(piob, fp->_base, fp->_ptr);
#else
	::std::size_t diff{static_cast<::std::size_t>(fp->_ptr - fp->_base)};
	//	if(diff==0||!wincrt_fp_is_dirty_impl(fp))
	if (diff == 0)
	{
		return;
	}
	posix_write_simple_impl(static_cast<::std::int_least32_t>(fp->_file), fp->_base, diff);
#endif
	fp->_ptr = fp->_base;
}

#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline char *wincrt_fp_read_cold_impl(FILE *__restrict fpp, char *first, ::std::size_t diff)
{
	if (fpp == ::ufio::win32::wincrt_acrt_iob_func(0))
	{
		wincrt_fp_flush_stdout_impl();
	}
	crt_iobuf *fp{reinterpret_cast<crt_iobuf *>(fpp)};
	::std::size_t cnt{static_cast<::std::size_t>(static_cast<::std::uint_least32_t>(fp->_cnt))};
	non_overlapped_copy_n(fp->_ptr, cnt, first);
	first += cnt;
	diff -= cnt;
	::std::size_t allocated_buffer_size{static_cast<::std::size_t>(static_cast<::std::uint_least32_t>(fp->_bufsiz))};
	if (allocated_buffer_size < 4)
	{
		allocated_buffer_size = wincrt_internal_buffer_size;
	}

	if (diff >= allocated_buffer_size)
	{
#if 0
		return posix_read_impl(static_cast<::std::int_least32_t>(fp->_file),first,diff);
#else
		::ufio::posix_io_observer piob{static_cast<::std::int_least32_t>(fp->_file)};
		return ::ufio::operations::decay::read_some_decay(piob, first, first + diff);
#endif
	}
	else
	{
		if (fp->_base == nullptr)
		{
			auto new_buffer{my_malloc_crt(allocated_buffer_size)};
			fp->_ptr = fp->_base = reinterpret_cast<char *>(new_buffer);
			fp->_cnt = 0;
			fp->_bufsiz = static_cast<::std::int_least32_t>(static_cast<::std::uint_least32_t>(allocated_buffer_size));
			fp->_flag |= crt_mybuf_value;
		}

#if 0
		::std::size_t readed{posix_read_impl(static_cast<::std::int_least32_t>(fp->_file),fp->_base,static_cast<::std::size_t>(static_cast<::std::uint_least32_t>(fp->_bufsiz)))};
#else
		::std::size_t readed;
		{
			::ufio::posix_io_observer piob{static_cast<::std::int_least32_t>(fp->_file)};
			readed = static_cast<::std::size_t>(
				::ufio::operations::decay::read_some_decay(piob, fp->_base, fp->_base + fp->_bufsiz) - fp->_base);
		}
#endif
		fp->_cnt = static_cast<::std::int_least32_t>(static_cast<::std::uint_least32_t>(readed));
		fp->_ptr = fp->_base;
		if (readed < diff)
		{
			diff = readed;
		}
		non_overlapped_copy_n(fp->_base, diff, first);
		fp->_ptr += diff;
		fp->_cnt -= static_cast<::std::int_least32_t>(static_cast<::std::uint_least32_t>(diff));
		return first + diff;
	}
}

template <::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__cold__)
[[__gnu__::__cold__]]
#endif
inline bool wincrt_fp_underflow_impl(FILE *__restrict fpp)
{
	if (fpp == ::ufio::win32::wincrt_acrt_iob_func(0))
	{
		wincrt_fp_flush_stdout_impl();
	}
	crt_iobuf *fp{reinterpret_cast<crt_iobuf *>(fpp)};
	if (fp->_base == nullptr)
	{
		wincrt_fp_allocate_buffer_impl(fpp);
	}
#if 0
	::std::size_t size{posix_read_impl(static_cast<::std::int_least32_t>(fp->_file),fp->_base,static_cast<::std::size_t>(static_cast<::std::uint_least32_t>(fp->_bufsiz)))};
#else
	::std::size_t size;
	{
		::ufio::posix_io_observer piob{static_cast<::std::int_least32_t>(fp->_file)};
		size = static_cast<::std::size_t>(
			::ufio::operations::decay::read_some_decay(piob, fp->_base, fp->_base + fp->_bufsiz) - fp->_base);
	}
#endif
	fp->_ptr = fp->_base;
	fp->_cnt = static_cast<::std::int_least32_t>(static_cast<::std::uint_least32_t>(size));
	if constexpr (sizeof(char_type) == 1)
	{
		return static_cast<bool>(size);
	}
	else
	{
		return sizeof(char_type) <= size;
	}
}

template <typename T, ::std::size_t num>
#if __has_cpp_attribute(__gnu__::__may_alias__)
[[__gnu__::__may_alias__]]
#endif
inline T *wincrt_get_buffer_ptr_impl(FILE *__restrict fpp) noexcept
{
	static_assert(num < 4);
	crt_iobuf *fp{reinterpret_cast<crt_iobuf *>(fpp)};
	if constexpr (num == 0)
	{
		return reinterpret_cast<T *>(fp->_base);
	}
	else if constexpr (num == 1)
	{
		return reinterpret_cast<T *>(fp->_ptr);
	}
	else
	{
		return reinterpret_cast<T *>(fp->_ptr + fp->_cnt);
	}
}

template <typename T>
inline void wincrt_set_buffer_curr_ptr_impl(FILE *__restrict fpp,
#if __has_cpp_attribute(__gnu__::__may_alias__)
											[[__gnu__::__may_alias__]]
#endif
											T *ptr) noexcept
{
	crt_iobuf *fp{reinterpret_cast<crt_iobuf *>(fpp)};
	fp->_cnt -= static_cast<::std::int_least32_t>(
		static_cast<::std::uint_least32_t>(static_cast<::std::size_t>(reinterpret_cast<char *>(ptr) - fp->_ptr) / sizeof(T)));
	fp->_ptr = reinterpret_cast<char *>(ptr);
}
#if defined(_MSC_VER) || defined(_UCRT)
/*
WINE has not correctly implemented this yet. I am submitting patches.
*/
inline void ucrt_lock_file(FILE *__restrict fp) noexcept
{
	char *fp2{reinterpret_cast<char *>(fp)};
	::ufio::win32::EnterCriticalSection(fp2 + sizeof(crt_iobuf));
}
inline void ucrt_unlock_file(FILE *__restrict fp) noexcept
{
	char *fp2{reinterpret_cast<char *>(fp)};
	::ufio::win32::LeaveCriticalSection(fp2 + sizeof(crt_iobuf));
}
#endif
} // namespace details

template <::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__may_alias__)
[[__gnu__::__may_alias__]]
#endif
inline char_type *ibuffer_begin(basic_c_io_observer_unlocked<char_type> ciob) noexcept
{
	return details::wincrt_get_buffer_ptr_impl<char_type, 0>(ciob.fp);
}

template <::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__may_alias__)
[[__gnu__::__may_alias__]]
#endif
inline char_type *ibuffer_curr(basic_c_io_observer_unlocked<char_type> ciob) noexcept
{
	return details::wincrt_get_buffer_ptr_impl<char_type, 1>(ciob.fp);
}

template <::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__may_alias__)
[[__gnu__::__may_alias__]]
#endif
inline char_type *ibuffer_end(basic_c_io_observer_unlocked<char_type> ciob) noexcept
{
	return details::wincrt_get_buffer_ptr_impl<char_type, 2>(ciob.fp);
}

template <::std::integral char_type>
inline void ibuffer_set_curr(basic_c_io_observer_unlocked<char_type> ciob, char_type *ptr) noexcept
{
	details::wincrt_set_buffer_curr_ptr_impl(ciob.fp, ptr);
}

template <::std::integral char_type>
inline bool ibuffer_underflow(basic_c_io_observer_unlocked<char_type> ciob)
{
	return details::wincrt_fp_underflow_impl<char_type>(ciob.fp);
}

template <::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__may_alias__)
[[__gnu__::__may_alias__]]
#endif
inline char_type *obuffer_begin(basic_c_io_observer_unlocked<char_type> ciob) noexcept
{
	return details::wincrt_get_buffer_ptr_impl<char_type, 0>(ciob.fp);
}

template <::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__may_alias__)
[[__gnu__::__may_alias__]]
#endif
inline char_type *obuffer_curr(basic_c_io_observer_unlocked<char_type> ciob) noexcept
{
	return details::wincrt_get_buffer_ptr_impl<char_type, 1>(ciob.fp);
}

template <::std::integral char_type>
#if __has_cpp_attribute(__gnu__::__may_alias__)
[[__gnu__::__may_alias__]]
#endif
inline char_type *obuffer_end(basic_c_io_observer_unlocked<char_type> ciob) noexcept
{
	return details::wincrt_get_buffer_ptr_impl<char_type, 2>(ciob.fp);
}

template <::std::integral char_type>
inline void obuffer_set_curr(basic_c_io_observer_unlocked<char_type> ciob, char_type *ptr) noexcept
{
	details::wincrt_set_buffer_curr_ptr_impl(ciob.fp, ptr);
}

template <::std::integral char_type>
inline void obuffer_overflow(basic_c_io_observer_unlocked<char_type> ciob, char_type ch)
{
	details::wincrt_fp_overflow_impl(ciob.fp, ch);
}

template <::std::integral char_type>
inline ::std::byte *read_some_bytes_underflow_define(::ufio::basic_c_io_observer_unlocked<char_type> ciob,
													 ::std::byte *first, ::std::byte *last)
{
	return ::ufio::details::wincrt_fp_read_cold_impl(ciob.fp, reinterpret_cast<char *>(first),
														reinterpret_cast<char *>(last));
}

template <::std::integral char_type>
inline void write_all_bytes_overflow_define(::ufio::basic_c_io_observer_unlocked<char_type> ciob,
											::std::byte const *first, ::std::byte const *last)
{
	::ufio::details::wincrt_fp_write_cold_impl(ciob.fp, reinterpret_cast<char const *>(first),
												  reinterpret_cast<char const *>(last));
}

inline c_io_observer c_stdin() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(0)};
}

inline c_io_observer c_stdout() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(1)};
}

inline c_io_observer c_stderr() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(2)};
}

inline wc_io_observer wc_stdin() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(0)};
}

inline wc_io_observer wc_stdout() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(1)};
}

inline wc_io_observer wc_stderr() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(2)};
}

inline u8c_io_observer u8c_stdin() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(0)};
}

inline u8c_io_observer u8c_stdout() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(1)};
}

inline u8c_io_observer u8c_stderr() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(2)};
}

inline u16c_io_observer u16c_stdin() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(0)};
}

inline u16c_io_observer u16c_stdout() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(1)};
}

inline u16c_io_observer u16c_stderr() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(2)};
}

inline u32c_io_observer u32c_stdin() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(0)};
}

inline u32c_io_observer u32c_stdout() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(1)};
}

inline u32c_io_observer u32c_stderr() noexcept
{
	return {::ufio::win32::wincrt_acrt_iob_func(2)};
}

} // namespace ufio
