﻿#pragma once

// clang-format off
// WIN32
#pragma comment(linker,"/alternatename:__imp_?GetLastError@win32@ufio@@YGIXZ=__imp__GetLastError@0")
#pragma comment(linker,"/alternatename:__imp_?LoadLibraryA@win32@ufio@@YGPAXPBD@Z=__imp__LoadLibraryA@4")
#pragma comment(linker,"/alternatename:__imp_?LoadLibraryW@win32@ufio@@YGPAXPB_S@Z=__imp__LoadLibraryW@4")
#pragma comment(linker,"/alternatename:__imp_?LoadLibraryExA@win32@ufio@@YGPAXPBDPAXI@Z=__imp__LoadLibraryExA@12")
#pragma comment(linker,"/alternatename:__imp_?LoadLibraryExW@win32@ufio@@YGPAXPB_SPAXI@Z=__imp__LoadLibraryExW@12")
#pragma comment(linker,"/alternatename:__imp_?FormatMessageA@win32@ufio@@YGIIPBDIIPADIPAX@Z=__imp__FormatMessageA@28")
#pragma comment(linker,"/alternatename:__imp_?FormatMessageW@win32@ufio@@YGIIPB_SIIPA_SIPAX@Z=__imp__FormatMessageW@28")
#pragma comment(linker,"/alternatename:__imp_?CreateFileMappingA@win32@ufio@@YGPAXPAXPAUsecurity_attributes@12@IIIPBD@Z=__imp__CreateFileMappingA@24")
#pragma comment(linker,"/alternatename:__imp_?CreateFileMappingW@win32@ufio@@YGPAXPAXPAUsecurity_attributes@12@IIIPB_S@Z=__imp__CreateFileMappingW@24")
#pragma comment(linker,"/alternatename:__imp_?MapViewOfFile@win32@ufio@@YGPAXPAXIIII@Z=__imp__MapViewOfFile@20")
#pragma comment(linker,"/alternatename:__imp_?SetEndOfFile@win32@ufio@@YGHPAX@Z=__imp__SetEndOfFile@4")
#pragma comment(linker,"/alternatename:__imp_?UnmapViewOfFile@win32@ufio@@YGHPBX@Z=__imp__UnmapViewOfFile@4")
#pragma comment(linker,"/alternatename:__imp_?WriteFile@win32@ufio@@YGHPAXPBXIPAIPAUoverlapped@12@@Z=__imp__WriteFile@20")
#pragma comment(linker,"/alternatename:__imp_?ReadFile@win32@ufio@@YGHPAXPBXIPAIPAUoverlapped@12@@Z=__imp__ReadFile@20")
#pragma comment(linker,"/alternatename:__imp_?SetFilePointer@win32@ufio@@YGIPAXHPAHI@Z=__imp__SetFilePointer@16")
#pragma comment(linker,"/alternatename:__imp_?SetFilePointerEx@win32@ufio@@YGHPAX_JPA_JI@Z=__imp__SetFilePointerEx@20")
#pragma comment(linker,"/alternatename:__imp_?DuplicateHandle@win32@ufio@@YGHPAX00PAPAXIHI@Z=__imp__DuplicateHandle@28")
#pragma comment(linker,"/alternatename:__imp_?GetStdHandle@win32@ufio@@YGPAXI@Z=__imp__GetStdHandle@4")
#pragma comment(linker,"/alternatename:__imp_?CreatePipe@win32@ufio@@YGHPAPAX0PAUsecurity_attributes@12@I@Z=__imp__CreatePipe@16")
#pragma comment(linker,"/alternatename:__imp_?FreeLibrary@win32@ufio@@YGHPAX@Z=__imp__FreeLibrary@4")
#pragma comment(linker,"/alternatename:__imp_?GetProcAddress@win32@ufio@@YGP6GHX_EPAXPBD@Z=__imp__GetProcAddress@8")
#pragma comment(linker,"/alternatename:__imp_?GetModuleHandleA@win32@ufio@@YGPAXPBD@Z=__imp__GetModuleHandleA@4")
#pragma comment(linker,"/alternatename:__imp_?GetModuleHandleW@win32@ufio@@YGPAXPB_S@Z=__imp__GetModuleHandleW@4")
#pragma comment(linker,"/alternatename:__imp_?WaitForSingleObject@win32@ufio@@YGIPAXI@Z=__imp__WaitForSingleObject@8")
#pragma comment(linker,"/alternatename:__imp_?CancelIo@win32@ufio@@YGIPAX@Z=__imp__CancelIo@4")
#pragma comment(linker,"/alternatename:__imp_?GetFileInformationByHandle@win32@ufio@@YGHPIAXPIAUby_handle_file_information@12@@Z=__imp__GetFileInformationByHandle@8")
#pragma comment(linker,"/alternatename:__imp_?GetUserDefaultLocaleName@win32@ufio@@YGHPA_SH@Z=__imp__GetUserDefaultLocaleName@8")
#pragma comment(linker,"/alternatename:__imp_?GetUserDefaultLCID@win32@ufio@@YGIXZ=__imp__GetUserDefaultLCID@0")
#pragma comment(linker,"/alternatename:__imp_?GetSystemTimePreciseAsFileTime@win32@ufio@@YGXPAUfiletime@12@@Z=__imp__GetSystemTimePreciseAsFileTime@4")
#pragma comment(linker,"/alternatename:__imp_?GetSystemTimeAsFileTime@win32@ufio@@YGXPAUfiletime@12@@Z=__imp__GetSystemTimeAsFileTime@4")
#pragma comment(linker,"/alternatename:__imp_?QueryUnbiasedInterruptTime@win32@ufio@@YGHPA_K@Z=__imp__QueryUnbiasedInterruptTime@4")
#pragma comment(linker,"/alternatename:__imp_?QueryPerformanceCounter@win32@ufio@@YGHPA_J@Z=__imp__QueryPerformanceCounter@4")
#pragma comment(linker,"/alternatename:__imp_?QueryPerformanceFrequency@win32@ufio@@YGHPA_J@Z=__imp__QueryPerformanceFrequency@4")
#pragma comment(linker,"/alternatename:__imp_?GetProcessTimes@win32@ufio@@YGHPAXPAUfiletime@12@111@Z=__imp__GetProcessTimes@20")
#pragma comment(linker,"/alternatename:__imp_?GetThreadTimes@win32@ufio@@YGHPAXPAUfiletime@12@111@Z=__imp__GetThreadTimes@20")
#pragma comment(linker,"/alternatename:__imp_?GetHandleInformation@win32@ufio@@YGHPAXPAI@Z=__imp__GetHandleInformation@8")
#pragma comment(linker,"/alternatename:__imp_?SetHandleInformation@win32@ufio@@YGHPAXII@Z=__imp__SetHandleInformation@12")
#pragma comment(linker,"/alternatename:__imp_?GetTempPathA@win32@ufio@@YGIIPAD@Z=__imp__GetTempPathA@8")
#pragma comment(linker,"/alternatename:__imp_?GetTempPathW@win32@ufio@@YGIIPA_S@Z=__imp__GetTempPathW@8")
#pragma comment(linker,"/alternatename:__imp_?CreateFileA@win32@ufio@@YGPAXPBDIIPAUsecurity_attributes@12@IIPAX@Z=__imp__CreateFileA@28")
#pragma comment(linker,"/alternatename:__imp_?CreateFileW@win32@ufio@@YGPAXPB_SIIPAUsecurity_attributes@12@IIPAX@Z=__imp__CreateFileW@28")
#pragma comment(linker,"/alternatename:__imp_?CreateIoCompletionPort@win32@ufio@@YGPAXPAX0II@Z=__imp__CreateIoCompletionPort@16")
#pragma comment(linker,"/alternatename:__imp_?SystemFunction036@win32@ufio@@YGHPAXI@Z=__imp__SystemFunction036@8")
#pragma comment(linker,"/alternatename:__imp_?CloseHandle@win32@ufio@@YGHPAX@Z=__imp__CloseHandle@4")
#pragma comment(linker,"/alternatename:__imp_?LockFileEx@win32@ufio@@YGHPAXIIIIPAUoverlapped@12@@Z=__imp__LockFileEx@24")
#pragma comment(linker,"/alternatename:__imp_?UnlockFileEx@win32@ufio@@YGHPAXIIIPAUoverlapped@12@@Z=__imp__UnlockFileEx@20")
#pragma comment(linker,"/alternatename:__imp_?DeviceIoControl@win32@ufio@@YGHPAXI0I0I0PAUoverlapped@12@@Z=__imp__DeviceIoControl@32")
#pragma comment(linker,"/alternatename:__imp_?GetFileType@win32@ufio@@YGIPAX@Z=__imp__GetFileType@4")
#pragma comment(linker,"/alternatename:__imp_?GetACP@win32@ufio@@YGIXZ=__imp__GetACP@0")
#pragma comment(linker,"/alternatename:__imp_?GetEnvironmentVariableA@win32@ufio@@YGIPBDPADI@Z=__imp__GetEnvironmentVariableA@12")
#pragma comment(linker,"/alternatename:__imp_?GetEnvironmentVariableW@win32@ufio@@YGIPB_SPA_SI@Z=__imp__GetEnvironmentVariableW@12")
#pragma comment(linker,"/alternatename:__imp_?MessageBoxA@win32@ufio@@YGIPAXPBD1I@Z=__imp__MessageBoxA@16")
#pragma comment(linker,"/alternatename:__imp_?MessageBoxW@win32@ufio@@YGIPAXPB_S1I@Z=__imp__MessageBoxW@16")
#pragma comment(linker,"/alternatename:__imp_?GetConsoleMode@win32@ufio@@YGHPAXPAI@Z=__imp__GetConsoleMode@8")
#pragma comment(linker,"/alternatename:__imp_?SetConsoleMode@win32@ufio@@YGHPAXI@Z=__imp__SetConsoleMode@8")
#pragma comment(linker,"/alternatename:__imp_?ReadConsoleA@win32@ufio@@YGHPAX0IPAI0@Z=__imp__ReadConsoleA@20")
#pragma comment(linker,"/alternatename:__imp_?ReadConsoleW@win32@ufio@@YGHPAX0IPAI0@Z=__imp__ReadConsoleW@20")
#pragma comment(linker,"/alternatename:__imp_?WriteConsoleA@win32@ufio@@YGHPAXPBXIPAI0@Z=__imp__WriteConsoleA@20")
#pragma comment(linker,"/alternatename:__imp_?WriteConsoleW@win32@ufio@@YGHPAXPBXIPAI0@Z=__imp__WriteConsoleW@20")
#pragma comment(linker,"/alternatename:__imp_?GetConsoleScreenBufferInfo@win32@ufio@@YGHPAXPAUconsole_screen_buffer_info@12@@Z=__imp__GetConsoleScreenBufferInfo@8")
#pragma comment(linker,"/alternatename:__imp_?ScrollConsoleScreenBufferA@win32@ufio@@YGHPAXPBUsmall_rect@12@1Ucoord@12@PBUchar_info@12@@Z=__imp__ScrollConsoleScreenBufferA@20")
#pragma comment(linker,"/alternatename:__imp_?ScrollConsoleScreenBufferW@win32@ufio@@YGHPAXPBUsmall_rect@12@1Ucoord@12@PBUchar_info@12@@Z=__imp__ScrollConsoleScreenBufferW@20")
#pragma comment(linker,"/alternatename:__imp_?SetConsoleCursorPosition@win32@ufio@@YGHPAXUcoord@12@@Z=__imp__SetConsoleCursorPosition@8")
#pragma comment(linker,"/alternatename:__imp_?InitializeCriticalSection@win32@ufio@@YGXPAX@Z=__imp__InitializeCriticalSection@4")
#pragma comment(linker,"/alternatename:__imp_?EnterCriticalSection@win32@ufio@@YGXPAX@Z=__imp__EnterCriticalSection@4")
#pragma comment(linker,"/alternatename:__imp_?TryEnterCriticalSection@win32@ufio@@YGHPAX@Z=__imp__TryEnterCriticalSection@4")
#pragma comment(linker,"/alternatename:__imp_?LeaveCriticalSection@win32@ufio@@YGXPAX@Z=__imp__LeaveCriticalSection@4")
#pragma comment(linker,"/alternatename:__imp_?DeleteCriticalSection@win32@ufio@@YGXPAX@Z=__imp__DeleteCriticalSection@4")
#pragma comment(linker,"/alternatename:__imp_?WSADuplicateSocketA@win32@ufio@@YGHPAXIPAUwsaprotocol_infoa@12@@Z=__imp__WSADuplicateSocketA@12")
#pragma comment(linker,"/alternatename:__imp_?WSADuplicateSocketW@win32@ufio@@YGXPAXIPAUwsaprotocol_infow@12@@Z=__imp__WSADuplicateSocketW@12")
#pragma comment(linker,"/alternatename:__imp_?WSACleanup@win32@ufio@@YGHXZ=__imp__WSACleanup@0")
#pragma comment(linker,"/alternatename:__imp_?WSAStartup@win32@ufio@@YGHIPAUwsadata@12@@Z=__imp__WSAStartup@8")
#pragma comment(linker,"/alternatename:__imp_?WSAGetLastError@win32@ufio@@YGHXZ=__imp__WSAGetLastError@0")
#pragma comment(linker,"/alternatename:__imp_?closesocket@win32@ufio@@YGHI@Z=__imp__closesocket@4")
#pragma comment(linker,"/alternatename:__imp_?WSASocketW@win32@ufio@@YGIHHHPAUwsaprotocol_infow@12@II@Z=__imp__WSASocketW@24")
#pragma comment(linker,"/alternatename:__imp_?WSASocketA@win32@ufio@@YGIHHHPAUwsaprotocol_infoa@12@II@Z=__imp__WSASocketA@24")
#pragma comment(linker,"/alternatename:__imp_?bind@win32@ufio@@YGHIPBXH@Z=__imp__bind@12")
#pragma comment(linker,"/alternatename:__imp_?listen@win32@ufio@@YGHIH@Z=__imp__listen@8")
#pragma comment(linker,"/alternatename:__imp_?WSAAccept@win32@ufio@@YGIIPBXPAHP6GXPAUwsabuf@12@2PAUqualityofservice@12@322PAII@_EI@Z=__imp__WSAAccept@20")
#pragma comment(linker,"/alternatename:__imp_?ioctlsocket@win32@ufio@@YGHIJPAI@Z=__imp__ioctlsocket@12")
#pragma comment(linker,"/alternatename:__imp_?sendto@win32@ufio@@YGHIPBDHHPBXH@Z=__imp__sendto@24")
#pragma comment(linker,"/alternatename:__imp_?WSASend@win32@ufio@@YGHIPAUwsabuf@12@IPAIIPAUoverlapped@12@P6GXII2I@_E@Z=__imp__WSASend@28")
#pragma comment(linker,"/alternatename:__imp_?WSASendMsg@win32@ufio@@YGHIPAUwsamsg@12@IPAIPAUoverlapped@12@P6GXII2I@_E@Z=__imp__WSASendMsg@24")
#pragma comment(linker,"/alternatename:__imp_?WSASendTo@win32@ufio@@YGHIPAUwsabuf@12@IPAIIPBXHPAUoverlapped@12@P6GXII3I@_E@Z=__imp__WSASendTo@36")
#pragma comment(linker,"/alternatename:__imp_?recv@win32@ufio@@YGHIPADHH@Z=__imp__recv@16")
#pragma comment(linker,"/alternatename:__imp_?recvfrom@win32@ufio@@YGHIPADHHPAXPAH@Z=__imp__recvfrom@24")
#pragma comment(linker,"/alternatename:__imp_?WSARecv@win32@ufio@@YGHIPAUwsabuf@12@IPAI1PAUoverlapped@12@P6GXII2I@_E@Z=__imp__WSARecv@28")
#pragma comment(linker,"/alternatename:__imp_?WSARecvFrom@win32@ufio@@YGHIPAUwsabuf@12@IPAI1PAXPAHPAUoverlapped@12@P6GXII4I@_E@Z=__imp__WSARecvFrom@36")
#pragma comment(linker,"/alternatename:__imp_?connect@win32@ufio@@YGHIPBXH@Z=__imp__connect@12")
#pragma comment(linker,"/alternatename:__imp_?WSAConnect@win32@ufio@@YGHIPBXHPAUwsabuf@12@1PAUqualityofservice@12@2@Z=__imp__WSAConnect@28")
#pragma comment(linker,"/alternatename:__imp_?shutdown@win32@ufio@@YGHIPBXH@Z=__imp__shutdown@8")
#pragma comment(linker,"/alternatename:__imp_?GetCurrentProcessId@win32@ufio@@YGIXZ=__imp__GetCurrentProcessId@0")
#pragma comment(linker,"/alternatename:__imp_?FlushFileBuffers@win32@ufio@@YGHPAX@Z=__imp__FlushFileBuffers@4")
#pragma comment(linker,"/alternatename:__imp_?GetQueuedCompletionStatus@win32@ufio@@YGHPAXPAI1PAUoverlapped@12@I@Z=__imp__GetQueuedCompletionStatus@20")
#pragma comment(linker,"/alternatename:__imp_?freeaddrinfo@win32@ufio@@YGXPAU?$win32_family_addrinfo@$0A@@12@@Z=__imp__freeaddrinfo@4")
#pragma comment(linker,"/alternatename:__imp_?FreeAddrInfoW@win32@ufio@@YGXPAU?$win32_family_addrinfo@$00@12@@Z=__imp__FreeAddrInfoW@4")
#pragma comment(linker,"/alternatename:__imp_?getaddrinfo@win32@ufio@@YGHPBD0PBU?$win32_family_addrinfo@$0A@@12@PAPAU312@@Z=__imp__getaddrinfo@16")
#pragma comment(linker,"/alternatename:__imp_?GetAddrInfoW@win32@ufio@@YGHPB_S0PBU?$win32_family_addrinfo@$00@12@PAPAU312@@Z=__imp__GetAddrInfoW@16")
#pragma comment(linker,"/alternatename:__imp_?CryptAcquireContextA@win32@ufio@@YGHPAIPB_Q1II@Z=__imp__CryptAcquireContextA@20")
#pragma comment(linker,"/alternatename:__imp_?CryptAcquireContextW@win32@ufio@@YGHPAIPB_S1II@Z=__imp__CryptAcquireContextW@20")
#pragma comment(linker,"/alternatename:__imp_?CryptReleaseContext@win32@ufio@@YGHII@Z=__imp__CryptReleaseContext@8")
#pragma comment(linker,"/alternatename:__imp_?CryptGenRandom@win32@ufio@@YGHIIPAE@Z=__imp__CryptGenRandom@12")
#pragma comment(linker,"/alternatename:__imp_?RegOpenKeyA@win32@ufio@@YGHIPB_QPAI@Z=__imp__RegOpenKeyA@12")
#pragma comment(linker,"/alternatename:__imp_?RegOpenKeyW@win32@ufio@@YGHIPB_SPAI@Z=__imp__RegOpenKeyW@12")
#pragma comment(linker,"/alternatename:__imp_?RegQueryValueExA@win32@ufio@@YGHIPB_QPAI1PAX1@Z=__imp__RegQueryValueExA@24")
#pragma comment(linker,"/alternatename:__imp_?RegQueryValueExW@win32@ufio@@YGHIPB_SPAI1PAX1@Z=__imp__RegQueryValueExW@24")
#pragma comment(linker,"/alternatename:__imp_?RegCloseKey@win32@ufio@@YGHI@Z=__imp__RegCloseKey@4")
#pragma comment(linker,"/alternatename:__imp_?GetTimeZoneInformation@win32@ufio@@YGIPAUtime_zone_information@12@@Z=__imp__GetTimeZoneInformation@4")
#pragma comment(linker,"/alternatename:__imp_?SetConsoleCP@win32@ufio@@YGHI@Z=__imp__SetConsoleCP@4")
#pragma comment(linker,"/alternatename:__imp_?SetConsoleOutputCP@win32@ufio@@YGHI@Z=__imp__SetConsoleOutputCP@4")
#pragma comment(linker,"/alternatename:__imp_?GetConsoleCP@win32@ufio@@YGIXZ=__imp__GetConsoleCP@0")
#pragma comment(linker,"/alternatename:__imp_?GetConsoleOutputCP@win32@ufio@@YGIXZ=__imp__GetConsoleOutputCP@0")
#pragma comment(linker,"/alternatename:__imp_?AcquireSRWLockExclusive@win32@ufio@@YGXPAX@Z=__imp__AcquireSRWLockExclusive@4")
#pragma comment(linker,"/alternatename:__imp_?TryAcquireSRWLockExclusive@win32@ufio@@YGIPAX@Z=__imp__TryAcquireSRWLockExclusive@4")
#pragma comment(linker,"/alternatename:__imp_?ReleaseSRWLockExclusive@win32@ufio@@YGXPAX@Z=__imp__ReleaseSRWLockExclusive@4")
#pragma comment(linker,"/alternatename:__imp_?GetSystemInfo@win32@ufio@@YGXPAUsystem_info@12@@Z=__imp__GetSystemInfo@4")
#pragma comment(linker,"/alternatename:__imp_?SetFileInformationByHandle@win32@ufio@@YGHPAXW4file_info_by_handle_class@12@0I@Z=__imp__SetFileInformationByHandle@16")
#pragma comment(linker,"/alternatename:__imp_?SetFileTime@win32@ufio@@YGHPAXPBUfiletime@12@11@Z=__imp__SetFileTime@16")
#pragma comment(linker,"/alternatename:__imp_?CreateProcessW@win32@ufio@@YGHPB_SPA_SPAUsecurity_attributes@12@2HIPAX0PAUstartupinfow@12@PAUprocess_information@12@@Z=__imp__CreateProcessW@40")
#pragma comment(linker,"/alternatename:__imp_?CreateProcessA@win32@ufio@@YGHPBDPADPAUsecurity_attributes@12@2HIPAXPB_SPAUstartupinfoa@12@PAUprocess_information@12@@Z=__imp__CreateProcessA@40")
#pragma comment(linker,"/alternatename:__imp_?K32GetMappedFileNameW@win32@ufio@@YGIPAX0PA_SI@Z=__imp__K32GetMappedFileNameW@16")
#pragma comment(linker,"/alternatename:__imp_?K32GetMappedFileNameA@win32@ufio@@YGIPAX0PADI@Z=__imp__K32GetMappedFileNameA@16")
#pragma comment(linker,"/alternatename:__imp_?GetMappedFileNameW@win32@ufio@@YGIPAX0PA_SI@Z=__imp__GetMappedFileNameW@16")
#pragma comment(linker,"/alternatename:__imp_?GetMappedFileNameA@win32@ufio@@YGIPAX0PADI@Z=__imp__GetMappedFileNameA@16")
#pragma comment(linker,"/alternatename:__imp_?GetExitCodeProcess@win32@ufio@@YGHPAXPAI@Z=__imp__GetExitCodeProcess@8")
#pragma comment(linker,"/alternatename:__imp_?QueryDosDeviceW@win32@ufio@@YGIPB_SPA_SI@Z=__imp__QueryDosDeviceW@12")
#pragma comment(linker,"/alternatename:__imp_?QueryDosDeviceA@win32@ufio@@YGIPBDPADI@Z=__imp__QueryDosDeviceA@12")
#pragma comment(linker,"/alternatename:__imp_?FindFirstFileW@win32@ufio@@YGPAXPB_SPAUwin32_find_dataw@12@@Z=__imp__FindFirstFileW@8")
#pragma comment(linker,"/alternatename:__imp_?FindFirstFileA@win32@ufio@@YGPAXPBDPAUwin32_find_dataa@12@@Z=__imp__FindFirstFileA@8")
#pragma comment(linker,"/alternatename:__imp_?FindNextFileW@win32@ufio@@YGHPAXPAUwin32_find_dataw@12@@Z=__imp__FindNextFileW@8")
#pragma comment(linker,"/alternatename:__imp_?FindNextFileA@win32@ufio@@YGHPAXPAUwin32_find_dataa@12@@Z=__imp__FindNextFileA@8")
#pragma comment(linker,"/alternatename:__imp_?FindClose@win32@ufio@@YGHPAX@Z=__imp__FindClose@4")
#pragma comment(linker,"/alternatename:__imp_?ShellExecuteW@win32@ufio@@YGPAXPAXPB_S111H@Z=__imp__ShellExecuteW@24")
#pragma comment(linker,"/alternatename:__imp_?ShellExecuteA@win32@ufio@@YGPAXPAXPBD111H@Z=__imp__ShellExecuteA@24")
#pragma comment(linker,"/alternatename:__imp_?DeleteFileW@win32@ufio@@YGHPB_S@Z=__imp__DeleteFileW@4")
#pragma comment(linker,"/alternatename:__imp_?DeleteFileA@win32@ufio@@YGHPBD@Z=__imp__DeleteFileA@4")
#pragma comment(linker,"/alternatename:__imp_?RemoveDirectoryW@win32@ufio@@YGHPB_S@Z=__imp__RemoveDirectoryW@4")
#pragma comment(linker,"/alternatename:__imp_?RemoveDirectoryA@win32@ufio@@YGHPBD@Z=__imp__RemoveDirectoryA@4")
#pragma comment(linker,"/alternatename:__imp_?CreateDirectoryW@win32@ufio@@YGHPB_SPAUsecurity_attributes@12@@Z=__imp__CreateDirectoryW@8")
#pragma comment(linker,"/alternatename:__imp_?CreateDirectoryA@win32@ufio@@YGHPBDPAUsecurity_attributes@12@@Z=__imp__CreateDirectoryA@8")
#pragma comment(linker,"/alternatename:__imp_?SetFileAttributesW@win32@ufio@@YGHPB_SI@Z=__imp__SetFileAttributesW@8")
#pragma comment(linker,"/alternatename:__imp_?SetFileAttributesA@win32@ufio@@YGHPBDI@Z=__imp__SetFileAttributesA@8")
#pragma comment(linker,"/alternatename:__imp_?GetFileAttributesW@win32@ufio@@YGIPB_S@Z=__imp__GetFileAttributesW@4")
#pragma comment(linker,"/alternatename:__imp_?GetFileAttributesA@win32@ufio@@YGIPBD@Z=__imp__GetFileAttributesA@4")
#pragma comment(linker,"/alternatename:__imp_?CopyFileW@win32@ufio@@YGHPB_S0H@Z=__imp__CopyFileW@12")
#pragma comment(linker,"/alternatename:__imp_?CopyFileA@win32@ufio@@YGHPBD0H@Z=__imp__CopyFileA@12")
#pragma comment(linker,"/alternatename:__imp_?MoveFileW@win32@ufio@@YGHPB_S0@Z=__imp__MoveFileW@8")
#pragma comment(linker,"/alternatename:__imp_?MoveFileA@win32@ufio@@YGHPBD0@Z=__imp__MoveFileA@8")
// NT
#pragma comment(linker,"/alternatename:__imp_?rtl_nt_status_to_dos_error@nt@win32@ufio@@YGII@Z=__imp__RtlNtStatusToDosError@4")
#pragma comment(linker,"/alternatename:__imp_?NtClose@nt@win32@ufio@@YGIPAX@Z=__imp__NtClose@4")
#pragma comment(linker,"/alternatename:__imp_?ZwClose@nt@win32@ufio@@YGIPAX@Z=__imp__ZwClose@4")
#pragma comment(linker,"/alternatename:__imp_?NtCreateFile@nt@win32@ufio@@YGIPAPAXIPAUobject_attributes@123@PAUio_status_block@123@PA_JIIIIPAXI@Z=__imp__NtCreateFile@44")
#pragma comment(linker,"/alternatename:__imp_?ZwCreateFile@nt@win32@ufio@@YGIPAPAXIPAUobject_attributes@123@PAUio_status_block@123@PA_JIIIIPAXI@Z=__imp__ZwCreateFile@44")
#pragma comment(linker,"/alternatename:__imp_?NtCreateSection@nt@win32@ufio@@YGIPIAPAXIPIAUobject_attributes@123@PA_KIIPIAX@Z=__imp__NtCreateSection@28")
#pragma comment(linker,"/alternatename:__imp_?ZwCreateSection@nt@win32@ufio@@YGIPIAPAXIPIAUobject_attributes@123@PA_KIIPIAX@Z=__imp__ZwCreateSection@28")
#pragma comment(linker,"/alternatename:__imp_?NtQueryInformationProcess@nt@win32@ufio@@YGIPIAXW4process_information_class@123@PAXIPAI@Z=__imp__NtQueryInformationProcess@20")
#pragma comment(linker,"/alternatename:__imp_?ZwQueryInformationProcess@nt@win32@ufio@@YGIPIAXW4process_information_class@123@PAXIPAI@Z=__imp__ZwQueryInformationProcess@20")
#pragma comment(linker,"/alternatename:__imp_?NtWriteFile@nt@win32@ufio@@YGIPAX0P6AX0PAUio_status_block@123@I@_E01PBXIPA_JPAI@Z=__imp__NtWriteFile@36")
#pragma comment(linker,"/alternatename:__imp_?ZwWriteFile@nt@win32@ufio@@YGIPAX0P6AX0PAUio_status_block@123@I@_E01PBXIPA_JPAI@Z=__imp__ZwWriteFile@36")
#pragma comment(linker,"/alternatename:__imp_?NtReadFile@nt@win32@ufio@@YGIPAX0P6AX0PAUio_status_block@123@I@_E01PBXIPA_JPAI@Z=__imp__NtReadFile@36")
#pragma comment(linker,"/alternatename:__imp_?ZwReadFile@nt@win32@ufio@@YGIPAX0P6AX0PAUio_status_block@123@I@_E01PBXIPA_JPAI@Z=__imp__ZwReadFile@36")
#pragma comment(linker,"/alternatename:__imp_?NtQueryDirectoryFile@nt@win32@ufio@@YGIPAX0P6AX0PAUio_status_block@123@I@_E010IW4file_information_class@123@HPAUunicode_string@123@H@Z=__imp__NtQueryDirectoryFile@44")
#pragma comment(linker,"/alternatename:__imp_?ZwQueryDirectoryFile@nt@win32@ufio@@YGIPAX0P6AX0PAUio_status_block@123@I@_E010IW4file_information_class@123@HPAUunicode_string@123@H@Z=__imp__ZwQueryDirectoryFile@44")
#pragma comment(linker,"/alternatename:__imp_?NtQuerySection@nt@win32@ufio@@YGIPAXW4section_information_class@123@0IPAI@Z=__imp__NtQuerySection@20")
#pragma comment(linker,"/alternatename:__imp_?ZwQuerySection@nt@win32@ufio@@YGIPAXW4section_information_class@123@0IPAI@Z=__imp__ZwQuerySection@20")
#pragma comment(linker,"/alternatename:__imp_?NtQueryInformationFile@nt@win32@ufio@@YGIPIAXPIAUio_status_block@123@0IW4file_information_class@123@@Z=__imp__NtQueryInformationFile@20")
#pragma comment(linker,"/alternatename:__imp_?ZwQueryInformationFile@nt@win32@ufio@@YGIPIAXPIAUio_status_block@123@0IW4file_information_class@123@@Z=__imp__ZwQueryInformationFile@20")
#pragma comment(linker,"/alternatename:__imp_?NtSetInformationFile@nt@win32@ufio@@YGIPIAXPIAUio_status_block@123@0IW4file_information_class@123@@Z=__imp__NtSetInformationFile@20")
#pragma comment(linker,"/alternatename:__imp_?ZwSetInformationFile@nt@win32@ufio@@YGIPIAXPIAUio_status_block@123@0IW4file_information_class@123@@Z=__imp__ZwSetInformationFile@20")
#pragma comment(linker,"/alternatename:__imp_?NtDuplicateObject@nt@win32@ufio@@YGIPAX00PAPAXIII@Z=__imp__NtDuplicateObject@28")
#pragma comment(linker,"/alternatename:__imp_?ZwDuplicateObject@nt@win32@ufio@@YGIPAX00PAPAXIII@Z=__imp__ZwDuplicateObject@28")
#pragma comment(linker,"/alternatename:__imp_?NtWaitForSingleObject@nt@win32@ufio@@YGIPAXHPA_K@Z=__imp__NtWaitForSingleObject@12")
#pragma comment(linker,"/alternatename:__imp_?ZwWaitForSingleObject@nt@win32@ufio@@YGIPAXHPA_K@Z=__imp__ZwWaitForSingleObject@12")
#pragma comment(linker,"/alternatename:__imp_?NtSetSystemTime@nt@win32@ufio@@YGIPA_K0@Z=__imp__NtSetSystemTime@8")
#pragma comment(linker,"/alternatename:__imp_?ZwSetSystemTime@nt@win32@ufio@@YGIPA_K0@Z=__imp__ZwSetSystemTime@8")
#pragma comment(linker,"/alternatename:__imp_?NtCreateProcess@nt@win32@ufio@@YGIPAPAXIPAUobject_attributes@123@PAXI222@Z=__imp__NtCreateProcess@32")
#pragma comment(linker,"/alternatename:__imp_?ZwCreateProcess@nt@win32@ufio@@YGIPAPAXIPAUobject_attributes@123@PAXI222@Z=__imp__ZwCreateProcess@32")
#pragma comment(linker,"/alternatename:__imp_?rtl_dos_path_name_to_nt_path_name_u@nt@win32@ufio@@YGEPB_SPAUunicode_string@123@PAPB_SPAUrtl_relative_name_u@123@@Z=__imp__RtlDosPathNameToNtPathName_U@16")
#pragma comment(linker,"/alternatename:__imp_?rtl_dos_path_name_to_nt_path_name_u_with_status@nt@win32@ufio@@YGIPB_SPAUunicode_string@123@PAPB_SPAUrtl_relative_name_u@123@@Z=__imp__RtlDosPathNameToNtPathName_U_WithStatus@16")
#pragma comment(linker,"/alternatename:__imp_?rtl_free_unicode_string@nt@win32@ufio@@YGXPAUunicode_string@123@@Z=__imp__RtlFreeUnicodeString@4")
#pragma comment(linker,"/alternatename:__imp_?RtlInitializeCriticalSection@nt@win32@ufio@@YGXPAX@Z=__imp__RtlInitializeCriticalSection@4")
#pragma comment(linker,"/alternatename:__imp_?RtlEnterCriticalSection@nt@win32@ufio@@YGXPAX@Z=__imp__RtlEnterCriticalSection@4")
#pragma comment(linker,"/alternatename:__imp_?RtlTryEnterCriticalSection@nt@win32@ufio@@YGHPAX@Z=__imp__RtlTryEnterCriticalSection@4")
#pragma comment(linker,"/alternatename:__imp_?RtlLeaveCriticalSection@nt@win32@ufio@@YGXPAX@Z=__imp__RtlLeaveCriticalSection@4")
#pragma comment(linker,"/alternatename:__imp_?RtlDeleteCriticalSection@nt@win32@ufio@@YGXPAX@Z=__imp__RtlDeleteCriticalSection@4")
#pragma comment(linker,"/alternatename:__imp_?RtlCreateUserThread@nt@win32@ufio@@YGIPAX0HIII00PAPAXPAUclient_id@123@@Z=__imp__RtlCreateUserThread@40")
#pragma comment(linker,"/alternatename:__imp_?NtResumeThread@nt@win32@ufio@@YGIPAXPAI@Z=__imp__NtResumeThread@8")
#pragma comment(linker,"/alternatename:__imp_?ZwResumeThread@nt@win32@ufio@@YGIPAXPAI@Z=__imp__ZwResumeThread@8")
#pragma comment(linker,"/alternatename:__imp_?NtLockFile@nt@win32@ufio@@YGIPAX0P6AX0PAUio_status_block@123@I@_E01PA_J3IEE@Z=__imp__NtLockFile@40")
#pragma comment(linker,"/alternatename:__imp_?ZwLockFile@nt@win32@ufio@@YGIPAX0P6AX0PAUio_status_block@123@I@_E01PA_J3IEE@Z=__imp__ZwLockFile@40")
#pragma comment(linker,"/alternatename:__imp_?NtUnlockFile@nt@win32@ufio@@YGIPAXPAUio_status_block@123@PA_J2I@Z=__imp__NtUnlockFile@20")
#pragma comment(linker,"/alternatename:__imp_?ZwUnlockFile@nt@win32@ufio@@YGIPAXPAUio_status_block@123@PA_J2I@Z=__imp__ZwUnlockFile@20")
#pragma comment(linker,"/alternatename:__imp_?NtFlushBuffersFile@nt@win32@ufio@@YGIPAXPAUio_status_block@123@@Z=__imp__NtFlushBuffersFile@8")
#pragma comment(linker,"/alternatename:__imp_?ZwFlushBuffersFile@nt@win32@ufio@@YGIPAXPAUio_status_block@123@@Z=__imp__ZwFlushBuffersFile@8")
#pragma comment(linker,"/alternatename:__imp_?NtFlushBuffersFileEx@nt@win32@ufio@@YGIPAXI0IPAUio_status_block@123@@Z=__imp__NtFlushBuffersFileEx@20")
#pragma comment(linker,"/alternatename:__imp_?ZwFlushBuffersFileEx@nt@win32@ufio@@YGIPAXI0IPAUio_status_block@123@@Z=__imp__ZwFlushBuffersFileEx@20")
#pragma comment(linker,"/alternatename:__imp_?DbgPrint@nt@win32@ufio@@YAIPBDZZ=__imp__DbgPrint")
#pragma comment(linker,"/alternatename:__imp_?DbgPrintEx@nt@win32@ufio@@YAIIIPBDZZ=__imp__DbgPrintEx")
#pragma comment(linker,"/alternatename:__imp_?RtlCreateProcessParameters@nt@win32@ufio@@YGIPAPAUrtl_user_process_parameters@123@PAUunicode_string@123@111PAX1111@Z=__imp__RtlCreateProcessParameters@40")
#pragma comment(linker,"/alternatename:__imp_?RtlCreateProcessParametersEx@nt@win32@ufio@@YGIPAPAUrtl_user_process_parameters@123@PAUunicode_string@123@111PAX1111I@Z=__imp__RtlCreateProcessParametersEx@44")
#pragma comment(linker,"/alternatename:__imp_?RtlDestroyProcessParameters@nt@win32@ufio@@YGIPAUrtl_user_process_parameters@123@@Z=__imp__RtlDestroyProcessParameters@4")
#pragma comment(linker,"/alternatename:__imp_?NtCreateUserProcess@nt@win32@ufio@@YGIPAX0IIPAUobject_attributes@123@1IIPAUrtl_user_process_parameters@123@PAUps_create_info@123@PAUps_attribute_list@123@@Z=__imp__NtCreateUserProcess@44")
#pragma comment(linker,"/alternatename:__imp_?ZwCreateUserProcess@nt@win32@ufio@@YGIPAX0IIPAUobject_attributes@123@1IIPAUrtl_user_process_parameters@123@PAUps_create_info@123@PAUps_attribute_list@123@@Z=__imp__ZwCreateUserProcess@44")
#pragma comment(linker,"/alternatename:__imp_?RtlCreateUserProcess@nt@win32@ufio@@YGIPAUunicode_string@123@IPAUrtl_user_process_parameters@123@PAUsecurity_descriptor@123@2PAXE33PAUrtl_user_process_information@123@@Z=__imp__RtlCreateUserProcess@40")
#pragma comment(linker,"/alternatename:__imp_?NtMapViewOfSection@nt@win32@ufio@@YGIPAX0PAPAXIIPBTlarge_integer@123@PAIW4section_inherit@123@II@Z=__imp__NtMapViewOfSection@40")
#pragma comment(linker,"/alternatename:__imp_?ZwMapViewOfSection@nt@win32@ufio@@YGIPAX0PAPAXIIPBTlarge_integer@123@PAIW4section_inherit@123@II@Z=__imp__ZwMapViewOfSection@40")
#pragma comment(linker,"/alternatename:__imp_?NtUnmapViewOfSection@nt@win32@ufio@@YGIPAX0@Z=__imp__NtUnmapViewOfSection@8")
#pragma comment(linker,"/alternatename:__imp_?ZwUnmapViewOfSection@nt@win32@ufio@@YGIPAX0@Z=__imp__ZwUnmapViewOfSection@8")
#pragma comment(linker,"/alternatename:__imp_?NtReadVirtualMemory@nt@win32@ufio@@YGIPAX00IPAI@Z=__imp__NtReadVirtualMemory@20")
#pragma comment(linker,"/alternatename:__imp_?ZwReadVirtualMemory@nt@win32@ufio@@YGIPAX00IPAI@Z=__imp__ZwReadVirtualMemory@20")
#pragma comment(linker,"/alternatename:__imp_?NtWriteVirtualMemory@nt@win32@ufio@@YGIPAX00IPAI@Z=__imp__NtWriteVirtualMemory@20")
#pragma comment(linker,"/alternatename:__imp_?ZwWriteVirtualMemory@nt@win32@ufio@@YGIPAX00IPAI@Z=__imp__ZwWriteVirtualMemory@20")
#pragma comment(linker,"/alternatename:__imp_?RtlAcquirePebLock@nt@win32@ufio@@YGIXZ=__imp__RtlAcquirePebLock@0")
#pragma comment(linker,"/alternatename:__imp_?RtlReleasePebLock@nt@win32@ufio@@YGIXZ=__imp__RtlReleasePebLock@0")
#pragma comment(linker,"/alternatename:__imp_?NtAllocateVirtualMemory@nt@win32@ufio@@YGIPAXPAPAXIPAIII@Z=__imp__NtAllocateVirtualMemory@24")
#pragma comment(linker,"/alternatename:__imp_?ZwAllocateVirtualMemory@nt@win32@ufio@@YGIPAXPAPAXIPAIII@Z=__imp__ZwAllocateVirtualMemory@24")
#pragma comment(linker,"/alternatename:__imp_?RtlInitUnicodeString@nt@win32@ufio@@YGIPAUunicode_string@123@PA_S@Z=__imp__RtlInitUnicodeString@8")
#pragma comment(linker,"/alternatename:__imp_?CsrClientCallServer@nt@win32@ufio@@YGIPAX0II@Z=__imp__CsrClientCallServer@16")
#pragma comment(linker,"/alternatename:__imp_?RtlAcquireSRWLockExclusive@nt@win32@ufio@@YGXPAX@Z=__imp__RtlAcquireSRWLockExclusive@4")
#pragma comment(linker,"/alternatename:__imp_?RtlTryAcquireSRWLockExclusive@nt@win32@ufio@@YGIPAX@Z=__imp__RtlTryAcquireSRWLockExclusive@4")
#pragma comment(linker,"/alternatename:__imp_?RtlReleaseSRWLockExclusive@nt@win32@ufio@@YGXPAX@Z=__imp__RtlReleaseSRWLockExclusive@4")
#pragma comment(linker,"/alternatename:__imp_?NtQueryObject@nt@win32@ufio@@YGIPAXW4object_information_class@123@0IPAI@Z=__imp__NtQueryObject@20")
#pragma comment(linker,"/alternatename:__imp_?ZwQueryObject@nt@win32@ufio@@YGIPAXW4object_information_class@123@0IPAI@Z=__imp__ZwQueryObject@20")
#pragma comment(linker,"/alternatename:__imp_?NtQuerySystemInformation@nt@win32@ufio@@YGIW4system_information_class@123@PAXIPAI@Z=__imp__NtQuerySystemInformation@16")
#pragma comment(linker,"/alternatename:__imp_?ZwQuerySystemInformation@nt@win32@ufio@@YGIW4system_information_class@123@PAXIPAI@Z=__imp__ZwQuerySystemInformation@16")
#pragma comment(linker,"/alternatename:__imp_?NtFreeVirtualMemory@nt@win32@ufio@@YGIPAXPAPAXPAII@Z=__imp__NtFreeVirtualMemory@16")
#pragma comment(linker,"/alternatename:__imp_?ZwFreeVirtualMemory@nt@win32@ufio@@YGIPAXPAPAXPAII@Z=__imp__ZwFreeVirtualMemory@16")
#pragma comment(linker,"/alternatename:__imp_?NtQueryVolumeInformationFile@nt@win32@ufio@@YGIPIAXPIAUio_status_block@123@0IW4fs_information_class@123@@Z=__imp__NtQueryVolumeInformationFile@20")
#pragma comment(linker,"/alternatename:__imp_?ZwQueryVolumeInformationFile@nt@win32@ufio@@YGIPIAXPIAUio_status_block@123@0IW4fs_information_class@123@@Z=__imp__ZwQueryVolumeInformationFile@20")
#pragma comment(linker,"/alternatename:__imp_?NtFsControlFile@nt@win32@ufio@@YGIPIAX0PIAP6AXPAXPAUio_status_block@123@I@_E12I1I1I@Z=__imp__NtFsControlFile@40")
#pragma comment(linker,"/alternatename:__imp_?ZwFsControlFile@nt@win32@ufio@@YGIPIAX0PIAP6AXPAXPAUio_status_block@123@I@_E12I1I1I@Z=__imp__ZwFsControlFile@40")
#pragma comment(linker,"/alternatename:__imp_?NtCreateNamedPipeFile@nt@win32@ufio@@YGIPIAPAXIPIAUobject_attributes@123@PIAUio_status_block@123@IIIIIIIIIPA_J@Z=__imp__NtCreateNamedPipeFile@56")
#pragma comment(linker,"/alternatename:__imp_?ZwCreateNamedPipeFile@nt@win32@ufio@@YGIPIAPAXIPIAUobject_attributes@123@PIAUio_status_block@123@IIIIIIIIIPA_J@Z=__imp__ZwCreateNamedPipeFile@56")
#pragma comment(linker,"/alternatename:__imp_?NtQueryPerformanceCounter@nt@win32@ufio@@YGIPA_J0@Z=__imp__NtQueryPerformanceCounter@8")
#pragma comment(linker,"/alternatename:__imp_?ZwQueryPerformanceCounter@nt@win32@ufio@@YGIPA_J0@Z=__imp__ZwQueryPerformanceCounter@8")
#pragma comment(linker,"/alternatename:__imp_?RtlGetSystemTimePrecise@nt@win32@ufio@@YG_JXZ=__imp__RtlGetSystemTimePrecise@0")
#pragma comment(linker,"/alternatename:__imp_?NtQueryInformationThread@nt@win32@ufio@@YGHPIAXW4thread_information_class@123@PAXIPAI@Z=__imp__NtQueryInformationThread@20")
#pragma comment(linker,"/alternatename:__imp_?ZwQueryInformationThread@nt@win32@ufio@@YGHPIAXW4thread_information_class@123@PAXIPAI@Z=__imp__ZwQueryInformationThread@20")
#pragma comment(linker,"/alternatename:__imp_?RtlAdjustPrivilege@nt@win32@ufio@@YGHIEEPAE@Z=__imp__RtlAdjustPrivilege@16")
#pragma comment(linker,"/alternatename:__imp_?NtSetInformationObject@nt@win32@ufio@@YGHPIAXW4object_information_class@123@PAXI@Z=__imp__NtSetInformationObject@16")
#pragma comment(linker,"/alternatename:__imp_?ZwSetInformationObject@nt@win32@ufio@@YGHPIAXW4object_information_class@123@PAXI@Z=__imp__ZwSetInformationObject@16")
#pragma comment(linker,"/alternatename:__imp_?NtQueryAuxiliaryCounterFrequency@nt@win32@ufio@@YGHPA_K@Z=__imp__NtQueryAuxiliaryCounterFrequency@4")
#pragma comment(linker,"/alternatename:__imp_?ZwQueryAuxiliaryCounterFrequency@nt@win32@ufio@@YGHPA_K@Z=__imp__ZwQueryAuxiliaryCounterFrequency@4")
#pragma comment(linker,"/alternatename:__imp_?RtlDetermineDosPathNameType_U@nt@win32@ufio@@YG?AW4rtl_path_type@123@PB_S@Z=__imp__RtlDetermineDosPathNameType_U@4")
#pragma comment(linker,"/alternatename:__imp_?RtlGetFullPathName_U@nt@win32@ufio@@YGIPB_SIPA_SPAPA_S@Z=__imp__RtlGetFullPathName_U@16")
// msvc
#pragma comment(linker,"/alternatename:__imp_?msvc__RTtypeid@msvc@ufio@@YAPAXPAX@Z=__imp____RTtypeid")
#pragma comment(linker,"/alternatename:?msvc__RTtypeid@msvc@ufio@@YAPAXPAX@Z=___RTtypeid")
// clang-format on
