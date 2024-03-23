//  avoid using a generic function

// check this operation by using the following command as an argument to the program
// `shuf -i 1-1000 -n 3000 | tr "\n" " " `
// explain the difference in time used for each container selected

#include "PmergeMe.hpp"
#include <time.h> 

void print_list2(std::string comment, std::list<unsigned int> l) {
  std::cout << comment << ": ";
  for (lst_iter it = l.begin(); it != l.end(); ++it) 
     std::cout << std::setw(2) << *it << " ";
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Error: give arguments (a sequence of numbers).\n";
    return 0;
  }

  std::list<unsigned int> l;
  for(int i = 1; i < argc ; i++) 
    l.push_back(std::strtoul(argv[i], NULL, 10));

  std::cout << "Before:  ";
  for (lst_iter it = l.begin(); it != l.end();++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  clock_t start = clock();
  l = PmergeMe().run_list(l);
  clock_t end = clock();
  float sec_list = (float)(end - start) / CLOCKS_PER_SEC;

  std::cout << "After:   ";
  for (lst_iter it = l.begin(); it != l.end();++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "Time to process a range of " << l.size() << " elements with std::list : " << sec_list << " sec\n";

  return 0;
}