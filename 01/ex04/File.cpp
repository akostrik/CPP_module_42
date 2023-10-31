#include "File.hpp"
#include <iostream>
#include <string> //

// try to pass a file that does not exist, change the permissions, pass it empty, etc.

File::File(const char *in_file_) : in_file(in_file_){
};

int File::replace(std::string s1, std::string s2) {
  std::ifstream in(this->in_file);
	std::string   in_file_str = this->in_file;
  std::ofstream out((in_file_str + ".replace").c_str());
  std::string   content = "";
  std::string   line;

  if (!in.is_open() || !out.is_open())
  {
		std::cout << "file open problem (" << this->in_file << " or " << (in_file_str + ".replace").c_str() << ")" << std::endl;
    return 1;
  }

  while (getline (in, line))
  {
		content += line + "\n";
    std::cout << line << std::endl;
    out       << line << std::endl;
  }
	if (content.length() > 0)
    content.resize(content.length() - 1);

  std::cout << "content :\n" << content << std::endl;

	std::size_t pos = 0;
  for (int i = 0; 1; i = pos + 1)
	{
		pos = content.find(s1, i);
		if (pos == std::string::npos)
			break ;
    std::cout << "pos = " << pos << '\n';;
	}

  in.close();
  out.close();
  (void)s1;
  (void)s2;
	return 0;
};
