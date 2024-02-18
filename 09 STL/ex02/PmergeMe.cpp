// to avoid using a generic function

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& o) {
  *this = o;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& o) {
//   std::stack<float>::container_type underliyng_cont_o    = o.c;
//   this->c = underliyng_cont_o;
  return *this;
}

PmergeMe::PmergeMe(char *argv[]) {
  for (int i = 0; argv[i] != NULL; i++)
    l.insert(std::strtoul(argv[i]), , 10);

}

void PmergeMe::run() {
  //std::cout << this->top() << std::endl;
}