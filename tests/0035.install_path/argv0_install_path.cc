#include <ufio.h>
#include <ufio_device.h>
#include <ufio_tools/install_path.h>

int main(int argc, char**argv)
{
	if (argc == 0)
	{
		return -1;
	}
	try
	{
		auto [module_name, path_name]{::ufio::get_module_install_path_from_argv0(*argv)};
		::ufio::io::perrln(::ufio::u8out(), u8"path: ", path_name, u8", name: ", module_name);
		::ufio::dir_file dir{path_name};
	}
	catch (::ufio::error e)
	{
		::ufio::perrln(e);
	}
}
