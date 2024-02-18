// to avoid using a generic function

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {
  delete order;
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; argv[i] != NULL; i++) {
    lst.push_back(std::strtoul(argv[i], NULL, 10));
    if(i % 2 == 0 && argv[i + 1] != NULL)
      map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), std::strtoul(argv[i + 1], NULL, 10)));
    else if (i % 2 == 0 && argv[i + 1] == NULL)
      map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), std::strtoul(argv[i], NULL, 10)));
  }
  int nb_insertions = (argc - 3) / 2;
  order = new int[nb_insertions];
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
    //std::cout << "group " << size_group << ", where_to_stop = " << where_to_stop << std::endl;
    for(; i < where_to_stop && i < nb_insertions; v--, i++) {
      order[i] = v;
      std::cout << order[i] << " ";
    }
  }
}

void PmergeMe::run(std::map<unsigned int,unsigned int> map) {
// sort recursively
//   for (std::list<unsigned int>::iterator it = lst.begin(); it != lst.end(); ++it)
//     std::cout << lst.front() << std::endl;
  (void)map;
}

void PmergeMe::run() {
  run(map);
}

1 2   3 4   5 6   7 8   9 10