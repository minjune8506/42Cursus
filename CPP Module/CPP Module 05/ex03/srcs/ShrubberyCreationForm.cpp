#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("noName", 1, 1) {
	std::cout << "Not Used" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: Form("Shrubbery", 145, 137), target_(target) {
	std::cout << "ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) 
: Form(obj), target_(obj.target_) {
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	std::cout << "ShrubberyCreationForm Copy Assignment Operator Called" << std::endl;
	Form::operator=(obj);
	target_ = obj.target_;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (canExecute(executor)) {
		std::string shrubbery =	"               ,@@@@@@@,\n"
								"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
								"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
								"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
								"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
								"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
								"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
								"       |o|        | |         | |\n"
								"       |.|        | |         | |\n"
								"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
		std::ofstream ofs;
		ofs.open(target_ + "_shrubbery");
		if (ofs.fail()) {
			return ;
		}
		ofs.write(shrubbery.c_str(), shrubbery.size());
		ofs.close();
		return ;
	}
	if (!getSigned()) {
		throw FormNotSignedException();
	} else {
		throw GradeTooLowException();
	}
}