#include "Bureaucrat.hpp"

int main() {
	std::cout << "TEST------------" << std::endl;
	Bureaucrat b("BuroTest", 1);
	std::cout << b << std::endl;
	b.decGrade();
	std::cout << b << std::endl;
	b.incGrade();
	std::cout << b << std::endl;
	std::cout << "----------------" << std::endl;

	try {
		Bureaucrat b("Buro1", 1);
	}
	catch (Bureaucrat::GradeTooHighException &ex) {
		std::cerr << "1:(GradeTooHighException) " << ex.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &ex) {
		std::cerr << "1:(GradeTooLowException) " << ex.what() << std::endl;
	} 
	catch (std::exception &exception) {
		std::cerr << "1: " << exception.what() << std::endl;
	}

	try {
		Bureaucrat b("Buro2", -11);
	}
	catch (Bureaucrat::GradeTooHighException &ex) {
		std::cerr << "2:(GradeTooHighException) " << ex.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &ex) {
		std::cerr << "2:(GradeTooLowException) " << ex.what() << std::endl;
	}
	catch (std::exception &exception) {
		std::cerr << "2: " << exception.what() << std::endl;
	}

	try {
		Bureaucrat b("Buro3", 153);
	}
	catch (Bureaucrat::GradeTooHighException &ex) {
		std::cerr << "3:(GradeTooHighException) " << ex.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &ex) {
		std::cerr << "3:(GradeTooLowException) " << ex.what() << std::endl;
	}
	catch (std::exception &exception) {
		std::cerr << "3: " << exception.what() << std::endl;
	}

	try {
		Bureaucrat b("Buro4", 149);
		b.decGrade();
		std::cout << "dec2" << std::endl;
		b.incGrade();
		b.incGrade();
		b.incGrade();
	}
	catch (Bureaucrat::GradeTooHighException &ex) {
		std::cerr << "4:(GradeTooHighException) " << ex.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &ex) {
		std::cerr << "4:(GradeTooLowException) " << ex.what() << std::endl;
	}
	catch (std::exception &exception) {
		std::cerr << "4: " << exception.what() << std::endl;
	}

	try {
		Bureaucrat b("Buro5", 2);
		b.decGrade();
		std::cout << "inc2" << std::endl;
		b.decGrade();
		b.decGrade();
	}
	catch (Bureaucrat::GradeTooHighException &ex) {
		std::cerr << "5:(GradeTooHighException) " << ex.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &ex) {
		std::cerr << "5:(GradeTooLowException) " << ex.what() << std::endl;
	}
	catch (std::exception &exception) {
		std::cerr << "5: " << exception.what() << std::endl;
	}

	Bureaucrat *b2;
	try {
		b2 	= new Bureaucrat("Buro 6", 0);
	}
	catch (Bureaucrat::GradeTooHighException &ex) {
		std::cerr << "6:(GradeTooHighException) " << ex.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &ex) {
		std::cerr << "6:(GradeTooLowException) " << ex.what() << std::endl;
	}
	catch (std::exception &exception) {
		std::cerr << "6: " << exception.what() << std::endl;
		delete b2;
	}

  std::cout << std::endl << "end:" << std::endl;
  return 0;
}
