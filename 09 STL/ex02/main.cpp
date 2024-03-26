// `shuf -i 1-1000 -n 3000 | tr "\n" " " `
// explain the difference in time used for each container selected !!!
// нули
// повторы

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
  std::list<unsigned int> l;
  std::vector<unsigned int> v;

  if (argc < 2) {
    std::cout << "Error: give arguments (a sequence of numbers).\n";
    return 0;
  }

  for(int i = 1; i < argc ; i++) {
    if (argv[i][0] == '\0') {
      std::cout << "Error\n";
      return 0;
    }
    for(std::basic_string<char>::size_type j = 0; j < std::string(argv[i]).size(); j++) {
      if(argv[i][j] >= '0' && argv[i][j] <= '9')
        continue ;
      if(j == 0 && argv[i][0] == '+' && argv[i][1] != '\0')
        continue ;
      if(j == 0 && argv[i][0] == '-') {
        for (j++; argv[i][j] != '\0'; j++) 
          if (argv[i][j] != '0') {
            std::cout << "Error\n";
            return 0;
          }
        continue ;
      }
      std::cout << "Error\n";
    }
    l.push_back(std::strtoul(argv[i], NULL, 10));
    v.push_back(std::strtoul(argv[i], NULL, 10));
  }

  std::cout << "Before:  ";
  for (lst_iter it = l.begin(); it != l.end();++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  PmergeMe p;
  std::list<unsigned int>   res_list = p.run(l);
  std::vector<unsigned int> res_vect = p.run(v);

  std::cout << "After:   ";
  for (lst_iter it = res_list.begin(); it != res_list.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << "After:   ";
  for (vec_iter it = res_vect.begin(); it != res_vect.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << "Time to process a range of " << l.size() << " elements with std::list   : " << std::setw(10) << p.sec_list << " mircosec\n";
  std::cout << "Time to process a range of " << l.size() << " elements with std::vector : " << std::setw(10) << p.sec_vect << " microsec\n";

  return 0;
}

// 0  1  0  3  2  9  8  7  6  5  4 19 18 17 16 15 14 13 12 11 10 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20                        order

// 0  1  3  5  11  21  43  85  171  341  683  1365  2731  5461  10923  21845  43691  87381  174763  349525                                                jacobstal numbers
//    2  2  6  10  22  42                                                                                                                                 size group
//    0  2  4  10  20                                                                                                                                     partic positions
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
