# ⚡️ AxxonSoft c++ test task ⚡

## 📖 Table of contents
* [General info](#General info)
* [Structure](#Structure)

## ℹ️ General info
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


## 🌁 Structure
``` text
.
├── CMakeLists.txt
├── app
│   └── main.cpp
├── include
│   └── exception
│       └── ...
│   └── cmd_line_parser
│       └── ...
├── src
│   └── cmd_line_parser
│       └── ...
├── test
│   └── exception
│       └── ...
│   └── cmd_line_parser
│       └── ...
│   └── CMakeLists.txt
│   └── main.cpp
```

* [app/](app) - Application launch point is located in the directory
* [include/](include/) - Header files directory
* * [include/exception](include/exception) - Exception header files directory
* * [include/cmd_line_parser](include/cmd_line_parser) - Command line parser header files directory
* [src/](src/) - Source code files directory
* * [src/cmd_line_parser](src/cmd_line_parser) - Command line parser source files directory
* [test/](test/) - Unit tests cases directory
* * [test/cmd_line_parser](test/cmd_line_parser) - Command line parser class test cases directory
* * [test/exception](test/exception) - Exception classes test cases directory
