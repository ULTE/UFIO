﻿#include <ufio_legacy.h>

using namespace ufio::io;

int main()
{
/*
This is an example to explain how ufio's files work with each other, and how you could use ufio with existing
FILE* or fstream apis
*/
#if (defined(_WIN32) && !defined(__WINE__)) && !defined(__CYGWIN__)
#ifdef _WIN32_WINDOWS
	//_WIN32_WINDOWS macro targets WIN9X kernel (windows 95, windows 98 and windows ME)
	// On 9x kernel, although ntdll.dll does exist, it does not do anything.
	ufio::win32_file nf("win32_file.txt", ufio::open_mode::out);
#else
	// NT kernel
	ufio::nt_file nf("nt_file.txt", ufio::open_mode::out);
#endif
	ufio::posix_file pf(std::move(nf), ufio::open_mode::out);
#else
	ufio::posix_file pf("posix_file.txt", ufio::open_mode::out);
#endif
	ufio::c_file cf(std::move(pf), ufio::open_mode::out);
	/*
	do not write
			fprintf(cf.fp,"Hello World from fprintf\n");
	This potentially contains format string vuln.
	*/
	print(cf, "Hello World from ufio::c_file\n");
	ufio::posix_tzset();
	auto unix_ts{ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)};
	println("Unix Timestamp:", unix_ts,
			"\n"
			"Universe Timestamp:",
			static_cast<ufio::universe_timestamp>(unix_ts),
			"\n"
			"UTC:",
			utc(unix_ts),
			"\n"
			"Local:",
			local(unix_ts), " Timezone:", ufio::timezone_name(),
			"\n"
#ifdef __clang__
			"LLVM clang " __clang_version__ "\n"
#elif defined(__GNUC__) && defined(__VERSION__)
			"GCC " __VERSION__ "\n"
#elif defined(_MSC_VER)
			"Microsoft Visual C++ ",
			_MSC_VER,
			"\n"
#else
			"Unknown C++ compiler\n"
#endif
#if defined(_LIBCPP_VERSION)
			"LLVM libc++ ",
			_LIBCPP_VERSION,
			"\n"
#elif defined(__GLIBCXX__)
			"GNU C++ Library ",
			_GLIBCXX_RELEASE, " ", __GLIBCXX__,
			"\n"
#elif defined(_MSVC_STL_UPDATE)
			"Microsoft Visual C++ STL ",
			_MSVC_STL_UPDATE,
			"\n"
#else
			"Unknown C++ standard library\n"
#endif
			"FILE*:",
			::ufio::mnp::handlevw(static_cast<ufio::c_io_observer>(cf).fp),
			"\n"
			"fd:",
			static_cast<ufio::posix_io_observer>(cf).fd
#if (defined(_WIN32) && !defined(__WINE__)) || defined(__CYGWIN__)
			,
			"\n"
			"win32 HANDLE:",
			::ufio::mnp::handlevw(static_cast<ufio::win32_io_observer>(cf).handle)
#ifndef _WIN32_WINDOWS
			// NT kernel
			,
			"\n"
			"zw HANDLE:",
			::ufio::mnp::handlevw(static_cast<ufio::zw_io_observer>(cf).handle),
			"\n"
			"nt HANDLE:",
			::ufio::mnp::handlevw(static_cast<ufio::nt_io_observer>(cf).handle)
#endif
#endif
	);
}
/*
MinGW-w64 needs -lntdll
g++ -o construct_fp_from_syscall construct_fp_from_syscall.cc -Ofast -std=c++20 -s -flto -march=native -lntdll

9x kernel with clang might need
-Wl,--major-subsystem-version -Wl,4 -Wl,--minor-subsystem-version -Wl,0 -D_WIN32_WINDOWS=0x0400 -DWINVER=0x0400
*/
