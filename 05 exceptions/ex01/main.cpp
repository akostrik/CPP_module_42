#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "\nAlice\n";
	try {
		Bureaucrat b("Alice", 3);
		Form f("University Form", 1, 5);

		std::cout << b << std::endl;
		b.incrGrade();
		b.incrGrade();
		std::cout << b << std::endl;

		std::cout << "The form before being signed : " << f << std::endl;
		b.signForm(&f);
		std::cout << "The form after  being signed : " << f << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nBob and Carol sign a form\n";
	try {
		Bureaucrat b1("Bob", 150);
		Bureaucrat b2("Carol", 1);
		Form f("42 School Form", 1, 5);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << "The form before being signed :                    " << f << std::endl;
		try {
			f.beSigned(b1);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "The form after  being signed by " << b1 << ": " << f << std::endl;
		try {
			f.beSigned(b2);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "The form after  being signed by " << b2 << ": " << f << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
