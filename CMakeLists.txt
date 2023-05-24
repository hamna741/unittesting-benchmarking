
cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME project1)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 11)

option(BUILD_TESTS "Build unit tests" OFF )
option(BUILD_BENCHMARKS "Build benchmarks" OFF)
include_directories( /home/hamna/Desktop/myproject/benchmarking_unittesting/include)
add_subdirectory(./src)

if(BUILD_TESTS)
    message("Building GTEST")
    add_subdirectory(./googletest)
    add_subdirectory(./unittest)
  
endif()

if(BUILD_BENCHMARKS)
    message("Building benchmarks")
    add_subdirectory(./benchmark)
    add_subdirectory(./BENCHMARK)
endif()