cmake_minimum_required(VERSION 3.16)
project(linecounter)

set(CMAKE_CXX_STANDARD 11)

# catch all warnings
add_compile_options(-Wall -Wextra -pedantic -Werror)

# add /include directories path
include_directories(include)

# build test cases
add_subdirectory(test)

# build application
add_executable(${CMAKE_PROJECT_NAME} app/main.cpp)
