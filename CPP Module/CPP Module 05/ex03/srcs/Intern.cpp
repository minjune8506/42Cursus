#include "Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern() {
	std::cout << "Intern Consturtor Called" << std::endl;
}

Intern::Intern(const Intern &obj) {
	std::cout << "Intern Copy Constructor Called" << std::endl;
	*this = obj;
}

Intern &Intern::operator=(const Intern &obj) {
	std::cout << "Intern Copy Assignment Operator Called" << std::endl;
	(void)obj;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern Destructor Called" << std::endl;
}

Form *Intern::createPresidential(std::string target) {
	std::cout << "Intern creates presidential pardon form" << std::endl;
	Form *temp = new PresidentialPardonForm(target);
	return temp;
}

Form *Intern::createRobotomy(std::string target) {
	std::cout << "Intern creates robotomy request form" << std::endl;
	Form *temp = new RobotomyRequestForm(target);
	return temp;
}

Form *Intern::createShrubbery(std::string target) {
	std::cout << "Intern creates shrubbery creation form" << std::endl;
	Form *temp = new ShrubberyCreationForm(target);
	return temp;
}

Form *Intern::makeForm(std::string name, std::string target) {
	std::string form_name[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	Form *(Intern::*func[3])(std::string) = {&Intern::createPresidential, &Intern::createRobotomy, &Intern::createShrubbery};	
	for (int i = 0 ; i < 3 ; i++) {
		if (form_name[i] == name) {
			return (this->*func[i])(target);
		}
	}
	std::cout << "name does not match any Form" << std::endl;
	return (NULL);
}