#include "whatever.hpp"
#include "Person.hpp"

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b  << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d  << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl << std::endl;

    Person* p1 = new Person("Poucette", 50);
    Person* p2 = new Person("Geant", 200);
    std::cout << "p1 = " << *p1 << "; p2 = " << *p2 << std::endl;
    std::cout << "min(p1, p2) = " << ::min(*p1, *p2) << std::endl;
    std::cout << "max(p1, p2) = " << ::max(*p1, *p2) << std::endl << std::endl;
    delete p1;
    delete p2;
    
    return 0;
}