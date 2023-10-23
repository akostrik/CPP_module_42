#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

#include "Contact.hpp"

public:
Contact::Contact(char *firstName, char *lastName, char *nickname, char *secret)
{
	: firstName(firstName), lastName(lastName), nickname(nickname), secret(secret)
}

public:
void	print1()
{
	std::cout << right << setw(10) << "|" << c.index
					  << right << setw(10) << "|" << c.firstName
						<< right << setw(10) << "|" << c.lastName
						<< right << setw(10) << "|" << c.nickname << str::endl);
}

public:
void	print2()
{
	std::cout << c.index     << str::endl
					  << c.firstName << str::endl
						<< c.lastName  << str::endl
						<< c.nickname  << str::endl
						<< c.secret    << str::endl;
}
