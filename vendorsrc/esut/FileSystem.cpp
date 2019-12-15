/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#include "stdafx.h"
#include "esut/FileSystem.h"
#include <boost/scoped_array.hpp>
#pragma warning (push)
#pragma warning (disable: 4244 4245)
#include <boost/crc.hpp>
#pragma warning (pop)
#include <boost/next_prior.hpp>
#include <io.h>

namespace esut
{

bool FileSystem::isExists(const std::string& filename)
{
    return _access(filename.c_str(), 0) == 0;
}


DWORD FileSystem::calculateChecksum(const std::string& filename)
{
    const size_t buffer_size = 1024;

    File file(filename, "rb");
    if (! file.isOpened()) {
        return 0;
    }

    boost::crc_32_type result;
    while (! file.eof()) {
        char buffer[buffer_size];
        const size_t readSize = file.read(buffer, buffer_size);
        if (file.error()) {
            break;
        }
        result.process_bytes(buffer, readSize);
    }

    return result.checksum();
}


DWORD FileSystem::calculateChecksum(const void* buffer, size_t size)
{
    boost::crc_32_type result;
    result.process_bytes(buffer, size);
    return result.checksum();
}


bool FileSystem::writeToFile(const std::string& filename,
    const void* buffer, size_t bufferSize)
{
    File file(filename, "wb");
    if (! file.isOpened()) {
        return false;
    }

    file.write(buffer, bufferSize);
    return true;
}


bool FileSystem::createDirectory(const std::string& directory)
{
    if (0 == ::CreateDirectory(directory.c_str(), NULL)) {
        const DWORD lastError = ::GetLastError();
        if (lastError != ERROR_ALREADY_EXISTS) {
            return false;
        }
    }
    return true;
}


bool FileSystem::createDirectories(const std::string& path)
{
    if (FileSystem::createDirectory(FileSystem::extractDirectory(path))) {
        return true;
    }

    std::string part;
    std::string directory;

    part.reserve(MAX_PATH);
    directory.reserve(MAX_PATH);

    std::string::const_iterator pos = path.begin();
    const std::string::const_iterator end = path.end();
    for (; pos != end; ++pos) {
        const char ch = *pos;
        part += ch;
        if (ch == ':' && *boost::next(pos) == '\\') {
            part += "\\";
            ++pos;
        }
        else if (ch == '\\') {
            directory += part;
            if (! createDirectory(directory)) {
                return false; // failed!!
            }
            part.clear();
        }
    }
    return true;
}


FileSystem::Strings FileSystem::getFiles(const std::string& directory,
    const std::string& wildcard)
{
    Strings files;

    WIN32_FIND_DATA findData;
    HANDLE h = FindFirstFile((directory + wildcard).c_str(), &findData);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                continue;
            }

            files.push_back(directory + findData.cFileName);
        }
        while (FindNextFile(h, &findData) != FALSE);
        FindClose(h);
    }

    return files;
}


void FileSystem::removeRecursively(const std::string& directory)
{
    if (directory.empty()) {
        return;
    }

    const Strings files = getFiles(directory);

    Strings::const_iterator pos = files.begin();
    const Strings::const_iterator end = files.end();
    for (; pos != end; ++pos) {
        const std::string& filename = *pos;
        ::DeleteFile(filename.c_str());
    }

    ::RemoveDirectory(directory.c_str());
}


std::string FileSystem::getTempFileName(const std::string& prefix)
{
    char tempPath[MAX_PATH];
    char tempFile[MAX_PATH];
    GetTempPath(MAX_PATH, tempPath);
    GetTempFileName(tempPath, prefix.c_str(), GetTickCount(), tempFile);
    return tempFile;
}

} // namespace esut
