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
}
