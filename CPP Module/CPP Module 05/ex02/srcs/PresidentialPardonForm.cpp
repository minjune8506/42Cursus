#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential", PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXEC_GRADE) {
	std::cout << "Not Used" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("Presidential", PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXEC_GRADE), target_(target) {
	std::cout << "PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) 
: Form(obj), target_(obj.target_) {
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	std::cout << "PresidentialPardonForm Copy Assignment Operator Called" << std::endl;
	Form::operator=(obj);
	target_ = obj.target_;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (canExecute(executor)) {
		std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl; 
		return ;
	}
	if (!getSigned()) {
		throw FormNotSignedException();
	} else {
		throw GradeTooLowException();
	}
}