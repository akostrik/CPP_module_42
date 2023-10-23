#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

#include "Contact.hpp"

Contact::Contact(char *firstName, char *lastName, char *nickname, char *secret)
{
	: firstName(firstName), lastName(lastName), nickname(nickname), secret(secret)
}

Contact::~Contact(void)
{
}

public:
std::string	Contact::get(void) const
{
	char *ret;
	std::<< cout << setw(10);
	std::cout << index << "|" << this.firstName << "|" << this.lastName << "|" << this.nickname "|" << this.secret;

	return (ret);
}

