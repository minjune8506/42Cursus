#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential", 1, 1) {
	std::cout << "Not Used" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("Presidential", 25, 5), target_(target) {
	std::cout << "PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) 
: Form(obj), target_(obj.target_) {
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Destructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (getSigned() && getExecuteGrade() >= executor.getGrade()) {
		std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl; 
		return ;
	}
	if (!getSigned()) {
		throw FormNotSignedException();
	} else {
		throw GradeTooLowException();
	}
}