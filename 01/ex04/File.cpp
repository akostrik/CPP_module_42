#include "File.hpp"

File::File(std::string name_) : mame(name_) {
};

void File::replace(std::string s1, std::string s2) {
	std::ifstream in;
	std::ofstream out;

	in .open(this->name);
	out.open("hello1.txt");
};
