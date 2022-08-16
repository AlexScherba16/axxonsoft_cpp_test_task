#include "file_searcher/text_files_searcher/recursive_file_searcher.h"
#include "counter/threaded_lines_counter/threaded_lines_counter.h"
#include "application/default_application/default_application.h"
#include "cmd_line_parser/cmd_line_parser.h"
#include "exception/general_exception.h"
#include <iostream>
#include <memory>

namespace application {
namespace default_application {

DefaultApplication::DefaultApplication() : IRunnable() {
    _tag = std::move("DEFAULT_APPLICATION");
}

int DefaultApplication::run(int argc, char **argv) {
    using namespace cmd_line_parser;
    using namespace file_searcher::text_files_searcher;
    using namespace counter::threaded_lines_counter;

    try {
        CmdLineParser parser;
        auto arguments = parser.parse(argc, argv);

        std::unique_ptr<file_searcher::IFileSearcher> searcher(new RecursiveTextFileSearcher());
        auto files = searcher->get_files(arguments.inputDirectory);

        std::unique_ptr<counter::ICounter> counter(new ThreadedLinesCounter(std::move(files)));
        std::cout << "counted lines : " << counter->count() << std::endl;

    } catch(std::exception& e) {
        throw exception::GeneralException(_tag, e.what());
    }
    return EXIT_SUCCESS;
}

}
}
