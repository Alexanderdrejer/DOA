cmake_minimum_required(VERSION 4.0)
project(Week_01)

set(CMAKE_CXX_STANDARD 14)

include_directories(basic_compilation/2-main_with_library)
include_directories(basic_compilation/3-main_with_class_v1)
include_directories(basic_compilation/3-main_with_class_v2)
include_directories(linear_search)
include_directories(templates)

add_executable(Week_01
        basic_compilation/1-single_file/main.cpp
        basic_compilation/2-main_with_library/hello.cpp
        basic_compilation/2-main_with_library/hello.h
        basic_compilation/2-main_with_library/main.cpp
        basic_compilation/3-main_with_class_v1/hello.h
        basic_compilation/3-main_with_class_v1/main.cpp
        basic_compilation/3-main_with_class_v2/hello.cpp
        basic_compilation/3-main_with_class_v2/hello.h
        basic_compilation/3-main_with_class_v2/main.cpp
        iterator/main.cpp
        linear_search/linear_search.h
        linear_search/test_linear_search.cpp
        pointers/pointers.cpp
        references/main.cpp
        templates/main.cpp
        templates/pair.h)
