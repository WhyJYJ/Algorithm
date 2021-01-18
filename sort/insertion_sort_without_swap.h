#ifndef INSERTION_SORT_WITHOUT_SWAP_H
#define INSERTION_SORT_WITHOUT_SWAP_H

template <typename Type>
void Insertion_Sort_Without_Swap(Type *_Array, int _n)
{
    // Suppose that first item is already sorted
    for (int i = 1; i < _n; i++)
    {
        // use var temp to not use swap function
        Type temp = _Array[i];
        for (int j = i; j > 0; j--)
        {
            // if array[j-1] > temp => push back array[j-1]
            if (_Array[j - 1] > temp)
            {
                _Array[j] = _Array[j - 1];
            }
            else
            {
                _Array[j] = temp;
                break;
            }
        }
        if (_Array[0] > temp)
        {
            _Array[0] = temp;
        }
    }
}

#endif