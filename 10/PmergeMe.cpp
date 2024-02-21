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

std::set<unsigned int> calc_jacobstal_numbers(int N) {
  std::set<unsigned int> jacobstal_numbers;
  int jac1 = 0;
  jacobstal_numbers.insert(jac1);
  int jac2 = 1;
  if (jac2 < N)
    jacobstal_numbers.insert(jac1);
  while (1) {
    int jac3 = 2 * jac1 + jac2;
    if (jac3 > N)
      break;
    jacobstal_numbers.insert(jac3);
    jac1 = jac2;
    jac2 = jac3;
  }
  std::cout << "jacobstal numbers : ";
  for(std::set<unsigned int>::iterator it = jacobstal_numbers.begin(); it != jacobstal_numbers.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  return jacobstal_numbers;
}

// (0  1)  1  3  5  11  21  43  85  171  341  683  1365  2731  5461  10923  21845  43691  87381  174763  349525                                             jacobstal numbers
// 0  1  0  3  2  9  8  7  6  5  4 19 18 17 16 15 14 13 12 11 10 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20                        order
//[0] 1 [2] 3 [4] 5  6  7  8  9[10]11 12 13 14 15 16 17 18 19[20]21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   particular positions =jacobstal numbers -1

// 0 [1] 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
//[0] 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +4

// 0  1  2 [3] 4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
// 0  1 [2] 3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +8

// 0  1  2  3  4  5  6  7  8 [9]10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
// 0  1  2  3 [4] 5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +16

// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18[19]20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
// 0  1  2  3  4  5  6  7  8  9[10]11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +32

// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40[41]42 43 44 45 46 47 48 49   -1 
// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19[20]21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +64


void PmergeMe::my_advance(list_iterator *it, list_iterator begin) {
  //std::advance(*it, k);
  // if (std::distance(begin, *it) == 1 || std::distance(begin, *it) == 1 || )
  //   std::advance(*it, _order[k + 1] - _order[k]);
  // else
    std::advance(*it, 1);
    (void)begin;
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
  calc_jacobstal_numbers(argc - 2);
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

  for (list_iterator it = ++(this->begin()); it != this->end(); ) {
    std::cout << *it << " ";
    //std::advance(it, 1);
    my_advance(&it, begin);
  }
  std::cout << std::endl;
}

void PmergeMe::run() {
  run(this->begin(), this->end());
}
