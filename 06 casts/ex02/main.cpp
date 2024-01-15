
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
  int secret_num;

  srand(time(NULL));
  secret_num = rand() % 3;

  if (secret_num == 0) {
    std::cout << "Class A was created" << std::endl;
    return (new A());
  }
  if (secret_num == 1) {
    std::cout << "Class B was created" << std::endl;
    return (new B());
  }
  if (secret_num == 2) {
    std::cout << "Class C was created" << std::endl;
    return (new C());
  }
  std::cout << "nothing was created in generate()" << std::endl;
  return (NULL);
}

// checks if Give the cast is NULL
void identify(Base *p) {
  if (dynamic_cast<A*>(p))
    std::cout << "Pointer: It is a class A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "Pointer: it is a class B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "Pointer: It is a class C" << std::endl;
  else 
    std::cout << "Pointer: It is not a class A, B or C" << std::endl;
}

// uses a try and catch block to check if the cast failed
void identify(Base &p) {
  if (dynamic_cast<A*>(&p))
    std::cout << "Reference: It is a class A" << std::endl;
  else if (dynamic_cast<B*>(&p))
    std::cout << "Reference: it is a class B" << std::endl;
  else if (dynamic_cast<C*>(&p))
    std::cout << "Reference: It is a class C" << std::endl;
  else 
    std::cout << "Reference: It is not a class A, B or C" << std::endl;
}

int main() {
  Base *base = generate();

  if (base == NULL) {
    std::cout << "malloc error" << std::endl;
    return (1);
  }

  std::cout << "Using a pointer:" << std::endl;
  identify(base);
  std::cout << "Using a reference:" << std::endl;
  identify(*base);

  delete base;
  return (0);
}