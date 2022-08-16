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

    bool is_file(const std::string& filePath);
    bool is_directory(const std::string& dirPath);
    std::string get_file_extension(const std::string& filePath);
    std::string get_file_name(const std::string& filePath);

public:
    virtual std::vector<std::string> get_files(const std::string& root_path) = 0;
    virtual ~IFileSearcher() = default;
};

} // namespace file_searcher

#endif //LINECOUNTER_INCLUDE_FILE_SEARCHER_BASE_FILE_SEARCHER_H
