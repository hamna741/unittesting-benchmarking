# UNIT TESTING & BENCHMARKING
## GETTING STARTED
See [Google Test documentation](https://github.com/google/googletest/blob/main/docs/primer.md) to gain familiarity with the concept.

## PROJECT HIRARCHY
    .
    ├──build
    ├── include
    │   ├── codility.h   
    ├── src
    │   ├── codility.cpp
    |   ├── main.cpp
    |   ├── CMakeLists.txt
    ├── BENCHMARK
    │   ├── benchmark.cpp
    |   ├── CMakeLists.txt
    ├── uniitest
    │   ├── unittest.cpp
    |   ├── CMakeLists.txt
    ├──googletest
    ├──.gitignore
    ├──.gitmodules
    ├──CMakELists.txt

First, create a directory for your project:

```
mkdir BENCHMARKING_UNIITESTING && cd BENCHMARKING_UNIITESTING
```


 
### TOP LEVEL CMAKE FILE
The top level CMakeListst.txt file defines complilation flags and option to run unit tst or benchmark seperatly.

```

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME benchmark_gtest)
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
```

Create CMakeLists.txt to configure the build system for a project. You’ll use this file to set up your project and declare  GoogleTest and benchmarking dependencies.
## RUNING UNIT TESTS
execute the command ``` cmake -DBUILD_UNITTESTS=ON ..``` to build test and execute  ```ctest```  to run binary. Alternatively, ```./unittest/runUnitTests``` to do so.
### OUTPUT
```
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from CodilityTest
[ RUN      ] CodilityTest.BinaryGapTest
[       OK ] CodilityTest.BinaryGapTest (0 ms)
[ RUN      ] CodilityTest.FrogJumpTest
[       OK ] CodilityTest.FrogJumpTest (0 ms)
[ RUN      ] CodilityTest.SliceSumTest
/home/hamna/Desktop/myproject/benchmarking_unittesting/unittest/unittest.cpp:21: Failure
Expected equality of these values:
  codility::slice_sum(A1)
    Which is: 6
  5

runUnitTests: /home/hamna/Desktop/myproject/benchmarking_unittesting/unittest/unittest.cpp:27: virtual void CodilityTest_SliceSumTest_Test::TestBody(): Assertion `codility::slice_sum(A3)== 14' failed.
Aborted (core dumped)
```


## Building Benchmarks
To build benchmark run the command  
```
cmake -DBUILD_BENCHMARKS=ON ..
``` 
on terminal. where .. represent location of CMakeLists.txt file in root directory. ```-D``` is used to set ```BUILD_BENCHMARKS```  value to ON. 

## Running Benchmarks

Benchmarks are executed by running the produced binaries. Benchmarks binaries,
by default, accept options that may be specified either through their command


## Output Formats
  
The library supports multiple output formats. Use the
`--benchmark_format=<console|json|csv>` flag (or set the
`BENCHMARK_FORMAT=<console|json|csv>` environment variable) to set
the format type. `console` is the default format.

run 
 ```
 ./BENCHMARK/my_benchmark
 ``` 
 command displays following outout on console:
```
2023-05-21T12:39:59+05:00
Running ./BENCHMARK/my_benchmark
Run on (8 X 4700 MHz CPU s)
CPU Caches:
  L1 Data 48 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 1280 KiB (x4)
  L3 Unified 12288 KiB (x1)
Load Average: 0.33, 0.36, 0.52
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
***WARNING*** Library was built as DEBUG. Timings may be affected.
------------------------------------------------------------
Benchmark                  Time             CPU   Iterations
------------------------------------------------------------
BM_BinaryGap/1         18282 ns        18283 ns        35935
BM_BinaryGap/8         18490 ns        18491 ns        38138
BM_BinaryGap/64        18301 ns        18302 ns        38239
BM_BinaryGap/512       18293 ns        18294 ns        38269
BM_BinaryGap/1024      18302 ns        18303 ns        38233
BM_BinaryGap_BigO   18333.71 (1)    18334.84 (1)  
BM_BinaryGap_RMS           0 %             0 %    
BM_FrogJump           388163 ns       388187 ns         1803
BM_SliceSum              354 ns          354 ns      1983789
```
For json formated code with results written in file 
``` 
./BENCHMARK/my_benchmark --benchmark_format=json --benchmark_out=benchmarkreport.txt
```

```{
  "context": {
    "date": "2023-05-21T12:44:49+05:00",
    "host_name": "hamna-Vostro-15-3510",
    "executable": "./BENCHMARK/my_benchmark",
    "num_cpus": 8,
    "mhz_per_cpu": 4700,
    "cpu_scaling_enabled": true,
    "caches": [
      {
        "type": "Data",
        "level": 1,
        "size": 49152,
        "num_sharing": 2
      },
      {
        "type": "Instruction",
        "level": 1,
        "size": 32768,
        "num_sharing": 2
      },
      {
        "type": "Unified",
        "level": 2,
        "size": 1310720,
        "num_sharing": 2
      },
      {
        "type": "Unified",
        "level": 3,
        "size": 12582912,
        "num_sharing": 8
      }
    ],
    "load_avg": [0.11,0.26,0.44],
    "library_build_type": "debug"
  },
  "benchmarks": [
    {
      "name": "BM_BinaryGap/1",
      "family_index": 0,
      "per_family_instance_index": 0,
      "run_name": "BM_BinaryGap/1",
      "run_type": "iteration",
      "repetitions": 1,
      "repetition_index": 0,
      "threads": 1,
      "iterations": 36059,
      "real_time": 1.8424876313825942e+04,
      "cpu_time": 1.8426015918356028e+04,
      "time_unit": "ns"
    },
    {
      "name": "BM_BinaryGap/8",
      "family_index": 0,
      "per_family_instance_index": 1,
      "run_name": "BM_BinaryGap/8",
      "run_type": "iteration",
      "repetitions": 1,
      "repetition_index": 0,
      "threads": 1,
      "iterations": 38137,
      "real_time": 1.8328252196034362e+04,
      "cpu_time": 1.8329201064582950e+04,
      "time_unit": "ns"
    },
    {
      "name": "BM_BinaryGap/64",
      "family_index": 0,
      "per_family_instance_index": 2,
      "run_name": "BM_BinaryGap/64",
      "run_type": "iteration",
      "repetitions": 1,
      "repetition_index": 0,
      "threads": 1,
      "iterations": 38199,
      "real_time": 1.8921229142129207e+04,
      "cpu_time": 1.8921989188198648e+04,
      "time_unit": "ns"
    },
    {
      "name": "BM_BinaryGap/512",
      "family_index": 0,
      "per_family_instance_index": 3,
      "run_name": "BM_BinaryGap/512",
      "run_type": "iteration",
      "repetitions": 1,
      "repetition_index": 0,
      "threads": 1,
      "iterations": 38155,
      "real_time": 1.8701013183075236e+04,
      "cpu_time": 1.8701767605818382e+04,
      "time_unit": "ns"
    },
    {
      "name": "BM_BinaryGap/1024",
      "family_index": 0,
      "per_family_instance_index": 4,
      "run_name": "BM_BinaryGap/1024",
      "run_type": "iteration",
      "repetitions": 1,
      "repetition_index": 0,
      "threads": 1,
      "iterations": 38120,
      "real_time": 1.8276523740814762e+04,
      "cpu_time": 1.8277436778593921e+04,
      "time_unit": "ns"
    },
    {
      "name": "BM_BinaryGap_BigO",
      "family_index": 0,
      "per_family_instance_index": 0,
      "run_name": "BM_BinaryGap",
      "run_type": "aggregate",
      "repetitions": 1,
      "threads": 1,
      "aggregate_name": "BigO",
      "aggregate_unit": "time",
      "cpu_coefficient": 1.8531282111109980e+04,
      "real_coefficient": 1.8530378915175901e+04,
      "big_o": "(1)",
      "time_unit": "ns"
    },
    {
      "name": "BM_BinaryGap_RMS",
      "family_index": 0,
      "per_family_instance_index": 0,
      "run_name": "BM_BinaryGap",
      "run_type": "aggregate",
      "repetitions": 1,
      "threads": 1,
      "aggregate_name": "RMS",
      "aggregate_unit": "percentage",
      "rms": 1.3175602486246331e-02
    },
    {
      "name": "BM_FrogJump",
      "family_index": 1,
      "per_family_instance_index": 0,
      "run_name": "BM_FrogJump",
      "run_type": "iteration",
      "repetitions": 1,
      "repetition_index": 0,
      "threads": 1,
      "iterations": 1772,
      "real_time": 3.8858582957122003e+05,
      "cpu_time": 3.8859918961625325e+05,
      "time_unit": "ns"
    },
    {
      "name": "BM_SliceSum",
      "family_index": 2,
      "per_family_instance_index": 0,
      "run_name": "BM_SliceSum",
      "run_type": "iteration",
      "repetitions": 1,
      "repetition_index": 0,
      "threads": 1,
      "iterations": 1970306,
      "real_time": 3.6699923717427362e+02,
      "cpu_time": 3.6696512013869921e+02,
      "time_unit": "ns"
    }
  ]
}
```


