#ifndef FILE_HPP
# define FILE_HPP

# include <string>
# include <iostream>
# include <fstream>

class File {
private:
  const char  *in_file;

public:
              File(const char* in_file_);
  int         replace(std::string s1, std::string s2);
};

#endif
