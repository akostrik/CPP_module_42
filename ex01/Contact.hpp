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
	std::string secret;
	std::string getInput(std::string str);

public:
	Contact();
	Contact(char *firstName, char *lastName, char *nickname, char *secret);
	void    init(void);
	void	print1(int index);
	void	print2(int index);
};

#endif