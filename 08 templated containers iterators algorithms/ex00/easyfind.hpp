#pragma once
#include <iostream>

// T est un container d’entiers
template <typename T> void iter(T* arr, int len, void (*func)(T&)) {
    if (arr == NULL)
        return ;
    for (int i = 0; i < len; i++)
        func(arr[i]);
}

// STL algorithms, if it does not (like manual search using iterators for example) -> wrong
template <typename T> void easyfind(T* arr, int n) {
    if (arr == NULL)
        return ;
    for (int i = 0; i < len; i++)
        func(arr[i]);
}
