#include "File.hpp"
#include <iostream>
#include <string> //

// try to pass a file that does not exist, change the permissions, pass it empty, etc.
// empty string
// s1 = a, s2 = aaa

File::File(const char *in_file_) : in_file(in_file_){
};

int File::replace(std::string s1, std::string s2) {
  std::ifstream in(this->in_file);
	std::string   in_file_str = this->in_file;
  std::ofstream out;
  std::string   content = "";
  std::string   line;

  if (!in.is_open())
  {
		std::cout << "can't open file " << this->in_file << std::endl;
    return 1;
  }
  out.open((in_file_str + ".replace").c_str());
	if (!out.is_open())
  {
		std::cout << "can't open file " << (in_file_str + ".replace").c_str() << std::endl;
    return 1;
  }

  while (getline (in, line))
    content += line + "\n";
	if (content.length() > 0)
    content.resize(content.length() - 1);

  for (int i = 0; 1; i++)
	{
	  std::cout << "*** content :\n" << content << std::endl;
		std::size_t pos = content.find(s1, i);
		if (pos ==std::string::npos)
			break ;
		if (s1.length() == 1)
		{
			content.erase(pos, s1.length()).insert(pos, s2);
			i = pos + s2.length(); // ?
		}
		else
		{
			content.erase(pos, s1.length()).insert(pos, s2);
			i = pos + s2.length() - 1;
		}
		std::cout << "pos = " << pos << ", i = " << i << std::endl << std::endl;
	}

  out       << content << std::endl;

  in.close();
  out.close();
	return 0;
};
