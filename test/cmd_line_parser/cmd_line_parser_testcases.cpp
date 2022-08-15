#include "cmd_line_parser/cmd_line_parser.h"
#include "exception/general_exception.h"
#include <gtest/gtest.h>

/// invalid argc param tests
TEST(CmdLineParserTest, InvalidArgc) {
    // arrange
    int argc = 0;
    char *argv[] = {const_cast<char*>("program_name")};
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : argc <= 0";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

/// invalid argv param tests
TEST(CmdLineParserTest, InvalidArgv) {
    // arrange
    int argc = 1;
    char **argv = nullptr;
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : argv == nullptr";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

/// no params tests
TEST(CmdLineParserTest, NoParams) {
    // arrange
    int argc = 1;
    char *argv[] = {const_cast<char*>("program_name")};
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : the option '--input' is required but missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

/// HELP parameter tests
TEST(CmdLineParserTest, LongHelpParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("--help")
    };
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : print --help parameter";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(CmdLineParserTest, ShortHelpParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("-h")
    };
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : print --help parameter";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(CmdLineParserTest, ErrorHelpParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("-has")
    };
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : unrecognised option '-has'";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}


/// INPUT parameter tests
TEST(CmdLineParserTest, LongEmptyInputParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("--input")
    };
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : the required argument for option '--input' is missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(CmdLineParserTest, ShortEmptyInputParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("--i")
    };
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : the required argument for option '--input' is missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(CmdLineParserTest, LongInputParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("--input=test")
    };
    cmd_line_parser::CmdLineParser parser;

    //act
    auto args = parser.parse(argc, argv);

    // assert message string
    ASSERT_STREQ(args.inputDirectory.c_str(), "test");
}

TEST(CmdLineParserTest, ShortInputParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("--i=test")
    };
    cmd_line_parser::CmdLineParser parser;

    //act
    auto args = parser.parse(argc, argv);

    // assert message string
    ASSERT_STREQ(args.inputDirectory.c_str(), "test");
}

TEST(CmdLineParserTest, LongErrorInputParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("--inputt=test")
    };
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : unrecognised option '--inputt=test'";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(CmdLineParserTest, ShortErrorInputParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("--a=test")
    };
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : unrecognised option '--a=test'";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}


/// Duplicate params
TEST(CmdLineParserTest, DoubleLongSrcParam) {
    // arrange
    int argc = 3;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("--input=test"),
            const_cast<char*>("--input=double_test")
    };
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : option '--input' cannot be specified more than once";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(CmdLineParserTest, DoubleShortSrcParam) {
    // arrange
    int argc = 3;
    char *argv[] = {
            const_cast<char*>("program_name"),
            const_cast<char*>("--i=test"),
            const_cast<char*>("--i=double_test"),
    };
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : option '--input' cannot be specified more than once";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(CmdLineParserTest, LongShortSrcParam) {
    // arrange
    int argc = 3;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--input=test"),
            const_cast<char*>("--i=double_test"),
    };
    cmd_line_parser::CmdLineParser parser;

    // act and exception assert
    EXPECT_THROW(parser.parse(argc, argv), exception::GeneralException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(exception::GeneralException& ex) {
        std::string message = "exception from [PARSER] message : option '--input' cannot be specified more than once";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}