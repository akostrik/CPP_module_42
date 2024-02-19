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

list_iterator calc_where_insert(list_iterator begin, list_iterator end, unsigned int a) {
  while(1) {
    list_iterator middle = begin;
    std::advance(middle, std::distance(begin, end) / 2);
    if(a == *middle)
      return middle ;
    else if(a < *middle)
      end = middle;
    else if(a > *middle)
      begin = middle;
    if(std::distance(begin, end) <= 1)
      return begin;
  }
}

std::map<unsigned int, unsigned int> put_list_to_map(std::list<unsigned int> lst) {
  list_iterator it1 = lst.begin();
  list_iterator it2 = ++(lst.begin());
  std::map<unsigned int, unsigned int> map;
  while(1) {
    map.insert(std::pair<unsigned int, unsigned int>(*it1, *it2));
    ++it1;
    ++it2;
    if (it2 == lst.end()) // even number of elements 1 2 3 4* .*
      break ;
    ++it1;
    ++it2;
    if (it2 == lst.end()) // odd  number of elements 1 2 3 4 5* .*
      break ;
  }
  if(std::distance(lst.begin(), lst.end()) % 2 == 1 )
    map.insert(std::pair<unsigned int, unsigned int>(*it1, 0));
  return map;
}

void erase_every_2nd_elt(std::list<unsigned int> *lst) {
  size_t size = lst->size();
  std::list<unsigned int>::iterator it = lst->begin();
  while(size--) {
    std::list<unsigned int>::iterator toErase = it;
    it++;
    if (size%2 == 1)
      lst->erase(toErase);
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
  for(int i = 1; i < argc; i++)
    _lst.push_back(std::strtoul(argv[i], NULL, 10));
  calc_order_insertions(argc);
  for(int i = 0; i < nb_insertions; i++)
    std::cout << order[i] << " ";
  std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::run(std::list<unsigned int> lst) {
  std::map<unsigned int, unsigned int> map = put_list_to_map(lst);
  for (list_iterator it = lst.begin(); it != lst.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  erase_every_2nd_elt(&lst);
  for (list_iterator it = lst.begin(); it != lst.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  // sort_every_pair(map);

  // // sort recursively

  // unsigned int insertions[std::distance(lst.begin(), lst.end())]; // [2 0] [8 0] [4 0] [6 0] and 1 3 7 5
  // for (list_iterator it = map.begin(); it != map.end(); it++)
  //   if (std::distance(map.begin(), it) % 2 == 1)
  //   if(i % 2 == 1 && argv[i + 1] != NULL)
  //     map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i + 1], NULL, 10), std::strtoul(argv[i], NULL, 10)));
  //   else if (i % 2 == 1 && argv[i + 1] == NULL)
  //     map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), 0));
  // }

  // map.insert(std::pair<unsigned int, unsigned int>(map.begin()->second, 0)); // insert in the beginning

  // list_iterator it = ++(++(++(map.begin()))); // если короткая
  // std::cout << "it = [" << it->first << " " << it->second << "]" << std::endl;
  // for (int i = 0; i < nb_insertions; i++) {
  //   list_iterator insert_after = calc_where_insert(map.begin(), map.end(), it->second);
  //   std::cout << "insert " << it->second << " after " << insert_after->first << std::endl;
  //   map.insert(insert_after, std::pair<unsigned int, unsigned int>(it->second, 0));
  //   for (list_iterator it = map.begin(); it != map.end(); it++)
  //     std::cout << "[" << it->first << "," << it->second << "] ";
  //   std::cout << std::endl;

  //   std::cout << "advance it [" << it->first << " " << it->second << "] by " << (order[i + 1] - order[i] + 1) << " -> ";
  //   std::advance(it, order[i + 1] - order[i] + 1);
  //   std::cout << "[" << it->first << " " << it->second << "]" << std::endl;
  // }
  // std::cout << std::endl << "final     : ";
  // for (list_iterator it = map.begin(); it != map.end(); it++)
  //   std::cout << "[" << it->first << "," << it->second << "] ";
  // std::cout << std::endl;
}

void PmergeMe::run() {
  run(_lst);
}
