#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
private:
	int index;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string secret;
};

#endif