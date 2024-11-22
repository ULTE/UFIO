#include <ufio.h>
#include <ufio_driver/qt.h>
#include <QtCore/QTextStream>

using namespace ufio::io;

int main()
{
/*
This is an example to explain how ufio's files work with each other, and how you could use ufio with existing
FILE* or fstream apis
*/
#if (defined(_WIN32) && !defined(__WINE__)) || defined(__CYGWIN__)
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
	ufio::qt_file qf(std::move(cf), ufio::open_mode::out);
	QTextStream qtextstream(qf.qdevice);
	qtextstream << "Hello World from QTextStream\n"; // qtextstream will buffer here
	qtextstream.flush();
	print(qf, "Hello World from ufio::qt_file\n");
	ufio::posix_tzset();
	auto unix_ts{ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)};
	println("Unix Timestamp:", unix_ts,
			"\n"
			"Universe Timestamp:",
			static_cast<ufio::universe_timestamp>(unix_ts),
			"\n"
			"UTC:",
			utc(unix_ts), "\n", "Local:", local(unix_ts), " Timezone:", ufio::timezone_name(),
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
			"GCC libstdc++ ",
			__GLIBCXX__,
			"\n"
#elif defined(_MSVC_STL_UPDATE)
			"Microsoft Visual C++ STL ",
			_MSVC_STL_UPDATE,
			"\n"
#else
			"Unknown C++ standard library\n"
#endif
			"qdevice:",
			qf.qdevice,
			"\n"
			"fd:",
			static_cast<ufio::posix_io_observer>(qf).fd
#if (defined(_WIN32) && !defined(__WINE__)) || defined(__CYGWIN__)
			,
			"\n"
			"win32 HANDLE:",
			static_cast<ufio::win32_io_observer>(qf).handle
#ifndef _WIN32_WINDOWS
			// NT kernel
			,
			"\n"
			"zw HANDLE:",
			static_cast<ufio::zw_io_observer>(qf).handle,
			"\n"
			"nt HANDLE:",
			static_cast<ufio::nt_io_observer>(qf).handle
#endif
#endif
	);
}
/*
Need -lcrypto to link to openssl
MinGW-w64 also needs -lntdll
g++ -o construct_fstream_from_syscall construct_fstream_from_syscall.cc -Ofast -std=c++20 -s -flto -march=native -lntdll
-I{qt include directory} {link to QtCorexxx}

9x kernel with clang might need
-Wl,--major-subsystem-version -Wl,4 -Wl,--minor-subsystem-version -Wl,0 -D_WIN32_WINDOWS=0x0400 -DWINVER=0x0400
*/
