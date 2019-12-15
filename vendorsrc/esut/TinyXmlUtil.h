/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_TINYXMLUTIL_H_
#define _ESUT_TINYXMLUTIL_H_

#include <string>

class TiXmlDocument;

namespace nspl
{
class PackageBrowser;
} // namespace nspl

namespace esut
{

/**
 * @struct TinyXmlUtil
 *
 * TinyXml utility
 */
struct TinyXmlUtil
{

    static bool parseXml(TiXmlDocument& xmlDoc,
        nspl::PackageBrowser* packageBrowser, const std::string& filename,
        bool useUtf8);

};

} // namespace esut

#endif    //_ESUT_TINYXMLUTIL_H_
