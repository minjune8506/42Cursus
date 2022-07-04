#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

#define SHRUBBERY_SIGN_GRADE 145
#define SHRUBBERY_EXEC_GRADE 137

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const &executor) const;
	class OpenFailException : public std::exception {
	public:
		const char *what() const throw();
	};
private:
	ShrubberyCreationForm();
	std::string target_;
};

#endif