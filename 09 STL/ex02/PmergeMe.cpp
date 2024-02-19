#include "PmergeMe.hpp"

void PmergeMe::calc_order_insertions(int argc) {
  nb_insertions = (argc - 3) / 2;
  order_insertions = new int[nb_insertions];
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
      order_insertions[i] = v;
  }
}

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {
  delete order_insertions;
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++) {
    if(i % 2 == 1 && argv[i + 1] != NULL)
      map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i + 1], NULL, 10), std::strtoul(argv[i], NULL, 10)));
    else if (i % 2 == 1 && argv[i + 1] == NULL)
      map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), 0));
  }
  calc_order_insertions(argc);
}

map_iterator insert_after_(map_iterator begin, map_iterator end, unsigned int a) {
  while(1) {
    map_iterator middle = begin;
    std::advance(middle, std::distance(begin, end) / 2);
    if(a == middle->first)
      return middle ;
    else if(a < middle->first)
      end = middle;
    else if(a > middle->first)
      begin = middle;
    if(std::distance(begin, end) <= 1)
      return begin;
  }
}

void PmergeMe::run(std::map<unsigned int, unsigned int> map) {
  // sort recursively
  for(map_iterator it = map.begin(); it != map.end();) {
    map_iterator to_erase = it;
    it++;
    if(to_erase->first < to_erase->second) {
      map.insert(map.begin(), std::pair<unsigned int, unsigned int>(to_erase->second, to_erase->first));
      map.erase(to_erase);
    }
  }
  std::cout << std::endl << "    sorted: ";
  for (map_iterator it = map.begin(); it != map.end(); it++)
    std::cout << "[" << it->first << "," << it->second << "] ";
  map.insert(map.begin(), std::pair<unsigned int, unsigned int>(map.begin()->second, 0)); // вручную поставить на место
  std::cout << std::endl << "after in 0: ";
  for (map_iterator it = map.begin(); it != map.end(); it++)
    std::cout << "[" << it->first << "," << it->second << "] ";
  std::cout << std::endl;
  for (map_iterator it = ++map.begin(); it != map.end(); it++) {
    std::cout << " insert " << it->first << " " << it->second << std::endl;
    unsigned int a = it->second;
    map_iterator insert_after = insert_after_(map.begin(), map.end(), a); // order_insertions !!!
    std::cout << a << " insert after " << insert_after->first << std::endl;
    map.insert(map.begin(), std::pair<unsigned int, unsigned int>(a, 0)); // my own insert
  }
  std::cout << std::endl << "final     : ";
  for (map_iterator it = map.begin(); it != map.end(); it++)
    std::cout << "[" << it->first << "," << it->second << "] ";
  std::cout << std::endl;
}

void PmergeMe::run() {
  run(map);
}
