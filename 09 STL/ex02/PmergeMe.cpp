// to avoid using a generic function

#include "PmergeMe.hpp"

int *calc_order_insertions(int argc) {
  int nb_insertions = (argc - 3) / 2;
  int *order = new int[nb_insertions];
  int size_group = 0;
  int k = 1;
  for(int i = 0; i < nb_insertions;) {
    size_group = pow(2, k++) - size_group;
    int where_to_stop = i + size_group;
    int v = i + size_group - 1;
    if(where_to_stop >= argc - 1) {
      v -= (where_to_stop - argc + 1);
      where_to_stop -= (where_to_stop - argc + 1);
    }
    for(; i < where_to_stop && i < nb_insertions; v--, i++) 
      order[i] = v;
  }
  return order;
}

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {
  delete order;
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; argv[i] != NULL; i++) {
    elt_t elt;
    elt.v = std::strtoul(argv[i], NULL, 10);
    elt.pair = NULL;
    if (i % 2 == 0)
      elt.pair = &(lst.back());
    lst.push_back(elt);
  }
  order = calc_order_insertions(argc);
}

void delete_every_second(std::list<elt_t> *lst) {
  size_t size = lst->size();
  std::list<elt_t>::iterator it = lst->begin();
  while(size--) {
    std::list<elt_t>::iterator toErase = it;
    it++;
    if (size%2 == 1)
      lst->erase(toErase);
  }
}

void PmergeMe::run(std::list<elt_t> lst) {
  // sort recursively
  delete_every_second(&lst);
  for (std::list<elt_t>::iterator it = lst.begin(); it != lst.end(); it++)
    std::cout << "[" << it->v << "," << (it->pair != NULL ? it->pair->v : 0) << "] ";
  std::cout << std::endl;
}

void PmergeMe::run() {
  run(lst);
}
