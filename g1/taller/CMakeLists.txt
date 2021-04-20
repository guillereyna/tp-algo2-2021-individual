cmake_minimum_required(VERSION 3.17)
project(taller)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=gnu++11 -ggdb3 -g")

file(GLOB SOURCE_FILES src/*.cpp src/*.h)
file(GLOB TEST_FILES tests/*.cpp)

SET(BUILD_GMOCK OFF)
SET(BUILD_GTEST ON)

add_library(gtest STATIC tests/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC tests/gtest-1.8.1/gtest_main.cc)

add_executable(testing ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(testing gtest gtest_main)

add_test(testing agenda)