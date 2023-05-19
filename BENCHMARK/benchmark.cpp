#include <benchmark/benchmark.h>
#include "codility.h"
#include <random>
#include <string>

int generateBinaryInput(int N)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, (1 << N) - 1);

    return dis(gen);
}
static void BM_BinaryGap(benchmark::State &state)
{
   
    for (auto _ : state)
    {
         int N = state.range(0);
        int input =generateBinaryInput(N);
        codility::binary_gap(input);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_FrogJump(benchmark::State &state)
{
    int X = 0, Y = 1000000000, D = 2;
    int count = 0;
    for (auto _ : state)
    {
        for (count = 0; count < 100000; count++)
        {
            codility::frog_jump(X, Y, D);
        }
    }
}

static void BM_SliceSum(benchmark::State &state)
{
    std::vector<int> A = {1, -2, 3, 4, -5, 0, 7};

    for (auto _ : state)
    {
        codility::slice_sum(A);
    }
}

// Define additional benchmark functions for other functions in codility.cpp if needed

// Run the benchmark functions
BENCHMARK(BM_BinaryGap)->Range(1,1<<10)->Complexity(benchmark::oAuto);
BENCHMARK(BM_FrogJump);
BENCHMARK(BM_SliceSum);
// Add more benchmarks if needed

// Run the benchmark
BENCHMARK_MAIN();
