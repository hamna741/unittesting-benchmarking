#include <benchmark/benchmark.h>
#include "codility.h"

static void BM_BinaryGap(benchmark::State& state)
{
    int N = 987654321;
    
    for (auto _ : state)
    {  codility::binary_gap(N);
        
    }
}

static void BM_FrogJump(benchmark::State& state)
{
    int X = 0, Y = 1000000000, D = 2;
   
    for (auto _ : state)
    {   
        codility::frog_jump(X,Y,D);
       
    }
}

static void BM_SliceSum(benchmark::State& state)
{
    std::vector<int> A = {1, -2, 3, 4, -5, 0, 7};
   
    for (auto _ : state)
    {
        codility::slice_sum(A);
    }
}

// Define additional benchmark functions for other functions in codility.cpp if needed

// Run the benchmark functions
BENCHMARK(BM_BinaryGap);
BENCHMARK(BM_FrogJump);
BENCHMARK(BM_SliceSum);
// Add more benchmarks if needed

// Run the benchmark
BENCHMARK_MAIN();
