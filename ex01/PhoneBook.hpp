#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
private:
	int		index;
	Contact c[8];

public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add(void);
	void	search(void);
};

#endif