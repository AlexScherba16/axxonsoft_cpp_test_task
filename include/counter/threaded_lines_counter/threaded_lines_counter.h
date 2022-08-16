#ifndef LINECOUNTER_INCLUDE_THREADED_LINES_COUNTER_THREADED_LINES_COUNTER_H
#define LINECOUNTER_INCLUDE_THREADED_LINES_COUNTER_THREADED_LINES_COUNTER_H

#include <vector>
#include <string>
#include "counter/base_counter.h"

namespace counter {
namespace threaded_lines_counter {

/// ThreadedLinesCounter - counts the number of lines in a list of text files in multithreaded mode.
/// It does not catch exceptions !!!

class ThreadedLinesCounter final : public ICounter {
private:
    std::vector<std::string> _files;
    const uint32_t _min_cores {4};

    /// count lines when reading text file line by line
    uint64_t _count_reading_by_lines(const std::string& path);

    /// count lines when reading text file character by character
    uint64_t _count_reading_by_chars(const std::string& path);

public:
    ThreadedLinesCounter() = default;
    ThreadedLinesCounter(std::vector<std::string>&& files);
    ~ThreadedLinesCounter() = default;

    uint64_t count() override;
};

} // namespace threaded_lines_counter
} // namespace counter

#endif //LINECOUNTER_INCLUDE_THREADED_LINES_COUNTER_THREADED_LINES_COUNTER_H
