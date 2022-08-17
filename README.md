# ⚡️ AxxonSoft c++ test task ⚡

## Table of contents
* 📖 [General info](#General info)
* 💻 [System requirements](#System requirements)
* 🌁 [Structure](#Structure)
* ⚙️ [Setup & Launch](#Setup&Launch)
* 📱 [Contacts](#Contacts)

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
│   ├── application
│   │   └── ...
│   ├── cmd_line_parser
│   │   └── ...
│   ├── counter
│   │   └── ...
│   ├── exception
│   │   └── ...
│   └── file_searcher
│       └── ...
├── src
│   ├── application
│   │   └── ...
│   ├── cmd_line_parser
│   │   └── ...
│   ├── counter
│   │   └── ...
│   └── file_searcher
│       └── ...
├── test
│   ├── cmd_line_parser
│   │   └── ...
│   ├── counter
│   │   └── ...
│   ├── exception
│   │   └── ...
│   ├── file_searcher
│   │   └── ...
│   ├── CMakeLists.txt
│   └── main.cpp
│  
├── thirdparty
│   └── ...
```

* [app/](app) - Application launch point is located in the directory
* [include/](include/) - Header files directory
* * [include/application](include/application) - Runner interface and its inheritants header files directory
* * [include/cmd_line_parser](include/cmd_line_parser) - Command line parser header files directory
* * [include/counter](include/counter) - Counter interface and its inheritants header files directory
* * [include/exception](include/exception) - Exception header files directory
* * [include/file_searcher](include/file_searcher) - File searcher interface and its inheritants header files directory
* [src/](src/) - Source code files directory
* * [src/application](src/application) - Runner interface and its inheritants source files
* * [src/cmd_line_parser](src/cmd_line_parser) - Command line parser source files directory
* * [src/counter](src/counter) - Counter interface and its inheritants source files
* * [src/file_searcher](src/file_searcher) - File searcher interface and its inheritants source files
* [test/](test/) - Unit tests cases directory
* * [test/cmd_line_parser](test/cmd_line_parser) - Command line parser class test cases directory
* * [test/counter](test/counter) - Counter interface inheritants test cases directory
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

# 3) build application
make build_app

# 4) run application
make run_app input=your_directory_path

# example
# make run_app input=/home/thirdparty/files_storage/txt_files/1_file_1000_lines

# 5) relax and enjoy 🤙
```

## 📱 Contacts
``` 
email:      alexscherba16@gmail.com
telegram:   @Alex_Scherba
```