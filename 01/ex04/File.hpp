#ifndef FILE_HPP
# define FILE_HPP
# include <string>
# include <iostream>
# include <fstream>

class File {
public: //private:
	const char *name_as_arr;

public:
              File(const char* name_as_string);
  void        replace(std::string s1, std::string s2);
  void        func();
	void        func2(std::string s1);
};

#endif
