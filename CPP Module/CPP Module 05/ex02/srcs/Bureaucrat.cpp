#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("anonymous"), grade_(150) {
	std::cout << "Not Used Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
	std::cout << "Bureaucrat Constructor Called" << std::endl;
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150) {
		throw Bureaucrat::GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name_(obj.name_), grade_(obj.grade_) {
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
	std::cout << "Bureaucrat Copy Assignment Operator Called" << std::endl;
	grade_ = obj.grade_;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor Called" << std::endl;
}

std::string Bureaucrat::getName() const {
	return name_;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::increment(int amount) {
	grade_ -= amount;
	if (grade_ < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::decrement(int amount) {
	grade_ += amount;
	if (grade_ > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::signForm(Form &obj) {
	if (grade_ <= obj.getSignGrade()) {
		std::cout << name_ << " signed " << obj.getName() << std::endl;
		return ;
	}
	std::cout << name_ << " couldn't sign " << obj.getName() << " because grade is too low" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

void Bureaucrat::executeForm(Form const &form) {
	try {
		form.execute(*this);
		std::cout << name_ << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		e.what();
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj) {
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}
