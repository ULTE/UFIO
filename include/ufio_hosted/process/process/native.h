#pragma once

#if !defined(__MSDOS__) && !defined(__NEWLIB__) && !defined(__wasi__) && !defined(_PICOLIBC__)
// #include "base.h"
#include "arg_env.h"
#if (defined(_WIN32) && !defined(__WINE__)) || defined(__CYGWIN__)
#include "win32.h"
#include "nt.h"
#endif

#if defined(__CYGWIN__) || ((!defined(_WIN32) || defined(__WINE__)) && __has_include(<sys/wait.h>))
#include <sys/wait.h>
#include "posix.h"
#endif

namespace ufio
{
#if defined(_WIN32) && !defined(__CYGWIN__) && !defined(__WINE__)
#if !defined(_WIN32_WINDOWS) && (!defined(_WIN32_WINNT) || _WIN32_WINNT >= 0x600)
using native_process_args = ::ufio::nt_process_args;
using native_process_envs = ::ufio::nt_process_envs;
using native_process_observer = ::ufio::nt_process_observer;
using native_process = ::ufio::nt_process;
#else
using native_process_args = ::ufio::win32_process_args<::ufio::win32_family::native>;
using native_process_envs = ::ufio::win32_process_envs<::ufio::win32_family::native>;
using native_process_observer = ::ufio::win32_process_observer;
using native_process = ::ufio::win32_process;
#endif
#else
using native_process_args = ::ufio::posix_process_args;
using native_process_envs = ::ufio::posix_process_envs;
using native_process_observer = ::ufio::posix_process_observer;
using native_process = ::ufio::posix_process;
#endif
} // namespace ufio

#endif
