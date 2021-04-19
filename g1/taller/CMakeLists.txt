cmake_minimum_required(VERSION 3.17)
project(taller)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++11 -ggdb3 -g")

add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc src/clases.cpp src/clases.h src/agenda.cpp src/agenda.h)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc src/clases.cpp src/clases.h src/agenda.cpp src/agenda.h)

add_executable(taller main.cpp src/clases.cpp src/clases.h src/agenda.cpp src/agenda.h)

