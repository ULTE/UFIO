﻿#pragma once

#include "single.h"
#ifdef __USING_MCFGTHREAD__
#include <mcfgthread/mutex.h>
#include "mcf_gthread_mutex.h"
#endif
#if defined(_WIN32) || defined(__CYGWIN__)
#include "rtl_critical_section.h"
#include "win32_critical_section.h"
#include "rtl_srwlock.h"
#include "win32_srwlock.h"
#endif
#if !defined(__SINGLE_THREAD__) && (!defined(__NEWLIB__) || defined(__CYGWIN__)) && !defined(_WIN32) && \
	!defined(__MSDOS__) && !defined(__wasi__) && __has_include(<pthread.h>)
#include "posix_pthread_mutex.h"
#endif

namespace ufio
{

using native_mutex =
#ifdef __USING_MCFGTHREAD__
	mcf_gthread_mutex
#elif (defined(_WIN32) && !defined(__WINE__)) || defined(__CYGWIN__)
#if !defined(__CYGWIN__) && !defined(__BIONIC__) && defined(_WIN32_WINDOWS)
#if (!defined(_WIN32_WINNT) || _WIN32_WINNT >= 0x0600)
	win32_srwlock
#else
	win32_critical_section
#endif
#else
#if (!defined(_WIN32_WINNT) || _WIN32_WINNT >= 0x0600)
	rtl_srwlock
#else
	rtl_critical_section
#endif
#endif
#elif defined(__SINGLE_THREAD__) || defined(__MSDOS__) || (defined(__NEWLIB__) && !defined(__CYGWIN__)) || \
	defined(__wasi__) || !__has_include(<pthread.h>)
	single_thread_noop_mutex
#else
	posix_pthread_mutex
#endif
	;

template <typename Mutex>
using basic_mutex_movable = ::std::conditional_t<::std::movable<Mutex>, Mutex,
												 ::ufio::basic_general_mutex_movable<Mutex, ::ufio::native_global_allocator>>;
using native_mutex_movable = ::ufio::basic_mutex_movable<native_mutex>;

template <typename T>
using basic_io_lockable_nonmovable = ::ufio::basic_general_io_lockable_nonmovable<T, ::ufio::native_mutex>;
template <typename T>
using basic_io_lockable = ::ufio::basic_general_io_lockable_nonmovable<T, ::ufio::native_mutex_movable>;

} // namespace ufio