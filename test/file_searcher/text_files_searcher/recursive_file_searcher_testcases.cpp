#include "file_searcher/text_files_searcher/recursive_file_searcher.h"
#include "exception/general_exception.h"
#include <gtest/gtest.h>

struct RecursiveTextFileSearcherTestSuite {
    std::string path;
    std::string exceptionText;
    uint32_t files;
};

TEST(RecursiveTextFileSearcherTest, EmptyInvalidPathes) {
    // arrange
    std::vector<RecursiveTextFileSearcherTestSuite> suits {
        {"", "exception from [RECURSIVE_TEXT_FILES_SEARCHER] message : empty directory path", 0},
        {"test", "exception from [RECURSIVE_TEXT_FILES_SEARCHER] message : invalid directory path", 0},
    };
    file_searcher::text_files_searcher::RecursiveTextFileSearcher searcher;

    // act and exception assert
    for (const auto& suite : suits) {
        EXPECT_THROW(searcher.getFiles(suite.path), exception::GeneralException);

        try {
            searcher.getFiles(suite.path);
        }
        catch(exception::GeneralException& ex){
            ASSERT_STREQ(ex.what(), suite.exceptionText.c_str());
        }
    }
}

TEST(RecursiveTextFileSearcherTest, OkPathes) {
    // "text_files_storage" should be located near unit tests binary file
    // arrange
    std::vector<RecursiveTextFileSearcherTestSuite> suits {
        {"files_storage/txt_files/1_file_1000_lines", "", 1},
        {"files_storage/txt_files/10_files_0_lines", "", 10},
        {"files_storage/txt_files/10_files_10_000_000_lines", "", 10},
        {"files_storage/txt_files/10_files_550_000_lines", "", 10},
        {"files_storage", "", 31},
    };
    file_searcher::text_files_searcher::RecursiveTextFileSearcher searcher;

    // act and assert
    for (const auto& suite : suits) {
        auto files = searcher.getFiles(suite.path);
        ASSERT_EQ(files.size(), suite.files);
    }
}

