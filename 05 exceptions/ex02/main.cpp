#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	std::cout << "\nAlice\n";
	try {
		Bureaucrat b("Alice", 3);
		ShrubberyCreationForm f("home");

		std::cout << b << std::endl;

		std::cout << "The form before being signed : " << f << std::endl;
		b.signForm(&f);
		std::cout << "The form after  being signed : " << f << std::endl;
		b.executeForm(f);
	}

	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
