/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#include "stdafx.h"
#include "esut/TinyXmlUtil.h"
#include "nspl/PackageBrowser.h"
#include "nspl/PackageFile.h"
#include "tinyxml/tinyxml.h"
#include <boost/scoped_array.hpp>

namespace
{

bool parseXmlFromPackage(TiXmlDocument& xmlDoc,
    nspl::PackageBrowser* packageBrowser, const std::string& filename,
    bool useUtf8)
{
    nspl::PackageFile* packageFile = packageBrowser->getPackageFile(filename);
    if (! packageFile) {
        return false;
    }

    DWORD bufferSize = packageFile->getOriginalSize();
    boost::scoped_array<char> buffer(new char[bufferSize + 1]);

    // 일반적으로 XML 파일은 크기가 작으므로 메모리 보다 성능을 우선시한다
    const bool shouldFreeStorage = false;
    if (! packageFile->decompressToMemory(buffer.get(), bufferSize,
        shouldFreeStorage)) {
        return false;
    }
    buffer[bufferSize] = '\0';

    (void)xmlDoc.Parse(buffer.get(), 0,
        useUtf8 ? TIXML_ENCODING_UTF8: TIXML_DEFAULT_ENCODING);

    return true;
}

} // namespace

namespace esut
{

bool TinyXmlUtil::parseXml(TiXmlDocument& xmlDoc,
    nspl::PackageBrowser* packageBrowser, const std::string& filename,
    bool useUtf8)
{
    if (packageBrowser != 0) {
        if (parseXmlFromPackage(xmlDoc, packageBrowser, filename, useUtf8)) {
            return true;
        }
    }

    return xmlDoc.LoadFile(filename.c_str());
}

} // namespace esut
