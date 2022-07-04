#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat t1("t1", 1);
	Bureaucrat t2("t2", 150);
	Form *f;
	try {
		std::cout << "==========test1==========" << std::endl;
		f = new PresidentialPardonForm("presidential");
		f->execute(t1);
	} catch (std::exception &e) { // not Signed
		delete f;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "==========test2==========" << std::endl;
		f = new PresidentialPardonForm("presidential"); // Presidential
		f->beSigned(t1);
		f->execute(t1); // Success
		delete f;
	} catch (std::exception &e) { 
		delete f;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "==========test3==========" << std::endl;
		f = new ShrubberyCreationForm("Shrubbery"); // Shrubbery
		f->beSigned(t1);
		f->execute(t1); // Success
		delete f;
	} catch (std::exception &e) {
		delete f;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "==========test4==========" << std::endl;
		f = new RobotomyRequestForm("Robotomy");
		f->beSigned(t1);
		f->execute(t1); // Success
		f->execute(t2); // Fail
		delete f;
	} catch (std::exception &e) {
		delete f;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "==========test5==========" << std::endl;
		RobotomyRequestForm a("t3");
		t1.signForm(a);
		t1.executeForm(a);
		t2.executeForm(a);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}