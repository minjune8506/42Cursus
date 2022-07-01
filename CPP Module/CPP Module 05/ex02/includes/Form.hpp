#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form &obj);
	Form &operator=(const Form &obj);
	~Form();
	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(Bureaucrat &obj);
	virtual void execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
	class FormNotSignedException : public std::exception {
		const char *what() const throw();
	};
private:
	Form();
	const std::string name_;
	bool signed_;
	const int signGrade_;
	const int executeGrade_;
};

std::ostream &operator<<(std::ostream &out, Form &obj);

#endif