#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", 1, 1) {
	std::cout << "Not Used" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: Form("Robotomy", 72, 45), target_(target) {
	std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) 
: Form(obj), target_(obj.target_) {
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	std::cout << "RobotomyRequestForm Copt Assignment Operator Called" << std::endl;
	Form::operator=(obj);
	target_ = obj.target_;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (getSigned() && executor.getGrade() <= getExecuteGrade()) {
		std::cout << "Drilling....." << std::endl;
		std::cout << target_ << "has been robotomized successfully 50% of time";
		return ;
	}
	std::cout << "Robotomy failed" << std::endl;
	if (!getSigned()) {
		throw FormNotSignedException();
	} else {
		throw GradeTooLowException();
	}
}