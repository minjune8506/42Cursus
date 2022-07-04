#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
	~RobotomyRequestForm();
	void execute(Bureaucrat const &executor) const;
private:
	std::string target_;
};

#endif