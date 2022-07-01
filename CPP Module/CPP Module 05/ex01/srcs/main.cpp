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
		Form test3("test3Form", 10, 10);
		Bureaucrat a("test3", 5);
		Bureaucrat b("test3", 100);
		test3.beSigned(a);
		test3.beSigned(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}