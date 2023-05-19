cmake_minimum_required(VERSION 3.12)
project(Codility)

# Add the source file

include_directories( /home/hamna/Desktop/myproject/benchmarking_unittesting/include)


file(GLOB SRC_FILES ./*.cpp)


########################################
add_library(project1_lib ${SRC_FILES})
add_executable(codility codility.cpp)

# Include the include directory
target_include_directories(codility PUBLIC ../include)
