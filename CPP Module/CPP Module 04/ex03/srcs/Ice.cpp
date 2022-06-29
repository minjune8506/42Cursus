#include "Ice.hpp"
#include <iostream>

Ice::Ice() {
	std::cout << "Ice Constructor Called" << std::endl;
	type_ = "ice";
}

Ice::Ice(const Ice &obj) {
	std::cout << "Ice Copy Constructor Called" << std::endl;
	type_ = obj.type_;
}

Ice &Ice::operator=(const Ice &obj) {
	std::cout << "Ice Copy Assignment Constructor Called" << std::endl;
	type_ = obj.type_;
	return (*this);
}

Ice::~Ice() {
	std::cout << "Ice Destructor Called" << std::endl;
}

AMateria *Ice::clone() const {
	AMateria *clone = new Ice(*this);
	return clone;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
