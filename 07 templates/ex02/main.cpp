#include "Array.hpp"
#include "Person.hpp"

int main(void) {
    Array<unsigned int>      arr1(5);
    Array<unsigned int>      *arr2 = new Array<unsigned int>(2); // ne w unsigned int[2]
    Array<unsigned int>      *arr3 = new Array<unsigned int>();  // ne w unsigned int(), empty array
    Array<Person>            *arr4 = new Array<Person>(2);
 
    for (unsigned int i = 0; i < arr1.size(); i++)  // initialisations
        arr1[i] = i * 2;
    *arr2 = arr1;
    (*arr4)[0]._name = "Poucette";
    (*arr4)[0]._height = 50;
    (*arr4)[1]._name = "Geant";
    (*arr4)[1]._height = 200;
    std::cout << "arr1: " << arr1  << std::endl;
    std::cout << "arr2: " << *arr2 << std::endl;
    std::cout << "arr3: " << *arr3 << std::endl;
    std::cout << "arr4: " << *arr4  << std::endl;

    try {                                             // test the exception
        std::cout << "valid index:   arr1[3]  = " << arr1[3]  << std::endl;
        std::cout << "valid index:   arr2[3]  = " << arr1[3]  << std::endl;
        std::cout << "invalid index: arr1[10] = " << arr1[10] << std::endl;
    } catch (Array<unsigned int>::OutOfBoundsException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    delete &arr2[0];               // !
    delete (Person*)arr3;          // !
    delete &arr4[0];               // !
    return (0);
}