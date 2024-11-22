#include <ufio.h>
#include <ufio_driver/nt_kernel.h>

using namespace ufio::io;

extern "C" std::uint32_t DriverEntry(::ufio::win32::nt::driver_object *driverobject,
									 ::ufio::win32::nt::utf16_string *registrypath) noexcept
{
	println(ufio::u8nt_dbg(), u8"Hello World from ufio:\ndriverobject:", driverobject, u8" registrypath:",
			registrypath);
	println(ufio::u8nt_dbg(), u8"test floating point:", 241.43643634);
	return 0;
}
