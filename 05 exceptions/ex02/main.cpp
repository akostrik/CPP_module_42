#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	try {
		Bureaucrat b("Alice", 3);
		ShrubberyCreationForm f("home");

		std::cout << b << std::endl;
		std::cout << "The form :     " << f << std::endl;
		b.signForm(&f);
		std::cout << "The form :     " << f << std::endl;
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Bobby", 140);
		ShrubberyCreationForm f("home");

		std::cout << std::endl << b << std::endl;
		std::cout << "The form :     " << f << std::endl;
		b.signForm(&f);
		std::cout << "The form :     " << f << std::endl;
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Carol", 150);
		ShrubberyCreationForm f("home");

		std::cout << std::endl << b << std::endl;
		std::cout << "The form :     " << f << std::endl;
		b.signForm(&f);
		std::cout << "The form :     " << f << std::endl;
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("David", 1);
		ShrubberyCreationForm f("home");

		std::cout << std::endl << b << std::endl;
		std::cout << "The form :     " << f << std::endl;
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Elias", 3);
		RobotomyRequestForm f("President");

		std::cout << std::endl << b << std::endl;
		std::cout << "The form :     " << f << std::endl;
		b.signForm(&f);
		std::cout << "The form :     " << f << std::endl;
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Fredy", 1);
		PresidentialPardonForm f("Predident");

		std::cout << std::endl << b << std::endl;
		std::cout << "The form :     " << f << std::endl;
		b.signForm(&f);
		std::cout << "The form :     " << f << std::endl;
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
