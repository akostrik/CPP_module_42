#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact c[8];
	int			index;
	int			size_();

public:
	PhoneBook(void);
	void	add(void);
	void	search(void);
};

#endif