#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main()
try
{
	ufio::u8ibuf_file ibf("not_exist.txt");
}
catch (ufio::error e)
{
	if (e == std::errc::no_such_file_or_directory)
	{
		perr("errc:no_such_file_or_directory\n");
	}
	return 1;
}
