#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	{
		std::cout << "==========test1==========" << std::endl;
		Intern  someRandomIntern;
    	Form	*rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		delete rrf;
	}
	{
		std::cout << "==========test2==========" << std::endl;
		Intern  someRandomIntern;
    	Form	*rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	{
		std::cout << "==========test3==========" << std::endl;
		Intern  someRandomIntern;
    	Form	*rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		delete rrf;
	}
	{
		std::cout << "==========test4==========" << std::endl;
		Intern  someRandomIntern;
    	Form	*rrf;
		rrf = someRandomIntern.makeForm("undefined", "Bender");
		delete rrf;
	}
	return (0);
}