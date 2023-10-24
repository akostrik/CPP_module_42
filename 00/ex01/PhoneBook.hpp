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
	int			index;
	Contact c[8];
	int			size_();

public:
	PhoneBook(void);
	void	add(void);
	void	search(void);
};

#endif