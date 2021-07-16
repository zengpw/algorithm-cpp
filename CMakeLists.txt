cmake_minimum_required (VERSION 3.20)

project(algorithm-cpp)

# Include
include(${PROJECT_SOURCE_DIR}/file.util.cmake)

# Compiler
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
endif()

# clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GoogleTest as sub module
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://gitlab.com/chromiumsrc/googletest.git
    GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.11.0, gitlab mirror
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# Use GoogleTest
FetchContent_MakeAvailable(googletest)

# Sources
append_source_list(src_list SRC_PATH ${PROJECT_SOURCE_DIR}/test/*.cpp)

# Targets
add_executable(${PROJECT_NAME} ${src_list})

# Header Paths
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}
)

# Dependencies
target_link_libraries(${PROJECT_NAME} gtest_main)

# CTest
include(GoogleTest)
enable_testing()
gtest_discover_tests(${PROJECT_NAME})
