#include <ufio.h>
#include <ufio_device.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 0) [[unlikely]]
		{
			return 1;
		}
		::ufio::io::perr("Usage: ", ::ufio::mnp::os_c_str(*argv), " <exe>\n");
		return 1;
	}
	try
	{
		::ufio::io::perr(::ufio::out(), "Note that there is no input:\n");

		::ufio::iobuf_pipe pipe_out;
		::ufio::iobuf_pipe pipe_err;
		::ufio::native_process p{
			::ufio::mnp::os_c_str(argv[1]),
			{},
			{},
			{::ufio::posix_dev_null(), pipe_out.handle, pipe_err.handle}};

		pipe_out.handle.out().close();
		pipe_err.handle.out().close();


		::ufio::io::perr(::ufio::out(), "child stdout:\n");

		for (;;)
		{
			auto res{::ufio::operations::transmit_until_eof(::ufio::out(), pipe_out)};
			if (!res.transmitted)
			{
				break;
			}
		}

		::ufio::io::perr(::ufio::out(), "child stderr:\n");

		for (;;)
		{
			auto res{::ufio::operations::transmit_until_eof(::ufio::out(), pipe_err)};
			if (!res.transmitted)
			{
				break;
			}
		}

	}
	catch (ufio::error e)
	{
		perrln(e);
		return 1;
	}
}
