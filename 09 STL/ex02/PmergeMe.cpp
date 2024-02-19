#include "PmergeMe.hpp"

/////////////////////////////////////////////////////////////////////////////// UTILS
void PmergeMe::calc_order_insertions(int argc) {
  nb_insertions = (argc - 3) / 2;
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
    for(; i < where_to_stop && i < nb_insertions; v--, i++)
      order[i] = v;
  }
}

map_iterator calc_where_insert(map_iterator begin, map_iterator end, unsigned int a) {
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

void sort_every_pair(std::map<unsigned int, unsigned int> map) {
  for(map_iterator it = map.begin(); it != map.end();) {
    if(it->first < it->second) {
      map_iterator to_erase = it;
      it++;
      map.insert(map.begin(), std::pair<unsigned int, unsigned int>(to_erase->second, to_erase->first));
      map.erase(to_erase);
    } 
    else
      it++;
  }
}

/////////////////////////////////////////////////////////////////////////////// CONSTRUCTORS
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {
  delete order;
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++) {
    if(i % 2 == 1 && argv[i + 1] != NULL)
      _map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i + 1], NULL, 10), std::strtoul(argv[i], NULL, 10)));
    else if (i % 2 == 1 && argv[i + 1] == NULL)
      _map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), 0));
  }
  calc_order_insertions(argc);
  for(int i = 0; i < nb_insertions; i++)
    std::cout << order[i] << " ";
  std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// param position of insert():
// optimizes the insertion time if position points to the element that will precede the inserted element
// is just a hint
// does not force the new elt to be inserted at that position (the elements in a map always follow a specific)
void PmergeMe::run(std::map<unsigned int, unsigned int> map) {
  sort_every_pair(map);

  // sort recursively
  for (map_iterator it = map.begin(), i = 0; it != map.end(); it++)
    if(i % 2 == 1 && argv[i + 1] != NULL)
      map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i + 1], NULL, 10), std::strtoul(argv[i], NULL, 10)));
    else if (i % 2 == 1 && argv[i + 1] == NULL)
      map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), 0));
  }

  map.insert(std::pair<unsigned int, unsigned int>(map.begin()->second, 0)); // insert in the beginning
  for (map_iterator it = map.begin(); it != map.end(); it++)
    std::cout << "[" << it->first << "," << it->second << "] ";
  std::cout << std::endl;

  map_iterator it = ++(++(++(map.begin()))); // если короткая
  std::cout << "it = [" << it->first << " " << it->second << "]" << std::endl;
  for (int i = 0; i < nb_insertions; i++) {
    map_iterator insert_after = calc_where_insert(map.begin(), map.end(), it->second);
    std::cout << "insert " << it->second << " after " << insert_after->first << std::endl;
    map.insert(insert_after, std::pair<unsigned int, unsigned int>(it->second, 0));
    for (map_iterator it = map.begin(); it != map.end(); it++)
      std::cout << "[" << it->first << "," << it->second << "] ";
    std::cout << std::endl;

    std::cout << "advance it [" << it->first << " " << it->second << "] by " << (order[i + 1] - order[i] + 1) << " -> ";
    std::advance(it, order[i + 1] - order[i] + 1);
    std::cout << "[" << it->first << " " << it->second << "]" << std::endl;
  }
  std::cout << std::endl << "final     : ";
  for (map_iterator it = map.begin(); it != map.end(); it++)
    std::cout << "[" << it->first << "," << it->second << "] ";
  std::cout << std::endl;
}

void PmergeMe::run() {
  run(_map);
}
