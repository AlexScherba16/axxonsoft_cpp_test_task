cmake_minimum_required(VERSION 3.16)
project(linecounter)

set(CMAKE_CXX_STANDARD 11)

# catch all warnings
add_compile_options(-Wall -Wextra -pedantic -Werror)

# build application
add_executable(${CMAKE_PROJECT_NAME} app/main.cpp)
