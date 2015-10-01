cmake_minimum_required(VERSION 3.3)
project(gitcpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/gitcpp/Repository.cpp src/gitcpp/Repository.h src/gitcpp/util/ErrorUtility.cpp src/gitcpp/util/ErrorUtility.h src/gitcpp/Reference.cpp src/gitcpp/Reference.h src/gitcpp/RepositoryReferenceManager.cpp src/gitcpp/RepositoryReferenceManager.h src/gitcpp/util/HandleUtility.cpp src/gitcpp/util/HandleUtility.h src/gitcpp/GitObject.cpp src/gitcpp/GitObject.h src/gitcpp/GitObjectType.cpp src/gitcpp/GitObjectType.h src/gitcpp/GitObjectId.cpp src/gitcpp/GitObjectId.h src/gitcpp/GitObjectIdPrefix.cpp src/gitcpp/GitObjectIdPrefix.h)
include_directories(thirdparty/libgit2/include)
add_executable(gitcpp ${SOURCE_FILES})