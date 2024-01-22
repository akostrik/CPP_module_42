#include "Base.hpp"

Base *generate(void) {
  int randV;

  srand(time(NULL));
  randV = rand() % 3;
  if (randV == 0) {
    std::cout << "generate:  A instance created" << std::endl;
    return (new A());
  }
  if (randV == 1) {
    std::cout << "generate:  B instance created" << std::endl;
    return (new B());
  }
  if (randV == 2) {
    std::cout << "generate:  C instance created" << std::endl;
    return (new C());
  }
  return (NULL);
}

// checks if the cast is NULL
void identify(Base *p) {
  if (dynamic_cast<A*>(p))
    std::cout << "Pointer:   A instance detected" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "Pointer:   B instance detected" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "Pointer:   C instance detected" << std::endl;
  else 
    std::cout << "Pointer:   It is not a A, B or C instance" << std::endl;
}

// a try and catch block to check if the cast failed
// pointeris are forbidden
void identify(Base &p) {
  try {
    A& ref = dynamic_cast<A&>(p);
    (void)ref;
    std::cout << "Reference: A instance detected" << std::endl;
    return ;
  } catch (...) {}
  try {
    B& ref = dynamic_cast<B&>(p);
    (void)ref;
    std::cout << "Reference: B instance detected" << std::endl;
    return ;
  } catch (...) {}
  try {
    C& ref = dynamic_cast<C&>(p);
    (void)ref;
    std::cout << "Reference: C instance detected" << std::endl;
    return ;
  } catch (...) {}
  std::cout << "Reference: It is not a A, B or C instance" << std::endl;
}

int main() {
  Base *base = generate();

  identify(base);
  identify(*base);
  delete base;
  return (0);
}
