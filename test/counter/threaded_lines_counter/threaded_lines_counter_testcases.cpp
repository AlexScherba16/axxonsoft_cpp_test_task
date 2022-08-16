#include "file_searcher/text_files_searcher/recursive_file_searcher.h"
#include "counter/threaded_lines_counter/threaded_lines_counter.h"
#include <gtest/gtest.h>

struct ThreadedLinesCounterTestSuite {
    std::string files_directory_path;
    uint64_t lines;
};

TEST(ThreadedCounterTest, CountEmpyFilesCollection) {
    using namespace counter::threaded_lines_counter;

    std::vector<std::string> files;
    ThreadedLinesCounter counter (std::move(files));
    ASSERT_EQ(counter.count(), 0);
}

TEST(ThreadedCounterTest, CountFilledFilesCollection) {
    using namespace counter::threaded_lines_counter;
    using namespace file_searcher::text_files_searcher;

    // arrange
    // "files_storage" should be located near unit tests binary file
    // for more information check README -> Setup & Launch -> 3, 4 step
    std::vector<ThreadedLinesCounterTestSuite> suits {
        {"files_storage/txt_files/1_file_1000_lines", 1000},
        {"files_storage/txt_files/10_files_0_lines", 0},
        {"files_storage/txt_files/10_files_10_000_000_lines", 10000000},
        {"files_storage/txt_files/10_files_550_000_lines", 550000},
        {"files_storage", 10551000},
    };
    RecursiveTextFileSearcher searcher;

    // act and assert
    for (const auto& suite : suits) {
        auto files = searcher.get_files(suite.files_directory_path);
        ThreadedLinesCounter counter (std::move(files));
        ASSERT_EQ(counter.count(), suite.lines);
    }
}
