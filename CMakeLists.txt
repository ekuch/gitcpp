cmake_minimum_required(VERSION 3.3)
project(gitcpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/gitcpp/Repository.cpp src/gitcpp/Repository.h src/gitcpp/util/ErrorUtility.cpp src/gitcpp/util/ErrorUtility.h src/gitcpp/Reference.cpp src/gitcpp/Reference.h src/gitcpp/RepositoryReferenceManager.cpp src/gitcpp/RepositoryReferenceManager.h src/gitcpp/util/HandleUtility.cpp src/gitcpp/util/HandleUtility.h src/gitcpp/GitObject.cpp src/gitcpp/GitObject.h src/gitcpp/GitObjectType.cpp src/gitcpp/GitObjectType.h src/gitcpp/GitObjectId.cpp src/gitcpp/GitObjectId.h src/gitcpp/GitObjectIdPrefix.cpp src/gitcpp/GitObjectIdPrefix.h src/gitcpp/interface/IObject.h src/gitcpp/interface/FwdDecl.h src/gitcpp/interface/IObjectId.h src/gitcpp/interface/IObjectType.h src/gitcpp/interface/IReference.h src/gitcpp/interface/IRepository.h src/gitcpp/interface/config/IConfigEntry.h src/gitcpp/interface/config/IConfig.h src/gitcpp/interface/config/IConfigUtil.h src/gitcpp/interface/IIterator.h src/gitcpp/interface/config/IConfigLevel.h src/gitcpp/interface/ICommit.h)
include_directories(thirdparty/libgit2/include)
include_directories(src/gitcpp)
add_executable(gitcpp ${SOURCE_FILES})

add_subdirectory(thirdparty/libgit2)
target_link_libraries(gitcpp git2)