/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_MFCUTIL_H_
#define _ESUT_MFCUTIL_H_

namespace esut
{

/**
 * @struct MfcUtil
 *
 * MFC 관련 유틸리티
 */
struct MfcUtil
{

    static void peekAndPumpMessage() {
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
            if (! AfxGetApp()->PumpMessage()) {
                break;
            }
        }
    }

};

} // namespace esut

#endif // _ESUT_MFCUTIL_H_
