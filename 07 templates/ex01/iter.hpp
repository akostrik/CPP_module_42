#pragma once
#include <iostream>

template <typename T> void iter(T* arr, int len, void (*func)(T&)) {
    if (arr == NULL)
        return ;
    for (int i = 0; i < len; i++)
        func(arr[i]);
}
