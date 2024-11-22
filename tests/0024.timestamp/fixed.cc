#define UFIO_SANITIZE_IO_BUFFER
#include <ufio.h>

inline void test_val(::ufio::unix_timestamp ts)
{
	using namespace ::ufio::mnp;
	using namespace ::ufio::io;
	println("val:", ts, "\n",
			fixed(ts, 0), "\n",
			fixed(ts, 1), "\n",
			fixed(ts, 2), "\n",
			fixed(ts, 3), "\n",
			fixed(ts, 4), "\n",
			fixed(ts, 5), "\n",
			fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 - 3), "\n",
			fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 - 2), "\n",
			fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 - 1), "\n",
			fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10), "\n",
			fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 + 1), "\n",
			fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 + 2), "\n",
			fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 * 2), "\n",
			comma_fixed(ts, 0), "\n",
			comma_fixed(ts, 1), "\n",
			comma_fixed(ts, 2), "\n",
			comma_fixed(ts, 3), "\n",
			comma_fixed(ts, 4), "\n",
			comma_fixed(ts, 5), "\n",
			comma_fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 - 3), "\n",
			comma_fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 - 2), "\n",
			comma_fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 - 1), "\n",
			comma_fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10), "\n",
			comma_fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 + 1), "\n",
			comma_fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 + 2), "\n",
			comma_fixed(ts, ::std::numeric_limits<::std::uint_least64_t>::digits10 * 2));
}

int main()
{
	test_val({0, 0});
	test_val({0, ::ufio::uint_least64_subseconds_per_second - 1u});
	test_val({0, ::ufio::uint_least64_subseconds_per_second >> 1u});
	test_val({0, (::ufio::uint_least64_subseconds_per_second / 10u) >> 1u});
	test_val({0, (::ufio::uint_least64_subseconds_per_second / 100u) >> 1u});
	test_val({0, (3 * (::ufio::uint_least64_subseconds_per_second / 100u)) >> 1u});
	test_val({::std::numeric_limits<::std::int_least64_t>::max(), ::ufio::uint_least64_subseconds_per_second - 1u});
	test_val({::std::numeric_limits<::std::int_least64_t>::max(), ::ufio::uint_least64_subseconds_per_second >> 1u});
	test_val({::std::numeric_limits<::std::int_least64_t>::max(), (::ufio::uint_least64_subseconds_per_second / 10u) >> 1u});
	test_val({::std::numeric_limits<::std::int_least64_t>::min(), ::ufio::uint_least64_subseconds_per_second - 1u});
	test_val({::std::numeric_limits<::std::int_least64_t>::min(), ::ufio::uint_least64_subseconds_per_second >> 1u});
	test_val({::std::numeric_limits<::std::int_least64_t>::min(), (::ufio::uint_least64_subseconds_per_second / 10u) >> 1u});
	test_val({::std::numeric_limits<::std::int_least64_t>::min(), ::ufio::uint_least64_subseconds_per_second >> 1u});
	test_val(::ufio::posix_clock_gettime(::ufio::posix_clock_id::realtime));
}
