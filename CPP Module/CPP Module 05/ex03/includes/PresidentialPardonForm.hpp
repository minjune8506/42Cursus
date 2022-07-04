#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

#define PRESIDENTIAL_SIGN_GRADE 25
#define PRESIDENTIAL_EXEC_GRADE 5

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
	~PresidentialPardonForm();
	void execute(Bureaucrat const &executor) const;
private:
	PresidentialPardonForm();
	std::string target_;
};

#endif