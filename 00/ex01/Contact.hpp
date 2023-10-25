#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phone;
	std::string secret;
	std::string getInput(std::string str);
	std::string shortened(std::string &s);
	std::string trimmed_(std::string &s);
	std::string without_tabs_etc_(std::string &s);


public:
	void	init(void);
	bool	isEmpty(void);
	void	print1(int index);
	void	print2(int index);
};

#endif