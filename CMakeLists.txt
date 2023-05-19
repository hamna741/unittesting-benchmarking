
cmake_minimum_required(VERSION 3.16)


set(PROJECT_NAME project1)
project(${PROJECT_NAME})



set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 11)




option(BUILD_TESTS "Build unit tests" )
option(BUILD_BENCHMARKS "Build benchmarks")
add_subdirectory(./src)

if(BUILD_TESTS)
    
    add_subdirectory(./googletest)
    add_subdirectory(./unittest)
  
endif()

if(BUILD_BENCHMARKS)
  # add_subdirectory(./src)
    add_subdirectory(./benchmark)
    add_subdirectory(BENCHMARK)
   
    
endif() 