cmake_minimum_required(VERSION 3.16)
project(Benchmark)

# Find and include the Google Benchmark library

include_directories( /home/hamna/Desktop/myproject/benchmarking_unittesting/include)

# Add your benchmark source files and target
add_executable(my_benchmark benchmark.cpp)
#add_library(codilitylib STATIC /home/hamna/Desktop/myproject/benchmarking_unittesting/src/codility.cpp)
# Link against the benchmark library
target_link_libraries(my_benchmark PRIVATE project1_lib benchmark::benchmark)
