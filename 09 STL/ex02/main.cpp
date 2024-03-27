// `shuf -i 1-1000 -n 3000 | tr "\n" " " `

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
  std::list<unsigned int> l;
  std::vector<unsigned int> v;

  if (argc < 2) {                                                        // arguments verification
    std::cout << "Error: give arguments (a sequence of numbers).\n";
    return 0;
  }

  for(int i = 1; i < argc ; i++) {
    if (argv[i][0] == '\0') {
      std::cout << "Error in arg " << argv[i] << std::endl;
      std::cout << "Error\n";
      return 0;
    }
    for(std::basic_string<char>::size_type j = 0; j < std::string(argv[i]).size(); j++) {
      if(argv[i][j] >= '0' && argv[i][j] <= '9')
        continue ;
      if(j == 0 && argv[i][0] == '+' && argv[i][1] != '\0')
        continue ;
      if(j == 0 && argv[i][0] == '-' && argv[i][1] == '\0') {
        std::cout << "Error in arg " << argv[i] << std::endl;
        return 0;
      }
      if(j == 0 && argv[i][0] == '-') {
        for (j++; argv[i][j] != '\0'; j++) 
          if (argv[i][j] != '0') {
            std::cout << "Error in arg " << argv[i] << std::endl;
            return 0;
          }
        continue ;
      }
      std::cout << "Error in arg " << argv[i] << std::endl;
      return 0;
    }
    if (std::string(argv[i]).compare("4294967295") > 0) {
      std::cout << "Error in arg " << argv[i] << std::endl;
      return 0;
    }
    l.push_back(std::strtoul(argv[i], NULL, 10));
    v.push_back(std::strtoul(argv[i], NULL, 10));
  }

  std::cout << "Before:       ";
  for (lst_iter it = l.begin(); it != l.end();++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  PmergeMe p;
  std::list<unsigned int>   res_list = p.run(l);
  std::vector<unsigned int> res_vect = p.run(v);

  std::cout << "After:        ";
  for (lst_iter it = res_list.begin(); it != res_list.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  // std::cout << "After:        ";
  // for (vec_iter it = res_vect.begin(); it != res_vect.end(); ++it)
  //   std::cout << *it << " ";
  // std::cout << std::endl;
  std::cout << "Time to process a range of " << l.size() << " elements with std::list   : " << std::setw(10) << p.t_lst << " mircosec\n";
  std::cout << "Time to process a range of " << l.size() << " elements with std::vector : " << std::setw(10) << p.t_vec << " microsec\n";

  return 0;
}