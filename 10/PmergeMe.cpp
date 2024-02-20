#include "PmergeMe.hpp"

/////////////////////////////////////////////////////////////////////////////// UTILS
void PmergeMe::calc_order_insertions(int argc) {
  int nb_insertions = 50; //(argc - 1) / 2;
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
  for(int i = 0; i < nb_insertions; i++)
    std::cout << std::setw(2) << i << " ";
  std::cout << std::endl;
  for(int i = 0; i < nb_insertions; i++)
    std::cout << std::setw(2) << _order[i] << " ";
  std::cout << std::endl;
  (void)argc;
}

void PmergeMe::my_advance(list_iterator *it, int k) {
  std::advance(*it, k);
  // std::advance(it, _order[k + 1] - _order[k]);
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
  list_iterator it1;
  list_iterator it2;

  if (std::distance(begin, end) <= 1)
    return ;                        //  1 5 4 8 2 7 3 6

  for (list_iterator it = this->begin(); it != this->end(); ++it) 
    std::cout << *it << " ";
  std::cout << std::endl;

  it1 = begin;
  it2 = begin;
  std::advance(it2, (std::distance(begin, end) + 1) / 2);
  for (; it2 != this->end(); ++it1, ++it2)
    if(*it1 < *it2)
        std::swap(*it1, *it2);
  for (list_iterator it = this->begin(); it != this->end(); ++it) 
    std::cout << *it << " ";
  std::cout << std::endl;

  for (list_iterator it = this->begin(); it != this->end(); ) {
    std::cout << *it << " ";
    //std::advance(it, 1);
    my_advance(&it, 1);
  }
  std::cout << std::endl;
}

void PmergeMe::run() {
  run(this->begin(), this->end());
}
