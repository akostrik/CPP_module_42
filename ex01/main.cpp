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

    do {
        std::cout << "Enter a command (ADD / SEARCH / EXIT)> ";
        std::cin >> input;
        std::cout << "input = " << input << std::endl;
        std::cout << "input.compare(SEARCH) = " << input.compare("SEARCH") << std::endl;
        if (input.compare("ADD") == 0)
            phb->add();
        else if (input.compare("SEARCH") == 0) {
            phb->search();
        }
        else if (input.compare("EXIT") == 0)
        {

        }
        std::cout << std::flush;
    } while (1);  // && !std::cin.eof()
	// phb.~PhoneBook();
    return (0);
}