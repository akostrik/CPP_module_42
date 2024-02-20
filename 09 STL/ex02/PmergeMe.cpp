#include "PmergeMe.hpp"

/////////////////////////////////////////////////////////////////////////////// UTILS
void PmergeMe::calc_order_insertions(int argc) {
  int nb_insertions = (argc - 1) / 2;
  _order = new int[nb_insertions];
  int size_group = 0;
  int k = 1;
  int i = 0;
  for(; i < nb_insertions;) {
    size_group = pow(2, k++) - size_group;                                // 0 1  2
    int where_to_stop = std::min(i + size_group - 1, nb_insertions - 1);
    for(int v = where_to_stop; i <= where_to_stop; v--, i++)
      _order[i] = v;
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
    if (it2 == lst.end()) // for ex 1 2 3 4* .*
      break ;
    ++it1;
    ++it2;
    if (it2 == lst.end()) // for ex 1 2 3 4 5* .*
      break ;
  }
  if(std::distance(lst.begin(), lst.end()) % 2 == 1) // for the last map elt (5,0)
    map.insert(std::pair<unsigned int, unsigned int>(*it1, 0));
  return map;
}

std::list<unsigned int> put_map_keys_to_list(std::map<unsigned int, unsigned int> map) {
  std::list<unsigned int> lst;
  for(map_iterator it = map.begin(); it != map.end(); ++it)
    lst.push_back(it->first);
  return lst;
}

unsigned int *PmergeMe::put_map_values_to_array_in_order(std::list<unsigned int> *lst, std::map<unsigned int, unsigned int> map) {
  size_t size_array = lst->size();
  unsigned int *arr = new unsigned int[size_array];
  size_t i = 0;
  for(list_iterator it = lst->begin(); it != lst->end(); ++it)
    arr[_order[i++]] = map[*it];
  return arr;
}

void sort_2_elts_of_pair(std::map<unsigned int, unsigned int> *map) {
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

std::map<unsigned int, list_iterator> inverse_map_(std::list<unsigned int> lst, std::map<unsigned int, unsigned int> map) {
  std::map<unsigned int, list_iterator> inverse_map;
  map_iterator itm = map.begin();
  list_iterator itl = lst.begin();
  for(; itm != map.end(); ++itm, ++itl)
    inverse_map.insert(std::pair<unsigned int, list_iterator>(itm->second, itl));
  return inverse_map;
}

void binary_search_insert(std::list<unsigned int> half_lst, list_iterator begin, list_iterator end, unsigned int a) {
  //list_iterator insert_after_this_elt;
  //list_iterator middle;
  (void)half_lst;
  (void)begin;
  (void)end;
  (void)a;
  // std::cout << "binary_search_insert " << a << " between " << *begin << " and " << *end << std::endl;
  // std::cout << "distance = " << std::distance(begin, end) << std::endl;
  // while(1) {
  //   middle = begin;
  //   std::cout << "middle = " << *middle << " advance by " << (std::distance(begin, end) / 2) << std::endl;
  //   std::advance(middle, std::distance(begin, end) / 2); // left ?
  //   std::cout << "test middle " << *middle << std::endl;
  //   if(a == *middle) {
  //     insert_after_this_elt = middle ;
  //     break ;
  //   }
  //   else if(a < *middle)
  //     end = middle;
  //   else if(a > *middle)
  //     begin = middle;
  //   if(std::distance(lst.begin(), end) <= 1) {
  //     insert_after_this_elt = begin;
  //     break ;
  //   }
  // }
  //lst.insert(insert_after_this_elt, a);
}

/////////////////////////////////////////////////////////////////////////////// CONSTRUCTORS

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() { delete _order; } //

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++)
    _lst.push_back(std::strtoul(argv[i], NULL, 10));
  calc_order_insertions(argc);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::run(std::list<unsigned int> *lst) {
  std::cout << std::endl << "run             : ";                        //  1 7 9 8 4 2 3 10 5 6
  for (list_iterator it = lst->begin(); it != lst->end(); it++)
    std::cout << *it << " ";
  if (lst->size() <= 1)
    return ;

  std::map<unsigned int, unsigned int> map = put_list_to_map(*lst);     
  std::cout << std::endl << "not sorted      : ";
  for (map_iterator it = map.begin(); it != map.end(); it++)
    std::cout << "[" << it->first << "," << it->second << "] ";
  sort_2_elts_of_pair(&map);                                            // [4 2]  [6 5]  [7 1]   [9 8]  [10 3]
  std::cout << std::endl << "map sorted pairs: ";
  for (map_iterator it = map.begin(); it != map.end(); it++)
    std::cout << "[" << it->first << "," << it->second << "] ";

  std::list<unsigned int> half_lst = put_map_keys_to_list(map);         //
  std::cout << std::endl << "half list       : ";
  for (list_iterator it = half_lst.begin(); it != half_lst.end(); it++)
    std::cout << *it << " ";
  // sort lalf_list recursively                                         // 4 6 7 9 10

  std::map<unsigned int, list_iterator> inverse_map = inverse_map_(half_lst, map);// [1 &7] [2 &4] [3 &10] [5 &6] [8 &9]
  std::cout << std::endl << "inverse_map     : ";
  for (std::map<unsigned int, list_iterator>::iterator it = inverse_map.begin(); it != inverse_map.end(); it++)
    std::cout << "[" << it->first << ",&" << *(it->second) << "] ";

  size_t size_array = lst->size() / 2;
  unsigned int *arr = put_map_values_to_array_in_order(&half_lst, map); // map[4] map[6] map[7] map[9] map[10]
  std::cout << std::endl << "arr             : ";                       // 2      5      1      8      3
  for (size_t i = 0; i < size_array; i++)                               // 5      2      8      1      3      (the order of the algo)
    std::cout << arr[i] << " ";
  std::cout << std::endl;

  list_iterator begin = half_lst.begin();
  for (size_t i = 0; i < size_array; i++) {
    std::cout << "end = inverse_map[" << arr[i] << "] = " << *inverse_map[arr[i]] << "\n"; /// !!!!
    list_iterator end = inverse_map[arr[i]];
    if (arr[i] < *(half_lst.begin())) {
      std::cout << "insert " << arr[i] << " in the beginning\n";
      half_lst.push_front(arr[i]);
    }
    else {
      std::cout << "insert " << arr[i] << " between " << *begin << " and " << *end << std::endl;
      //binary_search_insert(half_lst, begin, end, arr[i]);
    }
    ++end;
  }

  std::cout << std::endl;
  delete arr;
}

void PmergeMe::run() {
  run(&_lst);
}
