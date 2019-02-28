cmake_minimum_required (VERSION 3.6)

project(algorithm-cpp)

# Include
include(${PROJECT_SOURCE_DIR}/utils/cmake_config/file.util.cmake)

# Compiler
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
endif()

# Sources
append_source_list(src_list SRC_PATH ${PROJECT_SOURCE_DIR}/utils/googletest/googletest/src/gtest-all.cc)
append_source_list(src_list SRC_PATH ${PROJECT_SOURCE_DIR}/utils/googletest/googletest/src/gtest_main.cc)
append_source_list(src_list SRC_PATH ${PROJECT_SOURCE_DIR}/algorithm/*.h)
exclude_source_list(src_list REMOVE_PATH ${PROJECT_SOURCE_DIR}/algorithm/util/*.h)
append_source_list(src_list SRC_PATH ${PROJECT_SOURCE_DIR}/algorithm_test/*.cpp)

# Targets
add_executable(${PROJECT_NAME} ${src_list})

# Header Paths
set(common_inc_path ${PROJECT_SOURCE_DIR}
					${PROJECT_SOURCE_DIR}/algorithm
                    ${PROJECT_SOURCE_DIR}/utils/googletest/googletest/include
                    ${PROJECT_SOURCE_DIR}/utils/googletest/googletest
                    ${PROJECT_SOURCE_DIR}/utils/googletest/googlemock/include
                    ${PROJECT_SOURCE_DIR}/utils/googletest/googlemock
    )

target_include_directories(${PROJECT_NAME} PUBLIC
	${common_inc_path}
    )

# Dependencies
find_package(Threads)

target_link_libraries(${PROJECT_NAME}
    ${CMAKE_THREAD_LIBS_INIT}
    )

