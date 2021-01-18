#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

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

#endif