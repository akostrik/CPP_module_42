// to avoid using a generic function

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {
  delete order;
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for (int i = 1; argv[i] != NULL; i++) {
    lst.push_back(std::strtoul(argv[i], NULL, 10));
    if (i % 2 == 0 && argv[i + 1] != NULL)
      map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), std::strtoul(argv[i + 1], NULL, 10)));
    else if (i % 2 == 0 && argv[i + 1] == NULL)
      map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), std::strtoul(argv[i], NULL, 10)));
  }
  int nb_insertions = (argc - 2) / 2;
  order = new int[nb_insertions];
  int size_group = 0;
  int k = 1;
  for (int i = 0; i < argc - 1;) {
    size_group = pow(2, k) - size_group;
    k++;
    // for (int j = 0; j < size_group; j++)
    //   order[j] = 3;
    i += size_group;
    std::cout << "group " << size_group << ", i = " << i << std::endl;
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
