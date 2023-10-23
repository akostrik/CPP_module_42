#include "Contact.h"

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
private:
	Contact cnt[8];

public:
	Phonebook(void);
	~Phonebook(void);
	void	add(void);
	void	search(void);
}

#endif