#include "Form.hpp"

Form::Form() : signed_(false), signGrade_(1), executeGrade_(1) {
	std::cout << "Not Used Constructor" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : name_(name), signed_(false), signGrade_(signGrade), executeGrade_(executeGrade) {
	std::cout << "Form Constructor Called" << std::endl;
	if (signGrade_ < 1 || executeGrade_ < 1) {
		throw GradeTooHighException();
	}
	if (signGrade_ > 150 || executeGrade_ > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form &obj) : name_(obj.name_), signed_(obj.signed_), signGrade_(obj.signGrade_), executeGrade_(obj.executeGrade_) {
	std::cout << "Form Copy Constructor Called" << std::endl;
}

Form &Form::operator=(const Form &obj) {
	std::cout << "Form Copy Assignment Operator Called" << std::endl;
	signed_ = obj.signed_;
	return (*this);
}

Form::~Form() {
	std::cout << "Form Destructor Called" << std::endl;
}

std::string Form::getName() const {
	return name_;
}

bool Form::getSigned() const {
	return signed_;
}

int Form::getSignGrade() const {
	return signGrade_;
}

int Form::getExecuteGrade() const {
	return executeGrade_;
}

void Form::beSigned(Bureaucrat &obj) {
	obj.signForm(*this);
	if (obj.getGrade() > signGrade_) {
		throw GradeTooLowException();
	}
	signed_ = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char *Form::FormNotSignedException::what() const throw() {
	return "Form is not Signed";
}

std::ostream &operator<<(std::ostream &out, Form &obj) {
	std::cout << "-------Form-------\n"
	<< "name : " << obj.getName() << '\n'
	<< "signGrade : " << obj.getSignGrade() << '\n'
	<< "executeGrade : " << obj.getExecuteGrade() << '\n'
	<< "signed : " << (obj.getSigned() ? "O" : "X") << '\n'
	<< "------------------";
	return out;
}