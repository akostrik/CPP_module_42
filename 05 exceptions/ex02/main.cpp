#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		std::cerr << e.what() << " (catched in main)" << std::endl;
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
		std::cerr << e.what() << " (catched in main)" << std::endl;
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
		std::cerr << e.what() << " (catched in main)" << std::endl;
	}

	try {
		Bureaucrat b("David", 1);
		ShrubberyCreationForm f("home");

		std::cout << std::endl << b << std::endl;
		std::cout << "The form :     " << f << std::endl;
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << " (catched in main)" << std::endl;
	}

	return 0;
}
