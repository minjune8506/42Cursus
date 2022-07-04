#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

Form *Intern::makeForm(std::string name, std::string target) {
	std::string form_name[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i;
	for (i = 0 ; i < 3 ; i++) {
		if (form_name[i] == name) {
			break ;
		}
	}
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << form_name[i] << "form" << std::endl;
		return new PresidentialPardonForm(target);
	case 1:
		std::cout << "Intern creates " << form_name[i] << "form" << std::endl;
		return new RobotomyRequestForm(target);
	case 2:
		std::cout << "Intern creates " << form_name[i] << "form" << std::endl;
		return new ShrubberyCreationForm(target);
	default:
		std::cout << "name does not match any Form" << std::endl;
	}
	return (NULL);
}