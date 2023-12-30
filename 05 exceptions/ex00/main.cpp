#include "Bureaucrat.hpp"

int main() {
	std::cout << "\nAlice, 3\n";
	try {
		Bureaucrat b("Alice", 3);
		b.decrGrade();
		std::cout << b << std::endl;
		b.decrGrade();
		b.decrGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nBob, 1\n";
	try {
		Bureaucrat b("Bob", 1);
		b.decrGrade();
		b.incrGrade();
		b.incrGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nCarol, -11\n";
	try {
		Bureaucrat b("Carol", -3);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nDavid, 151\n";
	try {
		Bureaucrat b("David", 151);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
