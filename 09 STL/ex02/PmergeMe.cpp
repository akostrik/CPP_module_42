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
    if (i % 2 == 1)
      elt.pair = &(lst.front());
    lst.push_front(elt);
  }
  order = calc_order_insertions(argc);
}

void PmergeMe::run(std::list<elt_t> lst) {
// sort recursively

  for (std::list<elt_t>::iterator it = lst.begin(); it != lst.end(); ++it)
    std::cout << it->v << std::endl;
}

void PmergeMe::run() {
  run(lst);
}
