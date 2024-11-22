#include <ufio.h>

using namespace ufio::io;

int main()
try
{
	ufio::native_file pf(u8"example.txt", ufio::open_mode::app);
	for (std::size_t i{}; i != 1000000; ++i)
	{
		ufio::file_lock_guard g(file_lock(pf), ufio::flock_request_l64{});
		print(pf, "Hello ");
		print(pf, "World\n");
	}
}
catch (ufio::error e)
{
	perrln(e);
	return 1;
}