#include "codility.h"
#include <bitset>
int codility::binary_gap(int N)
{
    std::bitset<32> binary(N); // binary representation
    int max_zeros = 0;
    int zero_count = 0;
    bool zero_flag = false;

    for (int i = 0; i < 32; i++)
    {
        if (binary[i])
        { //'1'
            if (zero_flag)
            { // a gap
                max_zeros = std::max(max_zeros, zero_count);
                zero_count = 0; // reset the counter
            }
            else
            {
                zero_flag = true;
            }
        }
        else
        { //'0'
            if (zero_flag)
            {
                zero_count++;
            }
        }
    }
    return max_zeros;
}

int codility::frog_jump(int X, int Y, int D)
{
    int distance = Y - X;
    if (distance % D == 0)
        return distance / D;
    else
        return distance / D + 1;
}

int codility::slice_sum(std::vector<int> &A)
{
    std::vector<int> K1(A.size(), 0);
    std::vector<int> K2(A.size(), 0);

    for (unsigned int i = 1; i < A.size() - 1; i++)
    {
        K1[i] = std::max(K1[i - 1] + A[i], 0);
    }
    for (unsigned int i = A.size() - 2; i > 0; i--)
    {
        K2[i] = std::max(K2[i + 1] + A[i], 0);
    }

    int max = 0;

    for (unsigned int i = 1; i < A.size() - 1; i++)
    {
        max = std::max(max, K1[i - 1] + K2[i + 1]);
    }

    return max;
}