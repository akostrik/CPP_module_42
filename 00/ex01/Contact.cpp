#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>

#include "Contact.hpp"

std::string Contact::getInput(std::string str) {
    std::string input = "";
    std::string trimmed;
	std::string without_tabs_etc;

    bool        valid = false;
    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
		{
			without_tabs_etc = without_tabs_etc_(input);
			trimmed = trimmed_(without_tabs_etc);
		}
        if (std::cin.good() && !trimmed.empty())
            valid = true;
        else {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    } while (!valid);
    return (trimmed);
}

std::string Contact::without_tabs_etc_(std::string &s)
{
    size_t i;

    while ((i = s.find('\t')) != std::string::npos)
        s.replace(i, 1," ");
    while ((i = s.find('\r')) != std::string::npos)
        s.replace(i, 1," ");
	return (s);
}

std::string Contact::trimmed_(std::string &s)
{
	int	beg;
	int	end;

	for (beg = 0; s[beg] == ' '; beg++)
		;
	if (beg == (int)s.length() - 1 && s[beg] == ' ')
		return "";
	for (end = s.length() - 1; s[end] == ' ' && end >= 0; end--)
		;
	return (s.substr(beg, end - beg + 1));
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

std::string Contact::shortened(std::string &s)
{
	if (s.length() <= 10)
		return (s);
	return (s.substr(0, 9) + ".");
}

void	Contact::print1(int index)
{
	std::cout << std::setw(10) << std::right << index                << "|";
	std::cout << std::setw(10) << std::right << shortened(firstName) << "|";
	std::cout << std::setw(10) << std::right << shortened(lastName ) << "|";
	std::cout << std::setw(10) << std::right << shortened(nickname ) << std::endl;
}

void	Contact::print2(int index)
{
	std::cout << index           << std::endl;
	std::cout << this->firstName << std::endl;
	std::cout << this->lastName  << std::endl;
	std::cout << this->nickname  << std::endl;
	std::cout << this->phone     << std::endl;
	std::cout << this->secret    << std::endl;
}
