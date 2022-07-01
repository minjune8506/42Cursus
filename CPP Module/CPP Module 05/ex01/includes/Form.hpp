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
	void		beSigned(Bureaucrat &obj);
	std::string	getName() const;
	bool		getSigned() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
private:
	Form();
	const std::string	name_;
	const int			signGrade_;
	const int			executeGrade_;
	bool				signed_;
};

std::ostream &operator<<(std::ostream &out, Form &obj);

#endif