#include <ufio.h>
#include <ufio_device.h>
#include <ufio_tools/install_path.h>

int main()
{
	try
	{
		auto [module_name, path_name]{::ufio::get_module_install_path()};
		::ufio::io::perrln(::ufio::u8out(),u8"path: ",  path_name, u8", name: ", module_name);
		::ufio::dir_file dir{path_name};
	}
	catch (::ufio::error e)
	{
		::ufio::perrln(e);
	}
}
