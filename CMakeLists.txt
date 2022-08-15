cmake_minimum_required(VERSION 3.16)
project(linecounter)

set(CMAKE_CXX_STANDARD 11)

set(INCLUDE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src)

# catch all warnings
add_compile_options(-Wall -Wextra -pedantic -Werror)

# add /include, /src directories path
include_directories(include src)

# build test cases
add_subdirectory(test)

# build application
add_executable(${CMAKE_PROJECT_NAME} app/main.cpp)
