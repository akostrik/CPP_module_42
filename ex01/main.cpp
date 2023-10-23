#include <cctype>
#include <string>
#include <iostream>
#include <cstring>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
    PhoneBook	phb = new PhoneBook();
    Cmd				cmd;

		index = 0;
    while (1)
    {
				std::cout << "Enter a command (ADD / SEARCH / EXIT)> ";
				std::getline(std::cin, cmd, "\n");
        if (cmd == "ADD")
            phb.add(index++ % 8);
        else if (cmd == "SEARCH")
            phb.search();
        else if (cmd == "EXIT" || std::cin.eof())
            break ;
    }
		phb.~PhoneBook();
    return (0);
}