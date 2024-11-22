#pragma once

namespace ufio::wine
{

using linux_syscall_table =
#if defined(__x86_64__)
	linux_syscall_table_x86_64
#else
	linux_syscall_table_i686
#endif
	;

} // namespace ufio::wine
