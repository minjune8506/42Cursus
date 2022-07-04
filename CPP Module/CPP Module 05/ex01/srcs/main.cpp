#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void) {
	try {
		std::cout << "==========test1==========" << std::endl;
		Form test("successForm", 10, 10); // Success
		std::cout << test << std::endl; // Output operation overloading
		Form test2("failForm", -1, 151); // Fail
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl; // GradeTooHighException
	}

	try {
		std::cout << "==========test2==========" << std::endl;
		Form test("successForm", 10, 10); // Success
		std::cout << test << std::endl;
		Bureaucrat a("t1", 5); // Grade : 5
		Bureaucrat b("t2", 100); // Grade : 100
		test.beSigned(a); // Success
		b.signForm(test); // Fail -> Message
		test.beSigned(b); // Fail -> Exception (GradeTooLowException)
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl; // GradeTooLowException
	}

	try {
		std::cout << "==========test3==========" << std::endl;
		Form test("successForm", 10, 10); // Success
		Bureaucrat a("t1", 5); // Grade : 5
		Bureaucrat b("t2", 100); // Grade : 100
		a.signForm(test); // Success
		b.signForm(test); // Fail -> Error Message
	} catch (std::exception &e) { // Skip
		std::cout << e.what() << std::endl;
	}
	return (0);
}