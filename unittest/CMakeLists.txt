cmake_minimum_required(VERSION 3.16)
project(GTEST)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()


include_directories( /home/hamna/Desktop/myproject/benchmarking_unittesting/include)


add_executable(runUnitTests /home/hamna/Desktop/myproject/benchmarking_unittesting/unittest/unittest.cpp)

target_link_libraries(runUnitTests GTest::gtest_main ${CMAKE_BINARY_DIR}/src/libcod_library.a)
add_test(NAME UnitTests COMMAND runUnitTests)