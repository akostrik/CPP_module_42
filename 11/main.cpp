//  avoid using a generic function

// check this operation by using the following command as an argument to the program
// `shuf -i 1-1000 -n 3000 | tr "\n" " " `
// explain the difference in time used for each container selected

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Error: give arguments (a sequence of numbers).\n";
    return 0;
  }

  std::list<unsigned int> l;
  for(int i = 1; i < argc ; i++) 
    l.push_back(std::strtoul(argv[i], NULL, 10));

  PmergeMe().run(&l);

  return 0;
}

