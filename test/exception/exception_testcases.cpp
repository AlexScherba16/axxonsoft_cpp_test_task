#include "exception/general_exception.h"
#include <gtest/gtest.h>

struct ExceptionTestSuite {
    std::string source;
    std::string text;
    std::string result;
};

TEST(GeneralExceptionTest, WhatMethodResultString) {
    // arrange
    std::vector<ExceptionTestSuite> suits {
        {"","","exception from [] message : "},
        {"TEST_CASE","check what() string","exception from [TEST_CASE] message : check what() string"},
        {"EMPTY_TEXT_CASE","","exception from [EMPTY_TEXT_CASE] message : "},
        {"","EMPTY_SOURCE_CASE","exception from [] message : EMPTY_SOURCE_CASE"},
    };

    // act and exception assert
    for (const auto& suite : suits) {
        try {
            throw exception::GeneralException(suite.source, suite.text);
        }
        catch(exception::GeneralException& ex){
            ASSERT_STREQ(ex.what(), suite.result.c_str());
        }
    }
}
