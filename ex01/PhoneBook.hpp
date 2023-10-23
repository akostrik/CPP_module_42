#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
public:
static std::int		index = 0;

private:
	Contact cnt[8];

public:
	Phonebook(void);
	~(void);
	void	add(void);
	void	search(void);
};

#endif