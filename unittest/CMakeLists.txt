cmake_minimum_required(VERSION 3.16)
project(GTEST)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()


include_directories( /home/hamna/Desktop/myproject/benchmarking_unittesting/include)

# Unit Tests
add_executable(tests /home/hamna/Desktop/myproject/benchmarking_unittesting/src/codility.cpp)
target_link_libraries(tests gtest_main)
add_executable(runUnitTests ${PROJECT_SOURCE_DIR}/unittest.cpp)

target_link_libraries(runUnitTests GTest::gtest_main)
add_test(NAME UnitTests COMMAND runUnitTests)