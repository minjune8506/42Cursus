#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat &operator=(const Bureaucrat &ojb);
	~Bureaucrat();
	std::string	getName() const;
	int			getGrade() const;
	void		increment(int amount);
	void		decrement(int amount);
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char *what() const throw();
	};
private:
	const std::string	name_;
	int					grade_;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);
#endif
