cmake_minimum_required(VERSION 3.7)
project(HW1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c change.cpp)
add_executable(HW1 ${SOURCE_FILES})