#include <ufio.h>
#include <ufio_device.h>

using namespace ufio::io;

int main()
{
	ufio::native_dll_file dll(L"a.dll", ufio::dll_mode::posix_rtld_lazy);
	[[maybe_unused]] auto proc{dll_load_symbol(dll, u8"GetProc")};
}
