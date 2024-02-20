#include "PmergeMe.hpp"

/////////////////////////////////////////////////////////////////////////////// UTILS
void PmergeMe::calc_order_insertions(int argc) {
  nb_insertions = (argc - 3) / 2;
  _order = new int[nb_insertions];
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
      _order[i] = v;
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

std::list<unsigned int> put_map_keys_to_list(std::map<unsigned int, unsigned int> map) {
  std::list<unsigned int> lst;
  lst.push_back(map.begin()->second);
  for(map_iterator it = map.begin(); it != map.end(); ++it)
    lst.push_back(it->first);
  return lst;
}

unsigned int *PmergeMe::put_map_values_to_array_in_order(std::map<unsigned int, unsigned int> map) {
  size_t size_array;
  size_t i;
  map_iterator it;

  unsigned int last_value = (--(map.end()))->second;
  if (last_value == 0)
    size_array = map.size() - 2;
  else
    size_array = map.size() - 1;
  std::cout << std::endl << "size_array = " << size_array << std::endl;
  unsigned int *arr = new unsigned int[size_array];
  for(it = ++(map.begin()), i = 0; i < size_array; ++it, ++i)
    arr[_order[i]] = it->second;
  return arr;
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

void sort_every_pair(std::map<unsigned int, unsigned int> *map) {
  for(map_iterator it = map->begin(); it != map->end();) {
    if(it->first < it->second) {
      map_iterator to_erase = it;
      it++;
      map->insert(map->begin(), std::pair<unsigned int, unsigned int>(to_erase->second, to_erase->first));
      map->erase(to_erase);
    } 
    else
      it++;
  }
}

/////////////////////////////////////////////////////////////////////////////// CONSTRUCTORS
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {
  delete _order;
  // delete arr
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++)
    _lst.push_back(std::strtoul(argv[i], NULL, 10));
  calc_order_insertions(argc);
  std::cout << std::endl << "order: ";
  for(int i = 0; i < nb_insertions; i++)
    std::cout << _order[i] << " ";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::run(std::list<unsigned int> *lst) {
  std::cout << std::endl << "run        : ";                           // 1 2 4 3 8 7 6 5 9
  for (list_iterator it = lst->begin(); it != lst->end(); it++)
    std::cout << *it << " ";
  if (lst->size() <= 1)
    return ;

  std::map<unsigned int, unsigned int> map = put_list_to_map(*lst);    // [2 1] [4 3] [6 5] [8 7] [9 0]
  sort_every_pair(&map);
  std::cout << std::endl << "map with sorted pairs: ";
  for (map_iterator it = map.begin(); it != map.end(); it++)
    std::cout << "[" << it->first << "," << it->second << "] ";

  std::list<unsigned int> half_lst = put_map_keys_to_list(map);        // 1 and 2 4 6 8 9 -> 1 2 4 6 8 9
  std::cout << std::endl << "half list: ";
  for (list_iterator it = half_lst.begin(); it != half_lst.end(); it++)
    std::cout << *it << " ";

  size_t size_array = lst->size() / 2 - 1;
  std::cout << std::endl << "size_array = " << size_array << std::endl;
  unsigned int *arr = put_map_values_to_array_in_order(map);          // 3 5 7 (in order)
  std::cout << std::endl << "arr      : ";
  for (size_t i = 0; i < size_array; i++) // half_lst.size() - 2 if even, half_lst.size() - 3 if odd
    std::cout << arr[_order[i]] << " ";

  // lalf_list sort recursively

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
  run(&_lst);
}
