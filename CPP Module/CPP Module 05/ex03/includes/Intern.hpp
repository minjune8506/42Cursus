#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &obj);
	Intern &operator=(const Intern &obj);
	~Intern();
	Form *makeForm(std::string name, std::string target);
	Form *createPresidential(std::string target);
	Form *createRobotomy(std::string target);
	Form *createShrubbery(std::string target);
};

#endif