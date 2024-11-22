#pragma once
// clang-format off

#pragma comment(linker, "/alternatename:__imp_?HeapAlloc@win32@ufio@@YAPEAXPEAXI_K@Z=__imp_HeapAlloc")
#pragma comment(linker, "/alternatename:__imp_?HeapFree@win32@ufio@@YAHPEAXI0@Z=__imp_HeapFree")
#pragma comment(linker, "/alternatename:__imp_?GetProcessHeap@win32@ufio@@YAPEAXXZ=__imp_GetProcessHeap")
#pragma comment(linker, "/alternatename:__imp_?HeapReAlloc@win32@ufio@@YAPEAXPEAXI0_K@Z=__imp_HeapReAlloc")
#pragma comment(linker, "/alternatename:__imp_?HeapSize@win32@ufio@@YA_KPEAXIPEBX@Z=__imp_HeapSize")
#pragma comment(linker, "/alternatename:__imp_?RtlAllocateHeap@nt@win32@ufio@@YAPEAXPEAXI_K@Z=__imp_RtlAllocateHeap")
#pragma comment(linker, "/alternatename:__imp_?RtlFreeHeap@nt@win32@ufio@@YAEPEAXI0@Z=__imp_RtlFreeHeap")
#pragma comment(linker, "/alternatename:__imp_?RtlGetCurrentPeb@nt@win32@ufio@@YAPEAUpeb@123@XZ=__imp_RtlGetCurrentPeb")
#pragma comment(linker, "/alternatename:__imp_?RtlReAllocateHeap@nt@win32@ufio@@YAPEAXPEAXI0_K@Z=__imp_RtlReAllocateHeap")
#pragma comment(linker, "/alternatename:__imp_?RtlSizeHeap@nt@win32@ufio@@YA_KPEAXI0@Z=__imp_RtlSizeHeap")
#pragma comment(linker, "/alternatename:__imp_?VirtualAlloc@win32@ufio@@YAPEAXPEAX_KII@Z=__imp_VirtualAlloc")
#pragma comment(linker, "/alternatename:__imp_?VirtualProtect@win32@ufio@@YAHPEAX_KIPEAI@Z=__imp_VirtualProtect")
#pragma comment(linker, "/alternatename:__imp_?VirtualFree@win32@ufio@@YAHPEAX_KI@Z=__imp_VirtualFree")
#pragma comment(linker, "/alternatename:__imp_?__imp_?VirtualQuery@win32@ufio@@YAHPEBXPEAUmemory_basic_information@12@_K@Z=__imp_VirtualQuery")

#pragma comment(linker, "/alternatename:__imp_?mi_malloc@mimalloc@ufio@@YAPEAX_K@Z=mi_malloc")
#pragma comment(linker, "/alternatename:__imp_?mi_free@mimalloc@ufio@@YAXPEAX@Z=mi_free")
#pragma comment(linker, "/alternatename:__imp_?mi_calloc@mimalloc@ufio@@YAPEAX_K0@Z=mi_calloc")
#pragma comment(linker, "/alternatename:__imp_?mi_realloc@mimalloc@ufio@@YAPEAXPEAX_K@Z=mi_realloc")
#pragma comment(linker, "/alternatename:__imp_?mi_malloc_aligned@mimalloc@ufio@@YAPEAX_K0@Z=mi_malloc_aligned")
#pragma comment(linker, "/alternatename:__imp_?mi_ralloc_aligned@mimalloc@ufio@@YAPEAXPEAX_K1@Z=mi_ralloc_aligned")
#pragma comment(linker, "/alternatename:__imp_?mi_calloc_aligned@mimalloc@ufio@@YAPEAX_K00@Z=mi_calloc_aligned")
#pragma comment(linker, "/alternatename:__imp_?mi_free_aligned@mimalloc@ufio@@YAPEAXPEAX_K@Z=mi_free_aligned")

// clang-format on
