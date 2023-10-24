#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phone;
	std::string secret;
	std::string shortenedField(std::string str);
	std::string getInput(std::string str);

public:
	Contact();
	void    init(void);
	bool    isEmpty(void);
	void	print1(int index);
	void	print2(int index);
};

#endif