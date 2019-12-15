/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_FILESYSTEM_H_
#define _ESUT_FILESYSTEM_H_

#include "String.h"
#include <vector>
#include <cstdio>
#include <cassert>

namespace esut
{

/**
 * @struct FileSystem
 *
 * 파일 시스템 관련 유틸리티
 */
struct FileSystem
{

    typedef std::vector<std::string> Strings;


    /// 파일이 존재하는가?
    static bool isExists(const std::string& filename);

    /// 파일의 CRC를 구한다
    static DWORD calculateChecksum(const std::string& filename);

    /// 버퍼의 CRC를 구한다
    static DWORD calculateChecksum(const void* buffer, size_t size);

    /// 메모리를 파일에 저장한다
    static bool writeToFile(const std::string& filename,
        const void* buffer, size_t bufferSize);

    /// 문자열을 파일에 저장한다
    static bool writeToFile(const std::string& filename,
        const std::string& contents) {
        return FileSystem::writeToFile(filename,
            contents.c_str(), contents.size());
    }

    /// 디렉토리를 포함하고 있는가?
    static bool hasDirectory(const std::string& path,
        char dirDelimiter = '\\') {
        return path.find_first_of(dirDelimiter) != std::string::npos;
    }

    /// dir이 "." 또는 ".\\"인가?
    static bool isCurrentDirectory(const std::string& dir) {
        return (dir == ".") || (dir == ".\\");
    }

    /// 경로를 파싱하여 디렉토리와 파일명을 추출한다
    static void splitPath(std::string& directory, std::string& filename,
        const std::string& strPath, char dirDelimiter = '\\') {
        const size_t posDelimiter = strPath.find_last_of(dirDelimiter);
        if (posDelimiter != std::string::npos) {
            filename = strPath.substr(posDelimiter + 1);
            directory = strPath.substr(0, posDelimiter + 1);
        }
        else {
            directory = strPath;
        }
    }

    /// 경로에서 파일명을 얻어온다
    static std::string extractFilename(const std::string& path,
        char dirDelimiter = '\\') {
        const size_t posDelimiter = path.find_last_of(dirDelimiter);
        if (posDelimiter != std::string::npos) {
            return path.substr(posDelimiter + 1);
        }
        return path;
    }

    /// 경로에서 디렉토리를 얻어온다(끝에 dirDelimiter가 붙는다)
    static std::string extractDirectory(const std::string& path,
        char dirDelimiter = '\\') {
        const size_t posDelimiter = path.find_last_of(dirDelimiter);
        if (posDelimiter != std::string::npos) {
            return path.substr(0, posDelimiter + 1);
        }
        return path;
    }

    /// 파일명에서 확장자를 얻어온다
    static std::string extractExtension(const std::string& filename,
        char extDelimiter = '.') {
            const size_t posDelimiter = filename.find_last_of(extDelimiter);
            if (posDelimiter != std::string::npos) {
                return filename.substr(posDelimiter + 1);
            }
            return "";
    }

    /// 확장자를 없앤다
    static std::string& removeExtension(std::string& filename,
        char extDelimiter = '.') {
        const size_t posDelimiter = filename.find_last_of(extDelimiter);
        if (posDelimiter != std::string::npos) {
            filename.erase(posDelimiter);
        }
        return filename;
    }

    /// "." 또는 ".."인가?
    static bool isInvalidDirectory(const char* directory) {
        assert(directory != 0);
        return (strcmp(directory, ".") == 0) || (strcmp(directory, "..") == 0);
    }

    /// directory 끝에 구분자를 추가한다
    static std::string& appendDirectoryDelimiter(std::string& directory,
        char dirDelimiter = '\\') {
        if ((! directory.empty()) &&
            (directory[directory.size() - 1] != dirDelimiter)) {
            directory += dirDelimiter;
        }
        return directory;
    }

    static std::string appendDirectoryDelimiter_copy(
        const std::string& directory, char dirDelimiter = '\\') {
        std::string directoryCopied;
        directoryCopied.reserve(directory.length() + 1);
        directoryCopied = directory;
        return FileSystem::appendDirectoryDelimiter(directoryCopied,
            dirDelimiter);
    }

    /// directory 끝에서 구분자를 삭제한다
    static std::string& removeDirectoryDelimiter(std::string& directory,
        char dirDelimiter = '\\') {
        if ((! directory.empty()) &&
            (directory[directory.size() - 1] == dirDelimiter)) {
            directory.erase(directory.size() - 1);
        }
        return directory;
    }

    static std::string removeDirectoryDelimiter_copy(
        const std::string& directory, char dirDelimiter = '\\') {
        std::string directoryCopied;
        directoryCopied = directory;
        return FileSystem::removeDirectoryDelimiter(directoryCopied,
            dirDelimiter);
    }

    /// 디랙토리를 만든다
    static bool createDirectory(const std::string& directory);

    /// path의 모든 디렉토리를 만든다
    /// @param path "c:\b\d\"와 같은 형태가 되어야 한다. 끝에 '\'가 없으면
    ///        마지막 항목은 파일명으로 인식한다("c:\dir\file").
    static bool createDirectories(const std::string& path);

    /// directory 안에 있는 파일 목록을 얻는다(각각의 파일명은 full-path 형태)
    static Strings getFiles(const std::string& directory,
        const std::string& wildcard = "*.*");

    /// directory 안에 있는 모든 파일을 삭제하고 디렉토리도 삭제한다(rm -rf)
    static void removeRecursively(const std::string& directory);


    static std::string getTempFileName(const std::string& prefix);

};


/**
 * @class File
 * 파일 처리 유틸리티
 */
class File
{
public:
    File() :
        fp_(NULL) {}

    File(const std::string& filename, const char* mode) {
        (void)open(filename, mode);
    }

    ~File() {
        close();
    }

    bool open(const std::string& filename, const char* mode) {
        fp_ = fopen(filename.c_str(), mode);
        return fp_ != NULL;
    }

    void close() {
        if (fp_ != 0) {
            fclose(fp_);
            fp_ = NULL;
        }
    }

    size_t write(const void* buffer, size_t bufferSize) {
        assert(isValid());
        return std::fwrite(buffer, 1, bufferSize, fp_);
    }

    size_t read(void *buffer, size_t count) {
        assert(isValid());
        return std::fread(buffer, 1, count, fp_);
    }

    template <typename T>
    size_t write(T value) {
        return write(&value, sizeof(T));
    }

    /// 문자열 끝의 '\0'을 포함한다
    size_t write(const std::string& str) {
        return write(str.c_str(), str.size() + 1);
    }

    bool eof() {
        return 0 != feof(fp_);
    }

    bool error() {
        return 0 != ferror(fp_);
    }

    int seek(long offset, int origin) {
        assert(isValid());
        return std::fseek(fp_, offset, origin);
    }

    long tell() {
        assert(isValid());
        return std::ftell(fp_);
    }

    size_t getFileSize() {
        const long currentPosition = tell();
        seek(0, SEEK_END);
        const long length = tell();
        seek(currentPosition, SEEK_SET);
        return static_cast<size_t>(length);
    }

    bool isOpened() const {
        return fp_ != 0;
    }

    bool isValid() const {
        return fp_ != 0;
    }
private:
    FILE* fp_;
};

} // namespace esut

#endif // _ESUT_FILESYSTEM_H_
