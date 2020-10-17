#include <cstdio>
#include <algorithm>
using namespace std;

template <typename Type>
void Insertion_Sort(Type *_Array, int _n)
{
    // Suppose that first item is already sorted
    for (int i = 1; i < _n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (_Array[j - 1] > _Array[j])
            {
                swap(_Array[j - 1], _Array[j]);
            }
            else
                break;
        }
    }
}

int main()
{
    int arr[10] = {1, 5, 9, 8, 4, 3, 6, 2, 7, 10};
    // Insertion Sort
    Insertion_Sort<int>(arr, sizeof(arr) / sizeof(int));

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}