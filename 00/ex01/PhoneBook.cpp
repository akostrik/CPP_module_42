#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
};

void PhoneBook::add()
{
  Contact new_c;

  new_c.init();
  this->c[this->index] = new_c;
  this->index = (this->index + 1) % 8;
};

int PhoneBook::size_()
{
	int size;

	for(size = 0; size < 8; size++)
		if (this->c[size].isEmpty() == 1)
			break ;
	return (size);
}

void PhoneBook::search()
{
	int		size  = PhoneBook::size_();
	int		input = -1;
	bool	valid = false;

	if (size == 0)
	{
		std::cout << "The phonebook is empty" << std::endl;
		return ;
	}

	for(int i = 0; i < size; i++)
		this->c[i].print1(i);

	do
	{
		std::cin.ignore();
		std::cout << "Enter the contact index (between 0 and " << size- 1 << "): " << std::flush;
		std::cin >> input;
		if (std::cin.good() && input >= 0 && input <= size - 1)
			valid = true;
		else {
			std::cin.clear();
			std::cout << "Invalid index; please re-enter." << std::endl;
		}
	} while (!valid);
	this->c[input].print2(input);
};
