#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

#include "Contact.hpp"

Contact::Contact(char *firstName, char *lastName, char *nickname)
{
	: firstName(firstName), lastName(lastName), nickname(nickname)
}

Contact::~Contact(void)
{
}

std::string	Contact::get_fname(void) const
{
	char *ret;
	std::<< cout << setw(10);
	std::cout << index << "|" << this.firstName << "|" << this.lastName << "|" << this.nickname;

	return (ret);
}

void	Contact::set_fname(std::string str)
{
	this->_fname = str;
}
