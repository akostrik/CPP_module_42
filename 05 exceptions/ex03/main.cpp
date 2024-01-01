#include "Bureaucrat.hpp"
#include "Intern.hpp"
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

	try {
		Bureaucrat b("Eliot", 3);
		ShrubberyCreationForm f1("home");
		ShrubberyCreationForm f2(f1);
		ShrubberyCreationForm f3 = f1;

		std::cout << std::endl << b << std::endl;
		std::cout << "The form :     " << f1 << std::endl;
		std::cout << "The form :     " << f2 << std::endl;
		std::cout << "The form :     " << f3 << std::endl;
		b.signForm(&f1);
		b.signForm(&f2);
		b.signForm(&f3);
		std::cout << "The form :     " << f1 << std::endl;
		std::cout << "The form :     " << f2 << std::endl;
		std::cout << "The form :     " << f3 << std::endl;
		b.executeForm(f1);
		b.executeForm(f2);
		b.executeForm(f3);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << " (catched in main)" << std::endl;
	}

	try {
		Bureaucrat b("Fedia", 3);
		RobotomyRequestForm f("President");

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
		Bureaucrat b("Gregy", 1);
		PresidentialPardonForm f("Predident");

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
		Bureaucrat b("Henry", 1);
		std::cout << std::endl << b << std::endl;
		Intern i = Intern();
		std::cout << "Intern :       " << i << std::endl;
		AForm *f = (i.makeForm("PresidentialPardonForm", "Predident"));

		std::cout << "The form :     " << *f << std::endl;
		b.signForm(f);
		std::cout << "The form :     " << *f << std::endl;
		b.executeForm(*f);
		delete f;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << " (catched in main)" << std::endl;
	}

	try {
		Intern i = Intern();
		std::cout << std::endl << "Intern :       " << i << std::endl;
		AForm *f = (i.makeForm("NonExisting", "Predident"));

		std::cout << "The form :     " << *f << std::endl;
		delete f;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << " (catched in main)" << std::endl;
	}
	return 0;
}
