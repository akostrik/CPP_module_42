#include "Array.hpp"

int main(void) {
    Array<int>      arr1(5);
    Array<int>      *arr2 = new Array<int>();
    Array<float>    arr3(5);

    for ( unsigned int i = 0; i < arr1.size(); i++) {
        arr1[i] = i * 2;
        arr3[i] = arr1[i] + 0.5;
    }
    *arr2 = arr1;
    std::cout << "arr1: " << arr1 << std::endl;
    std::cout << "arr2: " << *arr2 << std::endl;
    std::cout << "arr3: " << arr3 << std::endl;

    try {
        std::cout << "valid index:   arr1[3]  = " << arr1[3]  << std::endl;
        std::cout << "valid index:   arr2[3]  = " << arr1[3]  << std::endl;
        std::cout << "invalid index: arr1[10] = " << arr1[10] << std::endl;
    } catch (Array<int>::OutOfBoundsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return ( 0 );
}