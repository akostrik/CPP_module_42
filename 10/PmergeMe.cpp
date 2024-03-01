// std::valarray

#include "PmergeMe.hpp"

////////////////////////////////////////////////////////// UTILS AND CONSTRUCTORS
void PmergeMe::print_list(std::string comment) {
  std::cout << comment << ":\n";
  for (lst_lst_iter it = this->begin(); it != this->end(); ++it) {
    std::cout << std::setw(2) << &(*it) << ": ";
    std::cout << "[";
    for (lst_iter it2 = it->begin(); it2 != it->end(); ++it2)
      std::cout << std::setw(2) << &(*it2) << "(" << *it2 << ") ";
    std::cout << "]\n";
  }
  std::cout << std::endl;
}

lst_lst_iter next(lst_lst_iter it) {
  std::advance(it, 1);
  return it;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char *argv[]) {
  int i;
  int degree_of_2 = 1;
  while(degree_of_2 < argc - 1)
    degree_of_2 *= 2;
  for(i = 1; i < argc ; i++) {
    std::list<unsigned int> new_lst;
    new_lst.push_back(std::strtoul(argv[i], NULL, 10));
    this->push_back(new_lst);
  }
  for(; i <= degree_of_2; i++) {
    std::list<unsigned int> new_lst;
    new_lst.push_back(0);
    this->push_back(new_lst);
  }

  // move_right[0] = 3;
  // move_right[2] = 7;
  // move_right[4] = 15;
  // move_right[10] = 31;
  // move_right[20] = 63;
  // move_right[42] = 127;
  // move_right[84] = 255;
  // move_right[170] = 511;
  // move_right[340] = 1023;
  // move_right[682] = 2047;
  // move_right[1364] = 4095;
  // move_right[2730] = 8191;
  // move_right[5460] = 16383;
  // move_right[10922] = 32767;
  // move_right[21844] = 65535;
  // move_right[43690] = 131071;
  // move_right[87380] = 262143;
  // move_right[174762] = 524287;
  // move_right[349524] = 1048575;
}

PmergeMe::PmergeMe(const PmergeMe& o) : std::list<std::list<unsigned int> >() { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::~PmergeMe() { } //

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void PmergeMe::my_advance(list_iterator *it, list_iterator begin, list_iterator end) {
//   int list_size = std::distance(begin, end);
//   list_iterator tmp = end;
//   --tmp;
//   std::cout << "my_advance     [" << &(*begin) << "(" << *begin << ") " << &(*tmp) << "(" << *tmp << ")] it = " << &(**it) << "(" << **it << "),  lst_size = " << list_size << std::endl;
//   int pos = std::distance(begin, *it);
//   std::list<unsigned int>::iterator is_particular_position = std::find(particular_positions.begin(), particular_positions.end(), pos);
//   //std::cout << "  " << pos << " is_particular_position : " << (is_particular_position != particular_positions.end()) << std::endl;
//   if(is_particular_position != particular_positions.end()) {
//     int number_of_part_position = std::distance(particular_positions.begin(), is_particular_position);
//     int slide = min(pow(2, number_of_part_position + 2) - 1, list_size - pos - 1);
//     std::cout << "  advance +" << slide << std::endl;
//     std::advance(*it, slide);
//   }
//   else {
//     std::cout << "  advance -1" << std::endl;
//     std::advance(*it, -1);
//   }
// }

// list_iterator PmergeMe::insert_before_(list_iterator begin, list_iterator end, unsigned int a) {
//   while(1) {
//     list_iterator middle = begin;
//     std::advance(middle, std::distance(begin, end) / 2);
//     if(a == *middle)
//       return ++middle;
//     else if(a < *middle)
//       end = middle;
//     else if(a > *middle)
//       begin = middle;
//     if(std::distance(begin, end) <= 1)
//       return ++begin;
//   }
// }


// 11   3   9   15   2   10   14   8   16   4   7   1   13   12   6   5
// 3-11     9-15     2-10     8-14     4-16     1-7     12-13     5-6
// 3-11-9-15         2-10-8-14         1-7-4-16         5-6-12-13
// 2-10- 8-14- 3-11- 9-15              1- 7- 4-16- 5- 6-12-13
// 1- 7- 4-16- 5- 6-12-13-2-10- 8-14- 3-11- 9-15
void PmergeMe::join_lists() {
  for(; this->size() > 1 ; ) {
    for(lst_lst_iter it = this->begin(); it != this->end() && next(it) != this->end(); ++it) { //
      if(*(it->begin()) <= *(next(it)->begin())) 
        it->splice(it->end(), *next(it));
      else 
        it->splice(it->begin(), *next(it));
      this->erase(next(it));
    }
  }
}

// 1- 7- 4-16- 5- 6-12-13              2-10- 8-14- 3-11- 9-15
//            (2)                                 (1)

// 1-10-8-14         2-7-4-16     3-11-9-15     5-6-12-13
//     (2)              (1)           (4)           (3)

// 1-10      2-7   3-11   4-16       5-6    8-14   9-15   12-13
//   (2)      (1)    (4)    (3)       (8)     (7)    (6)     (5)

void PmergeMe::separate_lists() {
  for(int len = this->begin()->size() / 2 ; len >= 1; len /= 2) {
    for(lst_lst_iter it = this->begin(); it != this->end(); ++it) { // надо будет препрыгивать
      lst_iter middle = it->begin();
      std::advance(middle, len);
      std::list<unsigned int> new_lst;
      new_lst.splice(new_lst.begin(), *it, middle, it->end());
      this->push_front(new_lst); // надо будет дихотомически
    }
    std::cout << "len = " << len << std::endl;
    print_list("separated");
  }
}

void PmergeMe::run() {
  if(this->size() <= 1)
    return ;
  print_list("this");
  join_lists();
  print_list("joined");
  separate_lists();
  print_list("separated");
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

