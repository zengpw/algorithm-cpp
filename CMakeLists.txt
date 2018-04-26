cmake_minimum_required(VERSION 3.8)
project(algorithm-cpp)

set(CMAKE_CXX_STANDARD 11)
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# include path
include_directories("${PROJECT_SOURCE_DIR}/unit_test/googletest/googletest")
include_directories("${PROJECT_SOURCE_DIR}/unit_test/googletest/googletest/include")
include_directories("${PROJECT_SOURCE_DIR}/src")

# source files
file(GLOB_RECURSE src "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE gtest "unit_test/googletest/googletest/src/gtest-all.cc")
file(GLOB_RECURSE gtest_main "unit_test/googletest/googletest/src/gtest_main.cc")
file(GLOB_RECURSE unit_test "${PROJECT_SOURCE_DIR}/unit_test/*.cpp")

list(APPEND src ${gtest})
list(APPEND src ${gtest_main})
list(APPEND src ${unit_test})

message(STATUS "------------- Source Files: -------------")

foreach(s ${src})
    message(${s})
endforeach()

# create bin
add_executable("algorithm-cpp" ${src})

# add pthread support for linux
find_package (Threads)
target_link_libraries (algorithm-cpp ${CMAKE_THREAD_LIBS_INIT})
