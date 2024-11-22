#include <ufio.h>
#include <ufio_dsal/string_view.h>

int main(int argc, char **argv)
{
	if (argc != 5)
	{
		if (argc == 0)
		{
			return 1;
		}
		::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file> [creation_time (iso8601), now, omit] [last_modification_time (iso8601), now, omit] [last_access_time (iso8601), now, omit]\n");
		return 1;
	}

#if __cpp_exceptions
	try
#endif
	{

		::ufio::unix_timestamp_option creation_time;
		::ufio::unix_timestamp_option last_access_time;
		::ufio::unix_timestamp_option last_modification_time;

		::ufio::iso8601_timestamp iso8601_ts{};

		bool succussed{};
		try
		{
			iso8601_ts = ::ufio::to<::ufio::iso8601_timestamp>(ufio::mnp::os_c_str(argv[2]));
			succussed = true;
		}
		catch (::ufio::error)
		{
			succussed = false;
		}
		if (succussed)
		{
			creation_time.flags = ::ufio::utime_flags::none;
			creation_time.timestamp = ::ufio::to_timestamp(iso8601_ts);
		}
		else if (::ufio::u8cstring_view{ufio::mnp::os_c_str(reinterpret_cast<char8_t *>(argv[2]))} == u8"now")
		{
			creation_time.flags = ::ufio::utime_flags::now;
		}
		else if (::ufio::u8cstring_view{ufio::mnp::os_c_str(reinterpret_cast<char8_t *>(argv[2]))} == u8"omit")
		{
			creation_time.flags = ::ufio::utime_flags::omit;
		}
		else
		{
			::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file> [creation_time, now, omit] [last_modification_time, now, omit] [last_access_time, now, omit]\n");
			return 1;
		}

		try
		{
			iso8601_ts = ::ufio::to<::ufio::iso8601_timestamp>(ufio::mnp::os_c_str(argv[3]));
			succussed = true;
		}
		catch (::ufio::error)
		{
			succussed = false;
		}
		if (succussed)
		{
			last_access_time.flags = ::ufio::utime_flags::none;
			last_access_time.timestamp = ::ufio::to_timestamp(iso8601_ts);
		}
		else if (::ufio::u8cstring_view{ufio::mnp::os_c_str(reinterpret_cast<char8_t *>(argv[3]))} == u8"now")
		{
			last_access_time.flags = ::ufio::utime_flags::now;
		}
		else if (::ufio::u8cstring_view{ufio::mnp::os_c_str(reinterpret_cast<char8_t *>(argv[3]))} == u8"omit")
		{
			last_access_time.flags = ::ufio::utime_flags::omit;
		}
		else
		{
			::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file> [creation_time, now, omit] [last_modification_time, now, omit] [last_access_time, now, omit]\n");
			return 1;
		}

		try
		{
			iso8601_ts = ::ufio::to<::ufio::iso8601_timestamp>(ufio::mnp::os_c_str(argv[4]));
			succussed = true;
		}
		catch (::ufio::error)
		{
			succussed = false;
		}
		if (succussed)
		{
			last_modification_time.flags = ::ufio::utime_flags::none;
			last_modification_time.timestamp = ::ufio::to_timestamp(iso8601_ts);
		}
		else if (::ufio::u8cstring_view{ufio::mnp::os_c_str(reinterpret_cast<char8_t *>(argv[4]))} == u8"now")
		{
			last_modification_time.flags = ::ufio::utime_flags::now;
		}
		else if (::ufio::u8cstring_view{ufio::mnp::os_c_str(reinterpret_cast<char8_t *>(argv[4]))} == u8"omit")
		{
			last_modification_time.flags = ::ufio::utime_flags::omit;
		}
		else
		{
			::ufio::io::perr("Usage: ", ufio::mnp::os_c_str(*argv), " <file> [creation_time, now, omit] [last_modification_time, now, omit] [last_access_time, now, omit]\n");
			return 1;
		}

		::ufio::native_utimensat(::ufio::at_fdcwd(), ufio::mnp::os_c_str(argv[1]), creation_time, last_access_time, last_modification_time);
	}
#if __cpp_exceptions
	catch (ufio::error e)
	{
		::ufio::io::perrln(e);
	}
#endif
}
