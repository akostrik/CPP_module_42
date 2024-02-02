#pragma once ///////////// ?
#include <iostream>

// The third parameter can be an instantiated function template
template <typename T> void iter(T* arr, int len, void (*func)(T&)) {
    if (arr == NULL)
        return ;
    for (int i = 0; i < len; i++)
        func(arr[i]);
}
