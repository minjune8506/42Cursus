#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <string>

#define ROBOTOMY_SIGN_GRADE 72
#define ROBOTOMY_EXEC_GRADE 45

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
	~RobotomyRequestForm();
	void execute(Bureaucrat const &executor) const;
private:
	RobotomyRequestForm();
	std::string target_;
};

#endif