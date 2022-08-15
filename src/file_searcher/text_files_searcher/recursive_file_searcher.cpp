#include "file_searcher/text_files_searcher/recursive_file_searcher.h"
#include "exception/general_exception.h"
#include <boost/filesystem.hpp>

namespace file_searcher {
namespace text_files_searcher {

RecursiveTextFileSearcher::RecursiveTextFileSearcher() : IFileSearcher() {
    _tag = std::move("RECURSIVE_TEXT_FILES_SEARCHER");
    _extension = std::move(".txt");
}

std::vector<std::string> RecursiveTextFileSearcher::getFiles(const std::string& root_path) {
    // validate income parameters
    if (root_path.empty())
        throw exception::GeneralException(_tag, std::string{"empty directory path"});

    if (!isDirectory(root_path))
        throw exception::GeneralException(_tag, std::string{"invalid directory path"});

    // files collection
    std::vector<std::string> files;
    try {
        // create a path object from given string
        boost::filesystem::path apk_path(root_path);

        // create directory iterator
        boost::filesystem::recursive_directory_iterator end;

        std::string filePath;
        for (boost::filesystem::recursive_directory_iterator i(apk_path); i != end; ++i) {
            filePath = boost::filesystem::path((*i)).string();

            // make file validation and check file extension
            if (isFile(filePath) && getFileExtension(filePath) == _extension) {
                files.emplace_back(std::move(filePath));
            }
        }
    }
    catch (std::exception &e) {
        throw exception::GeneralException(_tag, e.what());
    }

    return files;
}

}
}
