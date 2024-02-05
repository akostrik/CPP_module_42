#pragma once
#include <iostream>

template <typename T1, typename T2, typename FUNC_T> void iter(T1* arr, int len, FUNC_T (*func)(T2&)) {
    if (arr == NULL)
        return ;
    for (int i = 0; i < len; i++)
        func(arr[i]);
}
