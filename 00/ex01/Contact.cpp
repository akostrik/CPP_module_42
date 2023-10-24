#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>

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

void Contact::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

void Contact::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

void Contact::trim(std::string &s)
{
  rtrim(s);
  ltrim(s);
}

void    Contact::init(void) {
	std::cin.ignore();
	this->firstName = this->getInput("Enter the first name: ");
	trim(this->firstName);
	this->lastName  = this->getInput("Enter the last name: ");
	trim(this->lastName);
	this->nickname  = this->getInput("Enter the nickname: ");
	trim(this->nickname);
	this->phone     = this->getInput("Enter the phone: ");
	trim(this->phone);
	this->secret    = this->getInput("Enter the darkest secret: ");
	trim(this->secret);
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
	return (str.substr(0, 9) + '.');
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
