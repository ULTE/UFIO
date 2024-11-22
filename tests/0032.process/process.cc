#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;
using namespace ufio::mnp;
using ufio::native_process;
using ufio::native_process_io;
using ufio::posix_dev_null;
using ufio::iobuf_pipe;

int main()
try
{
	auto cout = ufio::c_stdout();
	::ufio::win32_process p;
	{
		iobuf_pipe pipe1;
		p = ::ufio::win32_process{
#ifdef _WIN32
			u8"test.exe"
#else
			u8"test"
#endif
			,
			{},
			{},
			{posix_dev_null(),
			 posix_dev_null(),
			 pipe1.handle}};
		// pipe1.handle.out().close();
		pipe1.handle.out().close();
		char buf[4096];
		for (;;)
		{
			auto fe = ufio::operations::read_some(pipe1, buf, buf + 4096);
			if (fe == buf)
			{
				break;
			}
			::ufio::io::print(cout, "Child: ", ::ufio::mnp::strvw(buf, fe));
		}
	}

	auto s = wait(p);
	return s.wait_loc;
}
catch (ufio::error e)
{
	perrln(e);
	return 1;
}
