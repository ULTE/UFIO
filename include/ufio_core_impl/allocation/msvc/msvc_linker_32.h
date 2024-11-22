#pragma once
// clang-format off

#pragma comment(linker, "/alternatename:__imp_?HeapAlloc@win32@ufio@@YAPAXPAXII@Z=__imp_HeapAlloc")
#pragma comment(linker, "/alternatename:__imp_?HeapFree@win32@ufio@@YAHPAXI0@Z=__imp_HeapFree")
#pragma comment(linker, "/alternatename:__imp_?GetProcessHeap@win32@ufio@@YAPAXXZ=__imp_GetProcessHeap")
#pragma comment(linker, "/alternatename:__imp_?HeapReAlloc@win32@ufio@@YAPAXPAXI0I@Z=__imp_HeapReAlloc")
#pragma comment(linker, "/alternatename:__imp_?HeapSize@win32@ufio@@YAIPAXIPBX@Z=__imp_HeapFree")
#pragma comment(linker, "/alternatename:__imp_?RtlAllocateHeap@nt@win32@ufio@@YAPAXPAXII@Z=__imp_RtlAllocateHeap")
#pragma comment(linker, "/alternatename:__imp_?RtlFreeHeap@nt@win32@ufio@@YAEPAXI0@Z=__imp_RtlFreeHeap")
#pragma comment(linker, "/alternatename:__imp_?RtlGetCurrentPeb@nt@win32@ufio@@YAPAUpeb@123@XZ=__imp_RtlGetCurrentPeb")
#pragma comment(linker, "/alternatename:__imp_?RtlReAllocateHeap@nt@win32@ufio@@YAPAXPAXI0I@Z=__imp_RtlReAllocateHeap")
#pragma comment(linker, "/alternatename:__imp_?RtlSizeHeap@nt@win32@ufio@@YAIPAXI0@Z=__imp_RtlSizeHeap")
#pragma comment(linker, "/alternatename:__imp_?VirtualAlloc@win32@ufio@@YAPAXPAXIII@Z=__imp_VirtualAlloc")
#pragma comment(linker, "/alternatename:__imp_?VirtualProtect@win32@ufio@@YAHPAXIIPAI@Z=__imp_VirtualProtect")
#pragma comment(linker, "/alternatename:__imp_?VirtualFree@win32@ufio@@YAHPAXII@Z=__imp_VirtualFree")
#pragma comment(linker, "/alternatename:__imp_?VirtualQuery@win32@ufio@@YAHPBXPAUmemory_basic_information@12@I@Z=__imp_VirtualQuery")

#pragma comment(linker, "/alternatename:__imp_?mi_malloc@mimalloc@ufio@@YAPAXI@Z=mi_malloc")
#pragma comment(linker, "/alternatename:__imp_?mi_free@mimalloc@ufio@@YAXPAX@Z=mi_free")
#pragma comment(linker, "/alternatename:__imp_?mi_calloc@mimalloc@ufio@@YAPAXII@Z=mi_calloc")
#pragma comment(linker, "/alternatename:__imp_?mi_realloc@mimalloc@ufio@@YAPAXPAXI@Z=mi_realloc")
#pragma comment(linker, "/alternatename:__imp_?mi_malloc_aligned@mimalloc@ufio@@YAPAXII@Z=mi_malloc_aligned")
#pragma comment(linker, "/alternatename:__imp_?mi_ralloc_aligned@mimalloc@ufio@@YAPAXPAXII@Z=mi_ralloc_aligned")
#pragma comment(linker, "/alternatename:__imp_?mi_calloc_aligned@mimalloc@ufio@@YAPAXIII@Z=mi_calloc_aligned")
#pragma comment(linker, "/alternatename:__imp_?mi_free_aligned@mimalloc@ufio@@YAPAXPAXI@Z=mi_free_aligned")
// clang-format on
