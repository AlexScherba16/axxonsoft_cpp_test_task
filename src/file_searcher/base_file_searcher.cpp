#include "file_searcher/base_file_searcher.h"
#include "exception/general_exception.h"
#include <boost/filesystem.hpp>

namespace file_searcher{

bool IFileSearcher::isFile(const std::string& filePath) {
    try{
        // create a Path object from given path string
        boost::filesystem::path pathObj(filePath);

        // check if path exists and is of a regular file
        if (boost::filesystem::exists(pathObj) &&
            boost::filesystem::is_regular_file(pathObj) &&
            !boost::filesystem::is_symlink(pathObj))
            return true;
    }
    catch (boost::filesystem::filesystem_error & e) {
        throw exception::GeneralException(_tag, e.what());
    }

    return false;
}

bool IFileSearcher::isDirectory(const std::string& dirPath) {
    try {
        // create a Path object from given path string
        boost::filesystem::path pathObj(dirPath);

        // Check if path exists and is a directory
        if (boost::filesystem::exists(pathObj) && boost::filesystem::is_directory(pathObj))
            return true;
    }
    catch (boost::filesystem::filesystem_error & e) {
        throw exception::GeneralException(_tag, e.what());
    }

    return false;
}

std::string IFileSearcher::getFileExtension(const std::string& filePath){
    // create a Path object from given string
    boost::filesystem::path pathObj(filePath);

    // check if file name in the path object has extension
    if (pathObj.has_extension()) {
        // fetch the extension from path object and return
        return pathObj.extension().string();
    }

    // in case of no extension return empty string
    return "";
}

std::string IFileSearcher::getFileName(const std::string& filePath){
    // create a path object from given string
    boost::filesystem::path pathObj(filePath);

    // return file name with extension
    return pathObj.filename().string();
}

}