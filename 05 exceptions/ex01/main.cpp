// условие 
// evaluation
// каждый операция - а что, если не пройдёт 
// valgrind для ошибок
// INT_MAX, 0, "\0" "" NULL EOF вводимые данные BUFSIZE>0

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat b("Alice", 3);
		AForm f("University Form", 1, 5);

		std::cout << b << std::endl;
		std::cout << "The form (1): " << f << std::endl;
		b.signForm(&f);
		std::cout << "The form (2): " << f << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b1("Bob", 150);
		Bureaucrat b2("Carol", 1);
		AForm f("School Form", 1, 5);

		std::cout << std::endl << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << "The form (1): " << f << std::endl;
		try {
			f.beSigned(b1);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "The form (2): " << f << std::endl;
		f.beSigned(b2);
		std::cout << "The form (3): " << f << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		AForm f("Bad Form", 0, 5);

		std::cout << "The form: " << f << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
