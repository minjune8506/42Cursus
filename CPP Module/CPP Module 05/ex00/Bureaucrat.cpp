#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("anonymous"), grade_(150) {
	std::cout << "Bureaucrat Constructor Called" << std::endl;
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

std::string Bureaucrat::getName() {
	return name_;
}

int Bureaucrat::getGrade() {
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

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj) {
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return out;
}
