/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#include "stdafx.h"
#include "esut/Win32Util.h"
#include <tlhelp32.h>
//#include <shlwapi.h> 

namespace esut
{

namespace
{

// Initializer
OSVERSIONINFO s_OsVersionInfo;

/**
 * @class InitTortoiseUtils
 */
class InitTortoiseUtils
{
public:
    InitTortoiseUtils() {
        s_OsVersionInfo.dwOSVersionInfoSize = sizeof(s_OsVersionInfo);
        GetVersionEx(&s_OsVersionInfo);
    }
};

InitTortoiseUtils InitTortoiseUtils; 

} // namespace

// = Win32Util

// http://www.ddj.com/windows/184416849
bool Win32Util::ensureUniqueInstance(const char* uniqueName)
{
    // see if we can access the mutex.
    const HANDLE hMutex = ::OpenMutex(MUTEX_ALL_ACCESS, TRUE, uniqueName);
    if (hMutex != NULL) {
        ::ReleaseMutex(hMutex);
        return false;
    }

    // mutex will be released at program termination.
    (void)::CreateMutex(NULL, TRUE, uniqueName);
    return true;
}


bool Win32Util::terminateProcess(const char* process)
{
    const int pid = Win32Util::getProcessPid(process);
    if (pid == 0) {
        return false;
    }
    return Win32Util::terminateProcess(pid);
}


bool Win32Util::terminateProcess(int pid)
{
    const HANDLE hProc = ::OpenProcess(PROCESS_TERMINATE, FALSE, pid);
    if (! hProc) {
        return false;
    }

    const bool ret = ::TerminateProcess(hProc, 0) ? true : false;
    ::CloseHandle(hProc);
    return ret;
}


int Win32Util::getProcessPid(const char* process)
{
    // PSAPI function pointers.
    BOOL (WINAPI* lpfEnumProcesses)(DWORD*, DWORD, DWORD*);
    BOOL (WINAPI* lpfEnumProcessModules)(HANDLE, HMODULE*, DWORD, LPDWORD );
    DWORD (WINAPI* lpfGetModuleBaseName)(HANDLE, HMODULE, LPTSTR, DWORD);

    if (OsVersion::isWindowsNT()) { // Win/NT or 2000 or XP
        // Load library and get function pointers.
        const HINSTANCE hInstLib = ::LoadLibraryA("PSAPI.DLL");
        if (! hInstLib) {
            return 0;
        }

        // Get procedure addresses.
        lpfEnumProcesses = (BOOL (WINAPI*)(DWORD*,DWORD,DWORD*))
            ::GetProcAddress(hInstLib, "EnumProcesses");
        lpfEnumProcessModules = (BOOL (WINAPI*)(HANDLE, HMODULE*, DWORD, LPDWORD))
            ::GetProcAddress( hInstLib, "EnumProcessModules" );
        lpfGetModuleBaseName =(DWORD (WINAPI*)(HANDLE, HMODULE, LPTSTR, DWORD ))
            ::GetProcAddress( hInstLib, "GetModuleBaseNameA" );

        if (!lpfEnumProcesses || !lpfEnumProcessModules || !lpfGetModuleBaseName) {
            FreeLibrary(hInstLib);
            return 0;
        }

        DWORD aiPID[1000];
        DWORD iCbneeded;
        if (!lpfEnumProcesses(aiPID, sizeof(aiPID), &iCbneeded)) {
            // Unable to get process list, EnumProcesses failed
            FreeLibrary(hInstLib);
            return 0;
        }

        // How many processes are there?
        int iNumProc = iCbneeded/sizeof(DWORD);

        // Get and match the name of each process
        for (int i = 0; i < iNumProc; ++i) {
            // Get the (module) name for this process

            char name[MAX_PATH] = "";
            // First, get a handle to the process
            HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, aiPID[i]);
            if (hProc) {
                // Now, get the process name
                HMODULE hMod;
                if (hProc && lpfEnumProcessModules(hProc, &hMod, sizeof(hMod), &iCbneeded))
                    lpfGetModuleBaseName(hProc, hMod, name, MAX_PATH);
                CloseHandle(hProc);
                if (_stricmp(name, process) == 0)
                {
                    // Process found
                    return aiPID[i];
                }
            }
        }
        FreeLibrary(hInstLib);
    }
    else { // Win/95 or 98 or ME

        HINSTANCE hInstLib = LoadLibraryA("Kernel32.DLL");
        if (! hInstLib) {
            return 0;
        }

        // ToolHelp function pointers.
        HANDLE (WINAPI* lpfCreateToolhelp32Snapshot)(DWORD, DWORD);
        BOOL (WINAPI* lpfProcess32First)(HANDLE, LPPROCESSENTRY32);
        BOOL (WINAPI* lpfProcess32Next)(HANDLE, LPPROCESSENTRY32);
        BOOL (WINAPI* lpfModule32First)(HANDLE, LPMODULEENTRY32);
        BOOL (WINAPI* lpfModule32Next)(HANDLE, LPMODULEENTRY32);

        // Get procedure addresses.
        lpfCreateToolhelp32Snapshot = 
            (HANDLE (WINAPI*)(DWORD, DWORD)) GetProcAddress( hInstLib, "CreateToolhelp32Snapshot" );
        lpfProcess32First = 
            (BOOL (WINAPI*)(HANDLE, LPPROCESSENTRY32)) GetProcAddress( hInstLib, "Process32First" );
        lpfProcess32Next = 
            (BOOL (WINAPI*)(HANDLE, LPPROCESSENTRY32)) GetProcAddress( hInstLib, "Process32Next" );
        lpfModule32First = 
            (BOOL (WINAPI*)(HANDLE, LPMODULEENTRY32)) GetProcAddress( hInstLib, "Module32First" );
        lpfModule32Next = 
            (BOOL (WINAPI*)(HANDLE, LPMODULEENTRY32)) GetProcAddress( hInstLib, "Module32Next" );
        if (!lpfProcess32Next || !lpfProcess32First || !lpfModule32Next ||
            !lpfModule32First || !lpfCreateToolhelp32Snapshot) {
            FreeLibrary(hInstLib);
            return 0;
        }

        // Get a handle to a Toolhelp snapshot of all the systems processes.

        const HANDLE hSnapShot = lpfCreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hSnapShot == INVALID_HANDLE_VALUE) {
            FreeLibrary(hInstLib);
            return 0;
        }

