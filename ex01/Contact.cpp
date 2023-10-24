#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

#include "Contact.hpp"

Contact::Contact()
{

}

std::string Contact::getInput(std::string str) {
    std::string input = "";
    bool        valid = false;
    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = true;
        else {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    } while (!valid);
    return (input);
}

void    Contact::init(void) {
    std::cin.ignore();
    this->firstName = this->getInput("Please enter you first name: ");
    this->lastName  = this->getInput("Please enter your last name: ");
    this->nickname  = this->getInput("Please enter your nickname: ");
    this->secret    = this->getInput("Please enter your darkest secret: ");
    std::cout << std::endl;
}

void	Contact::print1(int index)
{
	std::cout << std::right << std::setw(10) << "|" << index
		    << std::right << std::setw(10) << "|" << this->firstName
			<< std::right << std::setw(10) << "|" << this->lastName
			<< std::right << std::setw(10) << "|" << this->nickname << std::endl;
}

void	Contact::print2(int index)
{
	std::cout << index     << std::endl;
	std::cout << this->firstName << std::endl;
	std::cout << this->lastName  << std::endl;
	std::cout << this->nickname  << std::endl;
	std::cout << this->secret    << std::endl;
}
