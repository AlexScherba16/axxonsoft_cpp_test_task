#ifndef LINECOUNTER_INCLUDE_FILE_SEARCHER_TEXT_FILES_SEARCHER_RECURSIVE_FILE_SEARCHER_H
#define LINECOUNTER_INCLUDE_FILE_SEARCHER_TEXT_FILES_SEARCHER_RECURSIVE_FILE_SEARCHER_H

#include "file_searcher/base_file_searcher.h"

namespace file_searcher {
namespace text_files_searcher {

/// RecursiveTextFileSearcher - iterates directories recursively and builds a collection of .txt files paths
class RecursiveTextFileSearcher final : public IFileSearcher {

public:
    RecursiveTextFileSearcher();
    ~RecursiveTextFileSearcher() = default;

    std::vector<std::string> getFiles(const std::string& root_path) override;
};

} // namespace text_files_searcher
} // namespace file_searcher

#endif //LINECOUNTER_INCLUDE_FILE_SEARCHER_TEXT_FILES_SEARCHER_RECURSIVE_FILE_SEARCHER_H
