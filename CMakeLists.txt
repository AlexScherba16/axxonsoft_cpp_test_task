cmake_minimum_required(VERSION 3.16)
project(linecounter)

set(CMAKE_CXX_STANDARD 11)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS program_options thread filesystem REQUIRED)

# catch all warnings
add_compile_options(-Wall -Wextra -pedantic -Werror)

# add /include, /src directories path
include_directories(include src)

# collect all files
file(GLOB ALL_SRCS
        "${PROJECT_SOURCE_DIR}/include/application/*.h"
        "${PROJECT_SOURCE_DIR}/include/application/default_application/*.h"
        "${PROJECT_SOURCE_DIR}/include/cmd_line_parser/*.h"
        "${PROJECT_SOURCE_DIR}/include/counter/*.h"
        "${PROJECT_SOURCE_DIR}/include/counter/threaded_lines_counter/*.h"
        "${PROJECT_SOURCE_DIR}/include/exception/*.h"
        "${PROJECT_SOURCE_DIR}/include/file_searcher/*.h"
        "${PROJECT_SOURCE_DIR}/include/file_searcher/text_files_searcher/*.h"
        "${PROJECT_SOURCE_DIR}/src/application/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/application/default_application/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/cmd_line_parser/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/counter/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/counter/threaded_lines_counter/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/file_searcher/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/file_searcher/text_files_searcher/*.cpp")

enable_testing()

# build test cases
add_subdirectory(test)

# build application
add_executable(${CMAKE_PROJECT_NAME} app/main.cpp ${ALL_SRCS})

# static linking of libraries is used to solve problems with running
# in a lightweight docker container where there are no dynamic libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})
