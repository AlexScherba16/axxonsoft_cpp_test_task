# ⚡️ AxxonSoft c++ test task ⚡

## Table of contents
* 📖 [General info](#General info)
* 💻 [System requirements](#System requirements)
* 🌁 [Structure](#Structure)
* ⚙️ [Setup & Launch](#Setup&Launch)

## 📖 General info
Test task for C++ Software Engineer

Implement a program that calcualtes the total number of lines in all files in a given directory.
Assume that files found in the given directory are text files.
Usage example:
```
linecounter <path-to-a-directory>
14124
```
Requirements:
* Must be written in C++
* Can use third party libraries if needed (i.e. Boost)
* Must utilise all available CPU cores

## 💻 System requirements
* Make
* Docker
* Git

## 🌁 Structure
``` text
.
├── CMakeLists.txt
├── app
│   └── main.cpp
│  
├── include
│   ├── exception
│   │   └── ...
│   ├── cmd_line_parser
│   │   └── ...
│   ├── file_searcher
│       └── ...
├── src
│   ├── cmd_line_parser
│   │   └── ...
│   └── file_searcher
│       └── ...
├── test
│   ├── exception
│   │   └── ...
│   ├── cmd_line_parser
│   │   └── ...
│   ├── CMakeLists.txt
│   └── main.cpp
│  
├── thirdparty
│   └── ...
```

* [app/](app) - Application launch point is located in the directory
* [include/](include/) - Header files directory
* * [include/exception](include/exception) - Exception header files directory
* * [include/cmd_line_parser](include/cmd_line_parser) - Command line parser header files directory
* * [include/file_searcher](include/file_searcher) - File searcher interface and its inheritants header files directory
* [src/](src/) - Source code files directory
* * [src/cmd_line_parser](src/cmd_line_parser) - Command line parser source files directory
* * [src/file_searcher](src/file_searcher) - File searcher interface and its inheritants source files
* [test/](test/) - Unit tests cases directory
* * [test/cmd_line_parser](test/cmd_line_parser) - Command line parser class test cases directory
* * [test/exception](test/exception) - Exception classes test cases directory
* * [test/file_searcher](test/file_searcher) - File searcher interface inheritants test cases directory
* [thirdparty/](thirdparty/) - Directory that contains the various dependencies of the current project.
In our case, here are the text files necessary to test the operation of the application components.

## ⚙️ Setup & Launch
``` bash
# 1) clone repo
git clone https://github.com/AlexScherba16/axxonsoft_cpp_test_task

# 2) go to repo directory
cd axxonsoft_cpp_test_task

# 3) actualize repo dependencies
make pre_build

# 4) build application
make build

# 5) run application
make run input=your_directory_path

# example
# make run input=/home/alexander/text_files

# 6) relax and enjoy 😊
```