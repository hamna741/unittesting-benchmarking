cmake_minimum_required(VERSION 3.16)
project(Codility)

# Add the source file

include_directories( ${${CMAKE_BINARY_DIR}}/include)


file(GLOB SRC_FILES ./*.cpp)



add_library(cod_library ${SRC_FILES})
add_executable(codility  ${SRC_FILES})

# Include the include directory
target_include_directories(codility PUBLIC ../include)