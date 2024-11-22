#include <ufio.h>
#include <android/log.h>

using namespace ufio::io;

int main()
{
	print(ufio::dbg(ANDROID_LOG_FATAL, "ufio"), std::source_location::current(), "\n",
		  utc(ufio::posix_clock_gettime(ufio::posix_clock_id::realtime)),
		  "\n"
		  "Hello World remote debugger from ufio\n");
	// it will print to android adb with logcat. Level is FATAL. tag is "ufio"
}
