cmake_minimum_required(VERSION 3.3)
project(gitcpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


FILE(GLOB source_cpp src/gitcpp/implementation/* src/gitcpp/implementation/**/*)
set(SOURCE_FILES ${source_cpp})
include_directories(thirdparty/libgit2/include)
include_directories(src/gitcpp)
add_library(gitcpp ${SOURCE_FILES})

add_subdirectory(thirdparty/libgit2)
target_link_libraries(gitcpp git2)