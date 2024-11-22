﻿#include <ufio.h>

using namespace ufio::io;

int main()
{
	/*
	Typically, file stream functionalities are not implemented at the OS native API level.
	In Microsoft DOS, LF to CRLF conversion is carried out at the POSIX level using two systems.
	However, in Windows, LF to CRLF conversion occurs at the file descriptor level, though not at the Win32 or NT level; rather, it involves CRT tricks.
	It's likely that other operating systems implement this conversion at the FILE* level as well.
	*/
	ufio::posix_file cfl("text.txt", ufio::open_mode::out |
											ufio::open_mode::text); // add open_mode::text to open_mode flag
	ufio::posix_tzset();
	auto unix_ts{ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)};
	using namespace ufio::mnp;
	println(cfl, "Unix Timestamp:", unix_ts,
			"\n"
			"Universe Timestamp:",
			static_cast<ufio::universe_timestamp>(unix_ts),
			"\n"
			"UTC:",
			utc(unix_ts), "\n", "Local:", local(unix_ts), " Timezone:", ufio::timezone_name(), "\n",
#ifdef __clang__
			"LLVM clang ", __clang_version__,
			"\n"
#elif defined(__GNUC__)
			"gcc ", __GNUC__,
			"\n"
#elif defined(_MSC_VER)
			"Microsoft Visual C++ ", _MSC_VER,
			"\n"
#else
			"Unknown C++ compiler\n"
#endif
#if defined(__GLIBCXX__)
			"GCC libstdc++ ",
			__GLIBCXX__,
			"\n"
#elif defined(_LIBCPP_VERSION)
			"LLVM libc++ ",
			_LIBCPP_VERSION,
			"\n"
#elif defined(_MSVC_STL_UPDATE)
			"Microsoft Visual C++ STL ",
			_MSVC_STL_UPDATE,
			"\n"
#else
			"Unknown C++ standard library\n"
#endif
			"fd:",
			handlevw(static_cast<ufio::posix_io_observer>(cfl).fd)
#ifdef _WIN32
				,
			"\n"
			"win32 HANDLE:",
			handlevw(static_cast<ufio::win32_io_observer>(cfl).handle),
			"\n"
			"zw HANDLE:",
			handlevw(static_cast<ufio::zw_io_observer>(cfl).handle),
			"\n"
			"nt HANDLE:",
			handlevw(static_cast<ufio::nt_io_observer>(cfl).handle)
#endif
	);
}
/*
Demo output:
Unix Timestamp:1620354611.4156443
Universe Timestamp:434602343049589811.4156443
UTC:2021-05-07T02:30:11.4156443Z
Local:2021-05-06T22:30:11.4156443-04:00 Timezone:Eastern Daylight Time
gcc 12
GCC libstdc++ 20210505
FILE*:0x00007ff95961fa90
fd:3
win32 HANDLE:0x00000000000000b8
zw HANDLE:0x00000000000000b8
nt HANDLE:0x00000000000000b8
*/