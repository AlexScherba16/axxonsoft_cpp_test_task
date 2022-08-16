#include "counter/threaded_lines_counter/threaded_lines_counter.h"
#include <boost/asio.hpp>
#include <fstream>
#include <atomic>

namespace counter {
namespace threaded_lines_counter {

ThreadedLinesCounter::ThreadedLinesCounter(std::vector<std::string>&& files) :
    ICounter(), _files{std::move(files)} {}

uint64_t ThreadedLinesCounter::_count_reading_by_lines(const std::string& path) {
    uint64_t lines = 0;
    std::string line;
    std::ifstream fin(path);

    while (std::getline(fin, line)) {
        ++lines;
    }
    return lines;
}

uint64_t ThreadedLinesCounter::_count_reading_by_chars(const std::string& path) {
    std::ifstream file(path);
    uint64_t line_count = std::count(
            std::istream_iterator<char>(file),
            std::istream_iterator<char>(),
            '\n');
    return line_count;
}

uint64_t ThreadedLinesCounter::count() {
//    in case td::thread::hardware_concurrency() returns 0, take the minimum number of cores
    auto cores = std::thread::hardware_concurrency();
    cores = cores ? cores : _min_cores;

    boost::asio::thread_pool thread_pool(cores);
    std::atomic_uint64_t counted_lines {0};

    // tie each file processor to separate thread in thread pool
    for (const auto& path : _files) {
        boost::asio::post(thread_pool, [&counted_lines, &path, this](){
            counted_lines += _count_reading_by_lines(path);
        });
    }
    // wait until all threads are finished
    thread_pool.join();
    return counted_lines;
}

}
}
