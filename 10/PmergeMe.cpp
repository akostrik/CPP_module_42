#include "PmergeMe.hpp"

/////////////////////////////////////////////////////////////////////////////// UTILS
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

std::list<unsigned int> calc_particular_positions(int N) {
  std::list<unsigned int> particular_positions;
  int jac1 = 0; // jacobstahl numbers
  int jac2 = 1;
  // particular_positions.push_back(0);
  while (1) {
    int jac3 = 2 * jac1 + jac2;
    if (jac3 > N)
      break;
    particular_positions.push_back(jac3 -1);
    jac1 = jac2;
    jac2 = jac3;
  }
  // std::cout << "partic_positions  :  ";
  // for(std::list<unsigned int>::iterator it = particular_positions.begin(); it != particular_positions.end(); ++it)
  //   std::cout << *it << " ";
  // std::cout << std::endl;

  return particular_positions;
}

// 0  1  0  3  2  9  8  7  6  5  4 19 18 17 16 15 14 13 12 11 10 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20                        order

// 0  1  3  5  11  21  43  85  171  341  683  1365  2731  5461  10923  21845  43691  87381  174763  349525                                                jacobstal numbers
//    0  2  4  10  20                                                                                                                                     partic positions
//   (0)(1)(2) (3) (4)                                                                                                                                    numeration partic positions
//[0] 1 [2] 3 [4] 5  6  7  8  9[10]11 12 13 14 15 16 17 18 19[20]21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   partic positions

// 0 [1] 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
//[0] 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +4 (2nd jn, 2^2)

// 0  1  2 [3] 4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
// 0  1 [2] 3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +8 (3st jn, 2^3)

// 0  1  2  3  4  5  6  7  8 [9]10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
// 0  1  2  3 [4] 5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +16 (4th jn, 2^4)

// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18[19]20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
// 0  1  2  3  4  5  6  7  8  9[10]11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +32 (5th jn, 2^5)

// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40[41]42 43 44 45 46 47 48 49   -1 
// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19[20]21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +64 (6th jn, 2^6)


int min (int a, int b) {
  if(a < b)
    return a;
  return b;
}

void PmergeMe::my_advance(list_iterator *it, list_iterator begin, list_iterator end) {
  int pos = std::distance(begin, *it);
  int list_size = std::distance(begin, end);
  std::list<unsigned int>::iterator it_in_part_pos_lst = std::find(particular_positions.begin(), particular_positions.end(), pos);
  if(it_in_part_pos_lst != particular_positions.end()) {
    int pos_in_part_pos_lst = std::distance(particular_positions.begin(),  it_in_part_pos_lst);
    int slide = min(pow(2, pos_in_part_pos_lst + 2) - 1, list_size - pos - 1);
    std::advance(*it, slide);
  }
  else
    std::advance(*it, -1);
}

/////////////////////////////////////////////////////////////////////////////// CONSTRUCTORS

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++)
    this->push_back(std::strtoul(argv[i], NULL, 10));
  particular_positions = calc_particular_positions(argc - 2);
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::~PmergeMe() { } //

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::run(list_iterator begin, list_iterator end) {         //  1 5 4 8 2 7 3 6
  if (std::distance(begin, end) <= 1)
    return ;

  list_iterator middle = begin;
  std::advance(middle, (std::distance(begin, end) + 1) / 2);

  list_iterator it = begin;
  list_iterator it2 = middle;
  for (; it2 != end; ++it, ++it2)
    if(*it < *it2)
        std::swap(*it, *it2);
  std::cout << "pairs swapped     : ";
  for (it = begin; it != end; ++it) 
    std::cout << std::setw(2) << *it << " ";
  std::cout << std::endl;

  it = begin;
  ++it;
  for (int k = 0; it != end && k < std::distance(begin, end); k++) {
    std::cout << "  treat " << std::setw(2) << *it << " in pos " << std::setw(2) << std::distance(begin, it) << std::endl;
    my_advance(&it, begin, end);
  }
  std::cout << std::endl;
}

void PmergeMe::run() {
  run(this->begin(), this->end());
}
