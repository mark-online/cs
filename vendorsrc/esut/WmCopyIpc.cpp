/**
* Copyright (C) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#include "stdafx.h"
#include "WmCopyIpc.h"
#include "Shell.h"
#include <cassert>

#pragma warning (disable : 4311 4312 4355) 

namespace
{

typedef BOOL (WINAPI *ChangeWindowMessageFilter)(UINT message, DWORD dwFlag);

// http://msdn.microsoft.com/en-us/library/ms632675.aspx
void allowWmCopyDataInVista()
{
    const DWORD _MSGFLT_ADD = 1;

    if (! esut::Shell::isVistaAbove()) {
        return;
    }

    ChangeWindowMessageFilter changeWindowMessageFilter;
    const HINSTANCE hDll = LoadLibrary("USER32.DLL");
    if (NULL == hDll) {
        return;
    }

    changeWindowMessageFilter =
        (ChangeWindowMessageFilter)GetProcAddress(hDll,
            "ChangeWindowMessageFilter");
    if (NULL == changeWindowMessageFilter) {
        return;
    }

    const BOOL result = changeWindowMessageFilter(WM_COPYDATA, _MSGFLT_ADD);
    assert(result == TRUE); result;

    FreeLibrary(hDll);
}

} // namespace

namespace esut
{

/**
* @class Window
*
* WIN32 window.
*/
class Window
{
private:
    WmCopyIpc& m_ipc;
    HWND m_hWindow;

public:
    Window(WmCopyIpc& ipc) :
        m_ipc(ipc),
        m_hWindow(NULL) {}

    void create(const std::string& identifier) {
        allowWmCopyDataInVista();

        if (! isRegisteredClass(identifier)) {
            if (! registerClass(identifier))
                return;
        }

        m_hWindow = createWindow(identifier);
        if (m_hWindow != NULL) {
            ::ShowWindow(m_hWindow, SW_HIDE);
            ::SetWindowLong(m_hWindow, GWL_USERDATA,
                reinterpret_cast<long>(this));
        }
    }

    void destroy() {
        if (m_hWindow != NULL) {
            ::DestroyWindow(m_hWindow);
            m_hWindow = NULL;
        }
    }

    HWND getWindowHandle() const {
        return m_hWindow;
    }

    LRESULT onCopyData(COPYDATASTRUCT* cds) {
        return m_ipc.onReceive(cds->dwData, cds->lpData, cds->cbData);
    }

    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
        WPARAM wParam, LPARAM lParam) {
        Window* window =
            reinterpret_cast<Window*>(::GetWindowLong(hWnd, GWL_USERDATA));
        if ((window != 0) && (message == WM_COPYDATA)) {
            return window->onCopyData(reinterpret_cast<COPYDATASTRUCT*>(lParam));
        }
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

private:
    bool isRegisteredClass(const std::string& identifier) const {
        WNDCLASS wc;
        return ::GetClassInfo(getInstanceHandle(), identifier.c_str(), &wc)
            ? true : false;
    }

    bool registerClass(const std::string& identifier) {
        WNDCLASS wc;
        ZeroMemory(&wc, sizeof(wc));
        wc.style = 0;
        wc.lpfnWndProc = (WNDPROC)WndProc;
        wc.hInstance = getInstanceHandle();
        wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW+1);
        wc.lpszClassName = identifier.c_str();
        return ::RegisterClass(&wc) ? true : false;
    }

    HWND createWindow(const std::string& identifier) {
        return ::CreateWindow(identifier.c_str(), "esut_ipc",
            WS_POPUP, 0, 0, 0, 0, NULL, NULL, getInstanceHandle(), NULL);
    }

    HINSTANCE getInstanceHandle() const {
        return reinterpret_cast<HINSTANCE>(::GetModuleHandle(NULL));
    }
};

// = WmCopyIpc

WmCopyIpc::WmCopyIpc(const std::string& identifier) :
    m_identifier(identifier),
    m_window(new Window(*this))
{
    m_window->create(identifier);
}


WmCopyIpc::~WmCopyIpc()
{
    destroy();
}


void WmCopyIpc::destroy()
{
    m_window->destroy();
}


bool WmCopyIpc::isValid()
{
    return getWindowHandle() != NULL;
}


bool WmCopyIpc::sendData(long target,
    int id, const void* data, size_t data_size)
{
    COPYDATASTRUCT cds;
    cds.dwData = id;
    cds.cbData = static_cast<DWORD>(data_size);
    cds.lpData = const_cast<void*>(data);

    const UINT timeout = 3 * 1000;
    DWORD result;
    return ::SendMessageTimeout(reinterpret_cast<HWND>(target),
        WM_COPYDATA,
        static_cast<WPARAM>(getWindowHandle()),
        reinterpret_cast<LPARAM>(&cds),
        SMTO_NORMAL,
        timeout,
        &result) > 0;
}


bool WmCopyIpc::isValidHandle(long handle)
{
    return ::IsWindow(reinterpret_cast<HWND>(handle)) ? true : false;
}


long WmCopyIpc::onReceive(ULONG_PTR id, void* data, size_t dataSize)
{
    if (m_handler != 0) {
        return m_handler->onReceive(id, data, dataSize);
    }
    return 0;
}


long WmCopyIpc::getWindowHandle() const
{
    return reinterpret_cast<long>(m_window->getWindowHandle());
}


long WmCopyIpc::getHandle(const std::string& client_name)
{
    return reinterpret_cast<long>(
        ::FindWindow(m_identifier.c_str(), client_name.c_str()));
}

}  // namespace esut
