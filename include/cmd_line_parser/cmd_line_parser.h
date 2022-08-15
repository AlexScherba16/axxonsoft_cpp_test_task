#ifndef LINECOUNTER_INCLUDE_CMD_LINE_PARSER_CMD_LINE_PARSER_H
#define LINECOUNTER_INCLUDE_CMD_LINE_PARSER_CMD_LINE_PARSER_H

#include <string>

namespace cmd_line_parser {

/// CmdLineArgs - contains cmd line parsing result
struct CmdLineArgs {
    std::string inputDirectory;
    // add here additional parameters;
};

/// CmdLineParser - cmd line parser class
/// parses argv parameters and then populates the command line options structure
class CmdLineParser {
private:
    const std::string _tag{"PARSER"};
    CmdLineArgs _args;

public:
    const CmdLineArgs& parse(int argc, char *argv[]);
};

} // namespace cmd_line_parser

#endif //LINECOUNTER_INCLUDE_CMD_LINE_PARSER_CMD_LINE_PARSER_H
