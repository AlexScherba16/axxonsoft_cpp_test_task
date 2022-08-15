#include "cmd_line_parser/cmd_line_parser.h"
#include "exception/general_exception.h"
#include <boost/program_options.hpp>
#include <iostream>

namespace cmd_line_parser {

const CmdLineArgs& CmdLineParser::parse(int argc, char *argv[]) {
    if (argc <= 0)
        throw exception::GeneralException(_tag, std::string{"argc <= 0"});

    if (argv == nullptr)
        throw exception::GeneralException(_tag, std::string{"argv == nullptr"});

    namespace po = boost::program_options;
    std::string inputDirectory;

    try {
        // create option descriptor and append options
        po::options_description desc("Allowed options");
        desc.add_options()
                // First parameter describes input directory name/short name
                ("help,h", "print usage message")
                ("input,i", po::value<std::string>(&inputDirectory)->required(), "input directory path");

        // create options map and set input values
        po::variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);

        if (vm.count("help")) {
            std::cout << desc;
            throw exception::GeneralException(_tag, std::string{"print --help parameter"});
        }

        // throw exception if now required params
        po::notify(vm);

    } catch(po::error& e) {
        throw exception::GeneralException(_tag, e.what());
    }

    // save input params
    _args.inputDirectory = std::move(inputDirectory);

    return _args;
}
}
