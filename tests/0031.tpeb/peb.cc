#include <cstdio>
#include <ufio_core.h>

int main()
{
	printf("nt_get_current_peb():%p\nRtlGetCurrentPeb():%p\n",
		   ::ufio::win32::nt::nt_get_current_peb(),
		   ::ufio::win32::nt::RtlGetCurrentPeb());
}
