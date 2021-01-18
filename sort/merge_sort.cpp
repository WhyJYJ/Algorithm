#define NUM_THRESHHOLD 6

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
    if (_last - _first < NUM_THRESHHOLD)
    {
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