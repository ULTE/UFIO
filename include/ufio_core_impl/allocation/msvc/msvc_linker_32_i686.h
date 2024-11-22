#pragma once
// clang-format off

#pragma comment(linker, "/alternatename:__imp_?HeapAlloc@win32@ufio@@YGPAXPAXII@Z=__imp__HeapAlloc@12")
#pragma comment(linker, "/alternatename:__imp_?HeapFree@win32@ufio@@YGHPAXI0@Z=__imp__HeapFree@12")
#pragma comment(linker, "/alternatename:__imp_?GetProcessHeap@win32@ufio@@YGPAXXZ=__imp__GetProcessHeap@0")
#pragma comment(linker, "/alternatename:__imp_?HeapReAlloc@win32@ufio@@YGPAXPAXI0I@Z=__imp__HeapReAlloc@16")
#pragma comment(linker, "/alternatename:__imp_?HeapSize@win32@ufio@@YGIPAXIPBX@Z=__imp__HeapSize@12")
#pragma comment(linker, "/alternatename:__imp_?RtlAllocateHeap@nt@win32@ufio@@YGPAXPAXII@Z=__imp__RtlAllocateHeap@12")
#pragma comment(linker, "/alternatename:__imp_?RtlFreeHeap@nt@win32@ufio@@YGEPAXI0@Z=__imp__RtlFreeHeap@12")
#pragma comment(linker, "/alternatename:__imp_?RtlGetCurrentPeb@nt@win32@ufio@@YGPAUpeb@123@XZ=__imp__RtlGetCurrentPeb@0")
#pragma comment(linker, "/alternatename:__imp_?RtlReAllocateHeap@nt@win32@ufio@@YGPAXPAXI0I@Z=__imp__RtlReAllocateHeap@16")
#pragma comment(linker, "/alternatename:__imp_?RtlSizeHeap@nt@win32@ufio@@YGIPAXI0@Z=__imp__RtlSizeHeap@12")
#pragma comment(linker, "/alternatename:__imp_?VirtualAlloc@win32@ufio@@YGPAXPAXIII@Z=__imp__VirtualAlloc@16")
#pragma comment(linker, "/alternatename:__imp_?VirtualProtect@win32@ufio@@YGHPAXIIPAI@Z=__imp__VirtualProtect@16")
#pragma comment(linker, "/alternatename:__imp_?VirtualFree@win32@ufio@@YGHPAXII@Z=__imp__VirtualFree@12")
#pragma comment(linker, "/alternatename:__imp_?VirtualQuery@win32@ufio@@YGHPBXPAUmemory_basic_information@12@I@Z=__imp__VirtualQuery@12")

#pragma comment(linker, "/alternatename:__imp_?mi_malloc@mimalloc@ufio@@YAPAXI@Z=_mi_malloc")
#pragma comment(linker, "/alternatename:__imp_?mi_free@mimalloc@ufio@@YAXPAX@Z=_mi_free")
#pragma comment(linker, "/alternatename:__imp_?mi_calloc@mimalloc@ufio@@YAPAXII@Z=_mi_calloc")
#pragma comment(linker, "/alternatename:__imp_?mi_realloc@mimalloc@ufio@@YAPAXPAXI@Z=_mi_realloc")
#pragma comment(linker, "/alternatename:__imp_?mi_malloc_aligned@mimalloc@ufio@@YAPAXII@Z=_mi_malloc_aligned")
#pragma comment(linker, "/alternatename:__imp_?mi_ralloc_aligned@mimalloc@ufio@@YAPAXPAXII@Z=_mi_ralloc_aligned")
#pragma comment(linker, "/alternatename:__imp_?mi_calloc_aligned@mimalloc@ufio@@YAPAXIII@Z=_mi_calloc_aligned")
#pragma comment(linker, "/alternatename:__imp_?mi_free_aligned@mimalloc@ufio@@YAPAXPAXI@Z=_mi_free_aligned")
// clang-format on
