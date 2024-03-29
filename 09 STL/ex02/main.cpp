// `shuf -i 1-1000 -n 3000 | tr "\n" " " `
#include "PmergeMe.hpp"
#include <algorithm> 
#include <cctype>
#include <locale>

std::string& trim(std::string& s, const char* t = " \t\n") {
  s.erase(s.find_last_not_of(t) + 1);
  s.erase(0, s.find_first_not_of(t));
  return s;  // valgind ?
}

bool args_are_valid(int argc, char *argv[]) {
  if (argc < 2)
    return false;
  for(int i = 1; i < argc ; i++) {
    std::string s = std::string (argv[i]); 
    s = trim(s);
    if (s.at(0) == '-') {
      s.erase(0, 1);
      if (s.size() == 0)
        return false;
      if(s.find_first_not_of("0") == std::string::npos) // only zeros 
        continue ;
      else
        return false;
    }
    if (s.at(0) == '+')
      s.erase(0, 1);
    if (s.size() == 0)
      return false;
    if (s.find_first_not_of("0") == std::string::npos)  // only zeros
      continue ;
    s.erase(0, s.find_first_not_of('0'));               // erase leading zeros
    if(s.find_first_not_of("0123456789") != std::string::npos)
      return false;
    if (s.size() > std::string("4294967295").size())
      return false;
    if (s.size() == std::string("4294967295").size() && std::string(s).compare("4294967295") > 0)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  std::list<unsigned int> l;
  std::vector<unsigned int> v;

  if (!args_are_valid(argc, argv)) {
    std::cout << "Error: invalid arguments\n";
    return 0;
  }

  for(int i = 1; i < argc ; i++) {
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

  std::cout << "Time to process a range of " << l.size() << " elements with std::list   : " << std::setw(10) << p.t_lst << " mircosec\n";
  std::cout << "Time to process a range of " << l.size() << " elements with std::vector : " << std::setw(10) << p.t_vec << " microsec\n";

  return 0;
}