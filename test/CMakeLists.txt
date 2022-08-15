message("process /test")

SET(AXXONSOFT_TEST_PROJECT ${CMAKE_PROJECT_NAME}_test)

# tests build
add_executable(${AXXONSOFT_TEST_PROJECT}
        main.cpp
        exception/exception_testcases.cpp)

target_link_libraries(${AXXONSOFT_TEST_PROJECT}
        gtest
        gtest_main
        pthread)
