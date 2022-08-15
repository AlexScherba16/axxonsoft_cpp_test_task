#ifndef LINECOUNTER_INCLUDE_FILE_SEARCHER_BASE_FILE_SEARCHER_H
#define LINECOUNTER_INCLUDE_FILE_SEARCHER_BASE_FILE_SEARCHER_H

#include <string>
#include <vector>

namespace file_searcher {

/// IFileSearcher - general files searcher interface
class IFileSearcher {
protected:
    std::string _tag{"BASE_FILE_SEARCHER"};
    std::string _extension{""};

    bool isFile(const std::string& filePath);
    bool isDirectory(const std::string& dirPath);
    std::string getFileExtension(const std::string& filePath);
    std::string getFileName(const std::string& filePath);

public:
    IFileSearcher() = default;
    virtual std::vector<std::string> getFiles(const std::string& root_path) = 0;
    virtual ~IFileSearcher() = default;
};

} // namespace file_searcher

#endif //LINECOUNTER_INCLUDE_FILE_SEARCHER_BASE_FILE_SEARCHER_H
