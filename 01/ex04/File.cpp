#include "File.hpp"

File::File(const char *name_as_arr_) : name_as_arr(name_as_arr_){
};

void File::replace(std::string s1, std::string s2) {
  std::ifstream in;
  // std::ifstream in(this->name);
  // std::ofstream out;
  std::string line;

  in.open(this->name_as_arr);
	std::cout << "replace open this->name = " << this->name_as_arr << std::endl;
  // out.open(this.name + ".replace");
	std::cout << "in.is_open() = " << in.is_open() << std::endl;
  if (!in.is_open()) // || !out.is_open())
  {
		std::cout << this->name_as_arr << " or " << this->name_as_arr << ".replace open problem" << std::endl;
    return ;
  }

  while (getline (in, line))
  {
    std::cout << line << '\n';
  }

  in.close();
  // out.close();
  (void)s1;
  (void)s2;
};
