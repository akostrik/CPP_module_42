#include "File.hpp"
#include <iostream>
#include <string> //

// a file that does not exist, change the permissions
// empty string
// s1 = a, s2 = aa
// s1 = "" or s2 == ""

File::File(const char *in_file_) : in_file(in_file_){
};

int File::replace(std::string s1, std::string s2) {
  std::ifstream in(this->in_file);
	std::string   in_file_str = this->in_file;
  std::ofstream out;
  std::string   content = "";
  std::string   line;
	std::size_t   pos;

	if (s1.length() == 0)
		return 1;

  if (!in.is_open())
  {
		std::cout << "can't open file " << this->in_file << std::endl;
    return 1;
  }
  while (getline (in, line))
    content += line + "\n";
	if (content.length() > 0)
    content.resize(content.length() - 1);
  in.close();

  for (int i = 0; 1; )
	{
	  std::cout << "*** content :\n" << content << std::endl;
		pos = content.find(s1, i);
		if (pos == std::string::npos)
			break ;
		content.erase(pos, s1.length()).insert(pos, s2);
		i = pos + s2.length();
		std::cout << "pos = " << pos << ", i = " << i << std::endl << std::endl;
	}

  out.open((in_file_str + ".replace").c_str());
	if (!out.is_open())
  {
	  in.close();
		std::cout << "can't open file " << (in_file_str + ".replace").c_str() << std::endl;
    return 1;
  }
	out << content;
  out.close();

	return 0;
};
