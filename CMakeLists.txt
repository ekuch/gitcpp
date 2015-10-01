cmake_minimum_required(VERSION 3.3)
project(gitcpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(gitcpp ${SOURCE_FILES})