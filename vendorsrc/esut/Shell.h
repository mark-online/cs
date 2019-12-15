/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_SHELL_H_
#define _ESUT_SHELL_H_

#include <string>

namespace esut
{

/**
 * @struct Shell
 *
 * 윈도우 쉘 관련 유틸리티
 */
struct Shell
{

    /// Windows Vista 이상 버전인가?
    static bool isVistaAbove();

    /// 파일을 실행한다
    /// @param runas 비스타인경우 "runas"로 실행해야 하는가?
    static bool execute(const std::string& exeFilename,
        const std::string& parameters, bool runas, int nShow = SW_SHOWNORMAL);

    /**
     * 바탕화면에 파일 바로가기를 만든다
     * @param filename 바로가기를 만들 파일명
     * @param description 바로가기 이름
     * @param iconFilename 아이콘 파일명
     * - 출처: http://www.codeproject.com/shell/create_shortcut.asp
     */
    static bool createShortcutToDesktop(const std::string& filename, 
        const std::string& description, const std::string& iconFilename);

    /**
     * 바탕화면에 인터넷 바로가기를 만든다
     * 
     * - 출처: http://www.codeguru.com/cpp/i-n/internet/article.php/c3369/
     * - 참고: http://msdn2.microsoft.com/en-us/library/aa969273.aspx
     */
    static bool createInternetShortcutToDesktop(const std::string& url,
	    const std::string& description, const std::string& iconFilename);

    static std::string getDesktopDirectory();

};

} // namespace esut

#endif // _ESUT_SHELL_H_
