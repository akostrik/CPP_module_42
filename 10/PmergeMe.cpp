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

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++)
    this->push_back(std::strtoul(argv[i], NULL, 10));
  calc_order_insertions(argc);
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::~PmergeMe() { delete _order; } //

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::run(list_iterator begin, list_iterator end) {
  if (std::distance(begin, end) <= 1)
    return ;                        //  1 7 9 8 4 2 3 10 5 6
  std::cout << "distance = " << std::distance(begin, end) << std::endl;

  list_iterator it1 = begin;
  list_iterator it2 = end;
  std::advance(it2, (std::distance(begin, end) + 3) / 2);

  std::cout << "1)" << std::endl;
  for (; it2 != end; ++it1, ++it2) {
    std::cout << "[" << *it1 << " " << *it2 << "]\n";
  }
  if(std::distance(begin, end) % 2 == 1)
    std::cout << "[" << *it1 <<"]\n";
  std::cout << std::endl;

  // it1 = begin;
  // it2 = end;
  // for (; it2 != this->end(); ++it1, ++it2)
  //   if(*it1 < *it2)
  //       std::swap(*it1, *it2);

  // std::cout << "2)" << std::endl;
  // it1 = begin;
  // it2 = end;
  // for (; it2 != this->end(); ++it1, ++it2) {
  //   std::cout << "[" << *it1 << " " << *it2 << "]\n";
  // }
  // if(std::distance(begin, end) % 2 == 1)
  //   std::cout << "[" << *it1 <<"]\n";
  // std::cout << std::endl;

}

void PmergeMe::run() {
  run(this->begin(), this->end());
}
