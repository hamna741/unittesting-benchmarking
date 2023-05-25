cmake_minimum_required(VERSION 3.16)
project(Benchmark)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories( /home/hamna/Desktop/myproject/benchmarking_unittesting/include)

add_executable(my_benchmark benchmark.cpp)
target_sources(my_benchmark PRIVATE ${CMAKE_SOURCE_DIR}/src/codility.cpp)
target_link_libraries(my_benchmark PRIVATE benchmark::benchmark)
