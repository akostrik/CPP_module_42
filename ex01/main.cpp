#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
  std::string input = "";
  PhoneBook	*phb = new PhoneBook();

	do
	{
		std::cout << "Enter a command (ADD / SEARCH / EXIT)> ";
		std::cin.clear();
		std::cin >> input;
    if (!std::cin.good() || input.empty())
			continue ;
		if (input.compare("ADD") == 0)
			phb->add();
		else if (input.compare("SEARCH") == 0)
			phb->search();
		else if (input.compare("EXIT") == 0) // || std::cin.eof()
			break ;
    std::cout << std::flush;
  } while (1);
	delete phb;
	return (0);
}