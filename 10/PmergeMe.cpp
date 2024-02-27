#include "PmergeMe.hpp"

////////////////////////////////////////////////////////// UTILS AND CONSTRUCTORS
void print_list(list_iterator begin, list_iterator end, std::string comment) {
  list_iterator it;
  std::cout << std::setw(15) << comment << " ";
  for (it = begin; it != end; ++it) 
    std::cout << std::setw(2) << &(*it) << "(" << *it << ") ";
  std::cout << std::endl;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++)
    this->push_back(std::strtoul(argv[i], NULL, 10));
  move_right[0] = 3;
  move_right[2] = 7;
  move_right[4] = 15;
  move_right[10] = 31;
  move_right[20] = 63;
  move_right[42] = 127;
  move_right[84] = 255;
  move_right[170] = 511;
  move_right[340] = 1023;
  move_right[682] = 2047;
  move_right[1364] = 4095;
  move_right[2730] = 8191;
  move_right[5460] = 16383;
  move_right[10922] = 32767;
  move_right[21844] = 65535;
  move_right[43690] = 131071;
  move_right[87380] = 262143;
  move_right[174762] = 524287;
  move_right[349524] = 1048575;
}

PmergeMe::PmergeMe(const PmergeMe& o) : std::list<unsigned int>() { *this = o; }

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
//[0] 1 [2] 3 [4] 5  6  7  8  9[10]11 12 13 14 15 16 17 18 19[20]21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41[42]43 44 45 46 47 48 49   partic positions
//[1] 0 [3] 2 [9] 8  7  6  5  4[19]18 17 16 15 14 13 12 11 10[41]40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20
//+3    +7    +15              +31

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
  int list_size = std::distance(begin, end);
  list_iterator tmp = end;
  --tmp;
  std::cout << "my_advance     [" << &(*begin) << "(" << *begin << ") " << &(*tmp) << "(" << *tmp << ")] it = " << &(**it) << "(" << **it << "),  lst_size = " << list_size << std::endl;
  int pos = std::distance(begin, *it);
  std::list<unsigned int>::iterator is_particular_position = std::find(particular_positions.begin(), particular_positions.end(), pos);
  //std::cout << "  " << pos << " is_particular_position : " << (is_particular_position != particular_positions.end()) << std::endl;
  if(is_particular_position != particular_positions.end()) {
    int number_of_part_position = std::distance(particular_positions.begin(), is_particular_position);
    int slide = min(pow(2, number_of_part_position + 2) - 1, list_size - pos - 1);
    std::cout << "  advance +" << slide << std::endl;
    std::advance(*it, slide);
  }
  else {
    std::cout << "  advance -1" << std::endl;
    std::advance(*it, -1);
  }
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
  print_list(begin, end, "run");
  print_list(this->begin(), this->end(), "this");

  if (std::distance(begin, end) <= 1) // <= 0
    return ;

  list_iterator middle = begin;
  std::advance(middle, (std::distance(begin, end) + 1) / 2); // не мог ли он куда-то переместиться?
  list_iterator it  = begin;
  list_iterator it2 = middle;
  for (; it2 != end; ++it, ++it2)
    if(*it > *it2)
      std::swap(*it, *it2);
  print_list(begin, end, "swapped");

  run(begin, middle);
  print_list(begin, middle, "sorted part");

  it = middle;
  for (int k = 0; it != end && k <= std::distance(middle, end); k++) {
    std::cout << "insert " << std::setw(2) << *it << " (from pos " << std::setw(2) << std::distance(begin, it) << ") ";
    if (*it < *begin) {
      std::cout << "in the beginning " << std::endl;
      begin = this->insert(begin, *it);
    }
    else {
      list_iterator insert_before = insert_before_(begin, middle, *it);
      std::cout << "before " << *insert_before << std::endl;
      this->insert(insert_before, *it);
    }
    print_list(begin, end, "for");
    print_list(this->begin(), this->end(), "this");
    my_advance(&it, middle, end);
  }
  this->erase(middle, end);
  print_list(this->begin(), this->end(), "this erased");
}

void PmergeMe::run() {
  run(this->begin(), this->end());
}