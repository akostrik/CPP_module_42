#include <cctype>
#include <string>
#include <iostream>
#include <cstring>
#include "Contact.h"
#include "PhoneBook.hpp"
#include "Contact.hpp"

enum Cmd { ADD = 1, SEARCH, EXIT };


int	main()
{
    PhoneBook   phb = PhoneBook();
    Cmd cmd;

    while (1)
    {
				std::cout << "Enter a command (ADD / SEARCH / EXIT)> ";
				std::getline(std::cin, str);
        if (cmd == ADD)
            phb.add();
        else if (cmd == SEARCH)
            phb.search();
        else if (cmd == EXIT || std::cin.eof())
            break ;
    }
		std::cout << std::endl;
		phb.PhoneBook~();
    return (0);
}