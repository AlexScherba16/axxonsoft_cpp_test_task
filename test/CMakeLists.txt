SET(AXXONSOFT_TEST_PROJECT ${CMAKE_PROJECT_NAME}_test)

# tests build
add_executable(${AXXONSOFT_TEST_PROJECT}
        main.cpp
        cmd_line_parser/cmd_line_parser_testcases.cpp
        counter/threaded_lines_counter/threaded_lines_counter_testcases.cpp
        exception/exception_testcases.cpp
        file_searcher/text_files_searcher/recursive_file_searcher_testcases.cpp
        ${ALL_SRCS})

target_link_libraries(${AXXONSOFT_TEST_PROJECT}
        gtest
        gtest_main
        pthread
        boost_thread
        boost_program_options
        boost_system
        boost_filesystem)

add_test(NAME AllTests COMMAND ${AXXONSOFT_TEST_PROJECT})

# copy [deps/text_files_storage] content to unit tests binary directory
add_custom_command (
        TARGET ${AXXONSOFT_TEST_PROJECT}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/thirdparty ${CMAKE_CURRENT_BINARY_DIR}
)
