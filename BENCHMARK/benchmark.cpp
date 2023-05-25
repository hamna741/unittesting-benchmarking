#include <benchmark/benchmark.h>
#include "codility.h"



static void BM_BinaryGap(benchmark::State &state)
{
  
    for (auto _ : state)
    {
         int N = state.range(0);
        
       
        codility::binary_gap(N);
    }
 
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

  std::vector<int> A(state.range(0), 1);
 
    for (auto _ : state)
    {
        codility::slice_sum(A);
    }

}

BENCHMARK(BM_BinaryGap)->RangeMultiplier(3)->Range(1,1<<10)->Complexity(benchmark::oAuto);
BENCHMARK(BM_FrogJump);
BENCHMARK(BM_SliceSum)->Range(10, 10000)->Complexity(benchmark::oAuto);

BENCHMARK_MAIN();
