/**
* Copyright (C) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#pragma once

#include <string>
#include <boost/scoped_ptr.hpp>
#include <boost/noncopyable.hpp>

namespace esut
{

/**
* @class IpcEventHandler
*
*/
class IpcEventHandler
{
public:
    virtual ~IpcEventHandler() {}

    /// 이벤트를 받았다.
    /// @return 메세지 호출자에게 넘겨줄 리턴 코드
    virtual long onReceive(ULONG_PTR id, void* data, size_t dataSize) = 0;
};


/**
 * @class WmCopyIpc
 *
 * WM_COPY & ATL Window를 이용한 IPC receiver window.
 */
class WmCopyIpc : public boost::noncopyable
{
public:
    WmCopyIpc(const std::string& identifier);
    ~WmCopyIpc();

    /// Ipc 이벤트 핸들러 설정
    void setEventHandler(IpcEventHandler* handler) {
        m_handler = handler;
    }

    void destroy();

    /// target 윈도우에 WM_COPYDATA 메세지를 전송한다.
    bool sendData(long target,
        int id, const void* data, size_t data_size);

    bool isValid();

    bool isValidHandle(long handle);

    long getHandle(const std::string& client_name);

    long getWindowHandle() const;

private:
    friend class Window;
    long onReceive(ULONG_PTR id, void* data, size_t dataSize);

private:
    IpcEventHandler* m_handler;
    std::string m_identifier;

    boost::scoped_ptr<Window> m_window;
};

} // namespace esut
