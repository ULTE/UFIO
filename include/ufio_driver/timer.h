#pragma once
#include "../ufio.h"
#include "../ufio_dsal/string_view.h"

namespace ufio
{

struct timer
{
	::ufio::u8string_view s;
	unix_timestamp t0;
#if __has_cpp_attribute(__gnu__::__cold__)
	[[__gnu__::__cold__]]
#endif
	explicit timer(::ufio::u8string_view strvw)
		: s(strvw), t0(posix_clock_gettime(posix_clock_id::monotonic_raw))
	{
	}
	timer(timer const &) = delete;
	timer &operator=(timer const &) = delete;
#if __has_cpp_attribute(__gnu__::__cold__)
	[[__gnu__::__cold__]]
#endif
	~timer()
	{
		::ufio::io::perr(ufio::u8err(), s, u8":", posix_clock_gettime(posix_clock_id::monotonic_raw) - t0,
							u8"s\n");
	}
};
} // namespace ufio
