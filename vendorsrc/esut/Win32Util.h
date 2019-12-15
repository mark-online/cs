/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_WIN32UTIL_H_
#define _ESUT_WIN32UTIL_H_

#include <boost/noncopyable.hpp>
#include <string>

namespace esut
{

/**
 * @struct Shell
 *
 * Win32 관련 유틸리티
 */
struct Win32Util
{

    /// 하나의 인스턴스(프로세스)만 동작하도록 한다.
    /// @param uniqueName 유일한 식별자
    /// @return 이미 실행 중이면 false
    static bool ensureUniqueInstance(const char* uniqueName);

    /// Windows Message pumping
    static void peekAndPumpMessage() {
        MSG msg;
        if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }

    /// @param process ex, "explorer.exe"
    static bool terminateProcess(const char* process);

    static bool terminateProcess(int pid);

    /// Get PID of specified process, or 0 if no process is running.
    static int getProcessPid(const char* process);

};


/**
 * @struct OsVersion
 */
struct OsVersion
{
    /// Return true if the version of Windows is *not* 95, 98 or ME.
    static bool isWindowsNT();

    /// Return true if the version of Windows is 95
    static bool isWindows95();

    /// Return true if the version of Windows is NT 4
    static bool isWindowsNT4();

    /// Return true if the version of Windows is Win2000
    static bool isWindows2K();

    // Return true if the version of Windows is 2000 or high.
    static bool isWindows2KOrHigher();

    // Return true if the version of Windows is XP or high.
    static bool isWindowsXPOrHigher();

    // Return true if the version of Windows is Vista or high.
    static bool isWindowsVistaOrHigher();
};


/**
* @struct FileHandleGuard
*/
struct FileHandleGuard : boost::noncopyable
{
    FileHandleGuard(HANDLE handle) :
        handle_(handle) {}

    ~FileHandleGuard() {
        if (isValid()) {
            ::CloseHandle(handle_);
        }
    }

    bool isValid() const {
        return INVALID_HANDLE_VALUE != handle_;
    }

    const HANDLE handle_;
};

} // namespace esut

#endif // _ESUT_WIN32UTIL_H_
