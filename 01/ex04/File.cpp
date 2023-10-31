#include "File.hpp"

File::File(const char *name_as_string) {
	//name_as_string.copy(this->name_as_arr, name_as_string.length(), 0);
	//this->name_as_arr = &name_as_string[0];
	//this->name_as_arr = name_as_string.data();
	this->name_as_arr = name_as_string;
	std::cout << "constructor name    = " << this->name_as_arr << std::endl;
};

void File::func () {
	std::cout << "func     this->name = " << this->name_as_arr << std::endl;
}

void File::func2 (std::string s1) {
	std::cout << "func2    this->name = " << this->name_as_arr << std::endl;
	(void)s1;
}

// void File::replace(std::string s1, std::string s2) {
//   // std::ifstream in;
//   // std::ifstream in(this->name);
//   // std::ofstream out;
//   // std::string line;

// 	std::cout << "replace  this->name = " << this->name_as_arr << std::endl;
// 	std::cout << "replace  s1         = " << s1 << std::endl;
// 	std::cout << "replace  s2         = " << s2 << std::endl;
//   // in.open(this->name_as_arr);
//   // out.open(this.name + ".replace");
//   // if (!in.is_open()) // || !out.is_open())
//   // {
// 	// 	std::cout << this->name_as_arr << " or " << this->name_as_arr << ".replace open problem" << std::endl;
//   //   return ;
//   // }

//   // while (getline (in, line))
//   // {
//   //   std::cout << line << '\n';
//   // }

//   // in.close();
//   // out.close();
//   (void)s1;
//   (void)s2;
// };
