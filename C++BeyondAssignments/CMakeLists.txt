cmake_minimum_required(VERSION 3.6)
project(ParentChildPtr)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Parent.cpp Parent.h Child.cpp Child.h)
add_executable(ParentChildPtr ${SOURCE_FILES})