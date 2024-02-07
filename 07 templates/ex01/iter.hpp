#pragma once
#include <iostream>

template <typename T1, typename T2> void iter(T1* arr, int len, void (*func)(T2&)) {
    if (arr == NULL)
        return ;
    for (int i = 0; i < len; i++)
        func(arr[i]);
}
