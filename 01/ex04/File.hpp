#ifndef FILE_HPP
# define FILE_HPP
# include <string>
# include <iostream>

class File {
private:
  std::string name;

public:
              File(std::string type);
  void        replace(std::string s1, std::string s2);
};

#endif
