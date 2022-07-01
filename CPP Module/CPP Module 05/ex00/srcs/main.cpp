#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat a("test1", 10);
		Bureaucrat b("test2", -1); // Exception
		std::cout << "Next Line" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat c("test3", 20);
		std::cout << c << std::endl;
		c.increment(10);
		c.decrement(150); // Exception
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
