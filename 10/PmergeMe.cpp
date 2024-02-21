#include "PmergeMe.hpp"

////////////////////////////////////////////////////////// UTILS AND CONSTRUCTORS
void print_list(std::list<unsigned int> *lst) {
  list_iterator it;
  for (it = lst->begin(); it != lst->end(); it++) 
    std::cout << std::setw(2) << *it << " ";
  --it;
  std::cout << "(begin = " << *(lst->begin()) << " end = " << *it << ")\n";
}

std::list<unsigned int> calc_particular_positions(int N) {
  std::list<unsigned int> particular_positions;
  int jac1 = 0; // jacobstahl numbers
  int jac2 = 1;
  while (1) {
    int jac3 = 2 * jac1 + jac2;
    if (jac3 > N)
      break;
    particular_positions.push_back(jac3 -1);
    jac1 = jac2;
    jac2 = jac3;
  }
  return particular_positions;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++)
    this->push_back(std::strtoul(argv[i], NULL, 10));
  particular_positions = calc_particular_positions(argc - 2);
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::~PmergeMe() { } //

int min (int a, int b) {
  if(a < b)
    return a;
  return b;
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

list_iterator PmergeMe::insert_before_(list_iterator begin, list_iterator end, unsigned int a) {
  while(1) {
    list_iterator middle = begin;
    std::advance(middle, std::distance(begin, end) / 2);
    if(a == *middle)
      return ++middle;
    else if(a < *middle)
      end = middle;
    else if(a > *middle)
      begin = middle;
    if(std::distance(begin, end) <= 1)
      return ++begin;
  }
}

void PmergeMe::run(list_iterator begin, list_iterator end) {
  if (std::distance(begin, end) <= 1) // <= 0
    return ;
  print_list(this);

  list_iterator middle = begin;
  std::advance(middle, (std::distance(begin, end) + 1) / 2);
  list_iterator it = begin;
  list_iterator it2 = middle;
  for (; it2 != end; ++it, ++it2)
    if(*it < *it2)
      std::swap(*it, *it2);
  print_list(this);

  it = middle;
  ++it;
  for (int k = 0; it != end && k < std::distance(middle, end); k++) {
    std::cout << "insert " << std::setw(2) << *it << " (from pos " << std::setw(2) << std::distance(begin, it) << ") ";
    //std::cout << *it << " < " << *begin << " ?\n";
    if (*it < *begin) {
      std::cout << "in the beginning " << std::endl;
      this->insert(begin, *it);
      --begin;
      print_list(this);
    }
    else {
      list_iterator insert_before = insert_before_(begin, middle, *it);
      std::cout << "before " << *insert_before << std::endl;
      this->insert(insert_before, *it);
      print_list(this);
    }
    my_advance(&it, middle, end);
  }
}

void PmergeMe::run() {
  run(this->begin(), this->end());
}