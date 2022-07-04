#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try {
		Form test1("test1Form", 10, 10);
		std::cout << test1 << std::endl;
		Form test2("test2Form", -1, 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form test1("testForm", 10, 10);
		Bureaucrat a("t1", 5);
		Bureaucrat b("t2", 100);
		test1.beSigned(a);
		test1.beSigned(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form test1("testForm", 10, 10);
		Bureaucrat a("t1", 5);
		Bureaucrat b("t2", 100);
		a.signForm(test1);
		b.signForm(test1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}