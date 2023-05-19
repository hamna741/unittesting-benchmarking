cmake_minimum_required(VERSION 3.16)
project(Benchmark)

set(BENCHMARK_DOWNLOAD_DEPENDENCIES OFF)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Find and include the Google Benchmark library

include_directories( /home/hamna/Desktop/myproject/benchmarking_unittesting/include)

# Add your benchmark source files and target
add_executable(my_benchmark benchmark.cpp)
target_sources(my_benchmark PRIVATE ${CMAKE_SOURCE_DIR}/src/codility.cpp)
# Link against the benchmark library

target_link_libraries(my_benchmark PRIVATE benchmark::benchmark)
