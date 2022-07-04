#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE) {
	std::cout << "Not Used" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: Form("Robotomy", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE), target_(target) {
	std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) 
: Form(obj), target_(obj.target_) {
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	std::cout << "RobotomyRequestForm Copy Assignment Operator Called" << std::endl;
	Form::operator=(obj);
	target_ = obj.target_;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	srand(time(NULL));
	if (canExecute(executor)) {
		std::cout << "Drilling....." << std::endl;
		if (rand() % 2) {
			std::cout << target_ << " has been robotomized successfully 50% of time" << std::endl;
		}
		else {
			std::cout << "Robotomy failed" << std::endl;
		}
		return ;
	}
	if (!getSigned()) {
		throw FormNotSignedException();
	} else {
		throw GradeTooLowException();
	}
}