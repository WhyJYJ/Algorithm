#include <cstdio>
#include <cstring>
#include <random>
#include <algorithm>
#include <chrono>
#include "insertion_sort_without_swap.h"
#include "insertion_sort.h"
#include "merge_sort.h"
using namespace std;

template <typename Type>
bool Is_Sorted(Type *_array, int _n)
{
    for (int i = 1; i < _n; i++)
    {
        if (_array[i - 1] > _array[i])
        {
            printf("[Error] %d, %d / %d %d\n", i - 1, i, _array[i], _array[i - 1]);
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> dis(0, 10 * 1000 * 1000);

    int N = atoi(argv[1]);
    printf("[Notice} N : %d\n", N);

    int *data = new int[N];

    for (int i = 0; i < N; i++)
    {
        data[i] = dis(gen);
        printf("10%d\n", data[i]);
    }

    // start counting
    std::chrono::time_point<std::chrono::high_resolution_clock> start =
        std::chrono::high_resolution_clock::now();

    if (strcmp(argv[2], "insertion") == 0)
    {
        Insertion_Sort<int>(data, N);
    }
    else if (strcmp(argv[2], "insertion_without_swap") == 0)
    {
        Insertion_Sort_Without_Swap<int>(data, N);
    }
    else if (strcmp(argv[2], "std") == 0)
    {
        sort(&data[0], &data[N]);
    }
    else if (strcmp(argv[2], "merge") == 0)
    {
        Merge_Sort<int>(data, 0, N);
    }

    // end counting
    std::chrono::time_point<std::chrono::high_resolution_clock> end =
        std::chrono::high_resolution_clock::now();

    std::chrono::milliseconds timeDiff = std::chrono::duration_cast<chrono::milliseconds>(end - start);

    bool isCorrect = Is_Sorted<int>(data, N);

    if (isCorrect)
        printf("[Notice] Correct\n");
    else
        printf("[Notice] Wrong\n");

    double T = timeDiff.count();

    printf("[Notice] Runtime = %d ms\n", (int)T);

    printf("[Notice] Sorted\n");
    for (int i = 0; i < N; i++)
    {
        printf("10%d\n", data[i]);
    }

    return 1;
}
