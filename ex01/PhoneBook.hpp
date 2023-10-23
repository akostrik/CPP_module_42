#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
public:
static int		index;

private:
	Contact cnt[8];

public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add(void);
	void	search(void);
};

#endif