        // Get the first process' information.
        PROCESSENTRY32 procentry;      
        procentry.dwSize = sizeof(PROCESSENTRY32);
        BOOL bResult = lpfProcess32First(hSnapShot, &procentry);

        // While there are processes, keep looping and checking.
        while (bResult) {
            // Get a handle to a Toolhelp snapshot of this process.
            HANDLE hSnapShotm = lpfCreateToolhelp32Snapshot(TH32CS_SNAPMODULE, procentry.th32ProcessID);
            if (hSnapShotm == INVALID_HANDLE_VALUE) {
                CloseHandle(hSnapShot);
                FreeLibrary(hInstLib);
                return 0;
            }
            // Get the module list for this process
            MODULEENTRY32 modentry;
            modentry.dwSize = sizeof(MODULEENTRY32);
            BOOL bResultm = lpfModule32First(hSnapShotm, &modentry);

            // While there are modules, keep looping and checking
            while (bResultm) {
                if (! _stricmp(modentry.szModule, process)) {
                    // Process found
                    return procentry.th32ProcessID;
                }
                else {  // Look for next modules for this process
                    modentry.dwSize = sizeof(MODULEENTRY32);
                    bResultm = lpfModule32Next(hSnapShotm,&modentry);
                }
            }

            // Keep looking
            CloseHandle(hSnapShotm);
            procentry.dwSize = sizeof(PROCESSENTRY32);
            bResult = lpfProcess32Next(hSnapShot,&procentry);
        }
        CloseHandle(hSnapShot);
        FreeLibrary(hInstLib);     
    }
    return 0;
}

// = OsVersion

bool OsVersion::isWindowsNT()
{
    return (s_OsVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT);
}


bool OsVersion::isWindows95()
{
    return (s_OsVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS && 
        s_OsVersionInfo.dwMajorVersion == 4 && 
        s_OsVersionInfo.dwMinorVersion == 0);
}


bool OsVersion::isWindowsNT4()
{
    return (s_OsVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT && 
        s_OsVersionInfo.dwMajorVersion == 4 && 
        s_OsVersionInfo.dwMinorVersion == 0);
}


bool OsVersion::isWindows2K()
{
    return (s_OsVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT && 
        s_OsVersionInfo.dwMajorVersion == 5 && 
        s_OsVersionInfo.dwMinorVersion == 0);
}


bool OsVersion::isWindows2KOrHigher()
{
    return (s_OsVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT && 
        s_OsVersionInfo.dwMajorVersion >= 5);
}


bool OsVersion::isWindowsXPOrHigher()
{
    return ((s_OsVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT) &&
        ((s_OsVersionInfo.dwMajorVersion == 5) &&
        (s_OsVersionInfo.dwMinorVersion >= 1)) ||
        (s_OsVersionInfo.dwMajorVersion >= 6));
}


bool OsVersion::isWindowsVistaOrHigher()
{
    return (s_OsVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT) &&
        (s_OsVersionInfo.dwMajorVersion >= 6);
}

} // namespace esut
