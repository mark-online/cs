/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_SCREENSHOT_H_
#define _ESUT_SCREENSHOT_H_

#include <boost/scoped_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <string>

namespace esut
{

/**
 * @class ScreenShot
 * 전체 화면을 캡쳐한다
 * BugTrap(http://www.codeproject.com/KB/applications/BugTrap.aspx)에서 훔침
 */
class ScreenShot : public boost::noncopyable
{
public:
    ScreenShot();
    ~ScreenShot();

    /**
     * Write screen-shot to file.
     * @param filename - screen-shot file name.
     * @return true if screen-shot has been written successfully.
     */
    bool capture(const std::string& filename);

private:
    void reset();
private:
    /// Bitmap information.
    PBITMAPINFO bmpInfo_;
    /// Bitmap bits.
    PBYTE bitsArray_;
    /// Bitmap header size.
    DWORD bmpHdrSize_;
    /// Image size.
    DWORD bitsArraySize_;
};

} // namespace esut

#endif // _ESUT_SCREENSHOT_H_
