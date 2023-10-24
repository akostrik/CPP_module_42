#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

#include "Contact.hpp"

Contact::Contact() {}

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
	this->firstName = this->getInput("Enter the first name: ");
	this->lastName  = this->getInput("Enter the last name: ");
	this->nickname  = this->getInput("Enter the nickname: ");
	this->phone     = this->getInput("Enter the phone: ");
	this->secret    = this->getInput("Enter the darkest secret: ");
	std::cout << std::endl;
}

bool    Contact::isEmpty(void) {
    return (this->firstName.compare("") == 0);
}

std::string Contact::shortenedField(std::string str)
{
	std::string ret = "";

	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 8) + '.');
}

void	Contact::print1(int index)
{
	std::cout << std::setw(10) << std::right << index       << "|";
	std::cout << std::setw(10) << std::right << shortenedField(firstName) << "|";
	std::cout << std::setw(10) << std::right << shortenedField(lastName ) << "|";
	std::cout << std::setw(10) << std::right << shortenedField(nickname ) << std::endl;
}

void	Contact::print2(int index)
{
	std::cout << index           << std::endl;
	std::cout << this->firstName << std::endl;
	std::cout << this->lastName  << std::endl;
	std::cout << this->nickname  << std::endl;
	std::cout << this->secret    << std::endl;
}
