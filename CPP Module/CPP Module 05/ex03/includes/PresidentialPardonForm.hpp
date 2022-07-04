#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
	~PresidentialPardonForm();
	void execute(Bureaucrat const &executor) const;
private:
	std::string target_;
};

#endif