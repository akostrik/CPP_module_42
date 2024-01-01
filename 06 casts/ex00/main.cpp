// the type conversion must be solved using one specific type of casting
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b("Alice", 3);
		std::cout << b << std::endl;
		b.decrGrade();
		std::cout << b << std::endl;
		b.decrGrade();
		std::cout << b << std::endl;
		b.decrGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Bob", 1);
		std::cout << std::endl << b << std::endl;
		b.decrGrade();
		std::cout << b << std::endl;
		b.incrGrade();
		std::cout << b << std::endl;
		b.incrGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\ntry Carol, 0\n";
	try {
		Bureaucrat b("Carol", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\ntry David, 151\n";
	try {
		Bureaucrat b("David", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b1("Elias", 7);
		Bureaucrat b2(b1);
		Bureaucrat b3 = b1;

		std::cout << std::endl << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		b1.incrGrade();
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
