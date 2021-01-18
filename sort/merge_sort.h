#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#define NUM_THRESHHOLD 6

template <typename Type>
void Merge(Type *_arrayA, Type *_arrayB, int nA, int nB, Type *_arrayOut)
{
    int posA = 0, posB = 0, k = 0;
    while (posA < nA && posB < nB)
    {
        if (_arrayA[posA] < _arrayB[posB])
        {
            _arrayOut[k] = _arrayA[posA];
            posA++;
        }
        else
        {
            _arrayOut[k] = _arrayB[posB];
            posB++;
        }
        k++;
    }
    for (; posA < nA; posA++)
    {
        _arrayOut[k] = _arrayA[posA];
        k++;
    }
    for (; posB < nB; posB++)
    {
        _arrayOut[k] = _arrayB[posB];
        k++;
    }
}

template <typename Type>
void Merge_Sort(Type *_array, int _first, int _last)
{
    if (_last - _first <= NUM_THRESHHOLD)
    {
        printf("|Notice| Insertion sort\n");
        Insertion_Sort_Without_Swap<Type>(_array, _last - _first);
    }
    else
    {
        int midpoint = (_first + _last) / 2;
        Merge_Sort<Type>(_array, _first, midpoint);
        Merge_Sort<Type>(_array, midpoint, _last);
        // Merge(_array, _first, midpoint, _last);
        Type *tmp = new Type[_last - _first];
        Merge(&_array[_first], &_array[midpoint], midpoint - _first, _last - midpoint, tmp);
        for (int i = 0; i < _last - _first; i++)
        {
            _array[_first + i] = tmp[i];
        }
        delete[] tmp;
    }
}

#endif