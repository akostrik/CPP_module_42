#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
};

// PhoneBook::~PhoneBook(void)
// {
// 	for (int i = 0; i < 8; i++)
// 		this->c[i]~;
// }

void PhoneBook::add()
{
  Contact new_c;

  new_c.init();
  this->c[this->index] = new_c;
  this->index = (this->index + 1) % 8;
};

void PhoneBook::search()
{
	int     input = -1;
	int     size  = 0; //
    bool    valid = false;

    std::cout << "func search"<< std::endl;

  for(size = 0; size < 8; size++)
    {
        if ((*this).c[size].isEmpty() == 1)
        break ;
    }
  for(int i = 0; i < size; i++)
    this->c[i].print1(i);


    // do
    // {
    //     std::cout << "Please enter the contact index (betzeen 0 and " << index_max << "): " << std::flush;
    //     std::cin >> input;
    //     if (std::cin.good() && (input >= 0 && input <= index_max)) {
    //         valid = true;
    //     } else {
    //         std::cin.clear();
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    //         std::cout << "Invalid index; please re-enter." << std::endl;
    //     }
	// 	this->c[i].print2(i);
    // } while (!valid);
};
