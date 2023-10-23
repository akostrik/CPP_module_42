#include "PhoneBook.hpp"

public:
PhoneBook::PhoneBook()
{
	this->index = 0;
}

public:
~PhoneBook()
{
	for (int = 0, i < 8, i++)
		c[i]~;
}

public:
void add(int index)
{
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string secret;

	std::getline(std::cin, firstName, "\n");
	std::getline(std::cin, lastName,  "\n");
	std::getline(std::cin, nickname,  "\n");
	std::getline(std::cin, secret,    "\n");

	if (!firstName || !lastName || !nickname || !secret)
		return (NULL);
  phb.add(new Contact(index++ % 8, firstName, lastName, nickname, secret));
}

public:
Contact    search(PhoneBook phb)
{
	int index;
	int index_max;

	for(int i; i < 8; i++)
		c[i].print1();
	std::cout << "Entre the index> ";
	std::getline(std::cin, index, "\n");
	if (imdex >= 0 && index <= 7)
		std::cout << c[index].print2();
	else
	{
		index_max = 0;
		for (int i = 0; i < 8; i++)
		{
			if (c[i] == NULL)
				break;
			index_max++;
		}
		std::cour << "The index should be enter 0 and " << index_max << std::endl;
	}
}
