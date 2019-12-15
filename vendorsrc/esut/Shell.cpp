/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#include "stdafx.h"
#undef NTDDI_VERSION
#define NTDDI_VERSION NTDDI_WIN2K
#include "esut/Shell.h"
#pragma warning (push)
#pragma warning (disable: 4127)
#include <atlcomcli.h>
#pragma warning (pop)
#include <shellapi.h>
#include <shobjidl.h>
#include <shlguid.h>
#include <shlobj.h>
#include <intshcut.h>

namespace
{

/**
 * @struct SHGetFolderPathLoader
 */
struct SHGetFolderPathLoader
{
    typedef HRESULT (__stdcall * PFNSHGETFOLDERPATHA)(
        HWND, int, HANDLE, DWORD, LPSTR);

    PFNSHGETFOLDERPATHA shGetFolderPath_;

    SHGetFolderPathLoader() {
        const char* dll = "shfolder";
        const char* api = "SHGetFolderPathA";
        HMODULE hModule = ::GetModuleHandle(dll);
        if (! hModule) {
            hModule = LoadLibrary(dll);
        }
        if (hModule) {
            shGetFolderPath_ = reinterpret_cast<PFNSHGETFOLDERPATHA>(
                ::GetProcAddress(hModule, api));
        }
        else {
            shGetFolderPath_ = 0;
        }

        // from NSIS(http://nsis.sf.net)
        // part of what SHGetFileInfo does, is to convert a path into an idl.
        // to do this conversion, it first needs to initialize the list of 
        // special idls, which are exactly the idls we use to get the paths
        // of special folders (CSIDL_*).
        SHFILEINFO shfi;
        ::SHGetFileInfo("", 0, &shfi, sizeof(SHFILEINFO), 0); 
    }

    bool isSupported() const {
        return shGetFolderPath_ != 0;
    }
};


// from NSIS
// SHGetFolderPath as provided by shfolder.dll is used to get special folders
// unless the installer is running on Windows 95/98. For 95/98 shfolder.dll is
// only used for the Application Data and Documents folder (if the DLL exists).
// Oherwise, the old SHGetSpecialFolderLocation API is called. 
std::string getDesktopDirectory()
{
#ifndef SHGFP_TYPE_CURRENT
#  define SHGFP_TYPE_CURRENT 0
#endif

    static SHGetFolderPathLoader shGetFolderPathLoader;

    char path[MAX_PATH];
    if (shGetFolderPathLoader.isSupported()) {
        const HRESULT result = shGetFolderPathLoader.shGetFolderPath_(NULL,
            CSIDL_DESKTOPDIRECTORY, NULL, SHGFP_TYPE_CURRENT, path);
        if (SUCCEEDED(result)) {
            return path;
        }
    }

    LPITEMIDLIST idl; 
    if (NOERROR ==
        ::SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOPDIRECTORY, &idl)) {
        const BOOL res = ::SHGetPathFromIDList(idl, path);
        ::CoTaskMemFree(idl);
        if (res) {
            return path;
        }
    }

    return "";
}


std::wstring toUnicode(const std::string& ansi)
{
    std::wstring unicode;
    unicode.resize(ansi.size());
    MultiByteToWideChar(CP_ACP, 0, &ansi[0], -1, &unicode[0], MAX_PATH);
    unicode.resize(ansi.size() - 1);
    return unicode;
}


bool createShortcut(IShellLink& shellLink, IPersistFile& persistFile,
    const std::string& description, const std::string& iconFilename,
    const std::string& fileExtension)
{
    const HRESULT resultSetDesc =
        shellLink.SetDescription(description.c_str());
    if (FAILED(resultSetDesc)) {
        return false;
    }

    const HRESULT resultSetIcon =
        shellLink.SetIconLocation(iconFilename.c_str(), 0);
    if (FAILED(resultSetIcon)) {
        return false;
    }

    std::string filename = getDesktopDirectory();
    if (filename.empty()) {
        return false;
    }

    filename += "\\" + description + "." + fileExtension;

    ::DeleteFile(filename.c_str());

    return SUCCEEDED(persistFile.Save(toUnicode(filename).c_str(), TRUE));
}

} // namespace

namespace esut
{

bool Shell::isVistaAbove()
{
    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(osvi));
    osvi.dwOSVersionInfoSize = sizeof(osvi);
    ::GetVersionEx(&osvi);
    return 6 <= osvi.dwMajorVersion;
}


// Elevate through ShellExecute (from VISTA)
//  - http://blogs.msdn.com/vistacompatteam/archive/2006/09/25/771232.aspx
bool Shell::execute(const std::string& exeFilename,
    const std::string& parameters, bool runas, int nShow)
{
    SHELLEXECUTEINFO sei;
    ZeroMemory(&sei, sizeof(sei));
    sei.cbSize = sizeof(sei);
    sei.hwnd = ::GetForegroundWindow();
    sei.fMask = SEE_MASK_FLAG_NO_UI;
    sei.lpFile = exeFilename.c_str();
    sei.lpParameters = parameters.c_str();
    sei.nShow = nShow;

    if (runas) {
        // check for VISTA OS, and if so, elevate our privilegies to run game
        if (isVistaAbove()) {
            // "runas" verb is used in Vista to run process under UAC
            sei.lpVerb = "runas";
        }
    }

    return ::ShellExecuteEx(&sei) == TRUE;
}


bool Shell::createShortcutToDesktop(const std::string& filename, 
    const std::string& description, const std::string& iconFilename)
{
    TCHAR fullPath[MAX_PATH];
    LPTSTR filePart;
    if (0 == GetFullPathName(filename.c_str(),
        sizeof(fullPath) / sizeof(TCHAR), fullPath, &filePart)) {
        return false;
    }

    CComPtr<IShellLink> shellLink;
    const HRESULT resultShellLink = CoCreateInstance(CLSID_ShellLink, NULL, 
        CLSCTX_INPROC_SERVER, IID_IShellLink, (void**)&shellLink);
    if (FAILED(resultShellLink)) {
        return false;
    }

    CComQIPtr<IPersistFile> persistFile(shellLink);
    const HRESULT resultSetPath = shellLink->SetPath(fullPath);
    if (FAILED(resultSetPath)) {
        return false;
    }

    return createShortcut(*shellLink, *persistFile, description, iconFilename,
        "lnk");
}


bool Shell::createInternetShortcutToDesktop(const std::string& url,
	const std::string& description, const std::string& iconFilename)
{
    CComPtr<IUniformResourceLocator> internetShortcut;
    const HRESULT resultIs =
        ::CoCreateInstance(CLSID_InternetShortcut, NULL, CLSCTX_INPROC_SERVER,
            IID_IUniformResourceLocator, (void **)&internetShortcut);
    if (FAILED(resultIs)) {
        return false;
    }

    CComQIPtr<IPersistFile> persistFile;
    const HRESULT resultPf = internetShortcut->QueryInterface(IID_IPersistFile,
        (void **)&persistFile);
    if (FAILED(resultPf)) {
        return false;
    }

    CComQIPtr<IShellLink> shellLink;
    const HRESULT resultSl = internetShortcut->QueryInterface(IID_IShellLink,
        (void **)&shellLink);
    if (FAILED(resultSl)) {
        return false;
    }

    const HRESULT resultSetUrl = internetShortcut->SetURL(url.c_str(), 0);
    if (FAILED(resultSetUrl)) {
        return false;
    }

    return createShortcut(*shellLink, *persistFile, description, iconFilename,
        "url");
}


std::string Shell::getDesktopDirectory()
{
    return ::getDesktopDirectory();
}


} // namespace esut
