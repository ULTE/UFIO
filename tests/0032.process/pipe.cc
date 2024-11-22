#include <ufio.h>
int main()
{
	try
	{
		ufio::native_pipe pipe{};
		ufio::native_process p{"test.exe", {}, {}, {{}, pipe, pipe}};
		char *ptr{(char *)_alloca(4096)};
		::ufio::freestanding::bytes_clear_n((::std::byte *)ptr, 4096);
		char *last{};
		for (;;)
		{

			auto end = ::ufio::operations::read_some(pipe.in(), ptr, ptr + 4096);
			if (end == last)
			{
				break;
			}
			last = end;
		}
		::ufio::perrln("child: ", ::ufio::mnp::os_c_str(ptr));
	}
	catch (ufio::error err)
	{
		ufio::io::perrln(err);
	}
}
