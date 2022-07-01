#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &obj) : AMateria(obj) {
}

Ice &Ice::operator=(const Ice &obj) {
	AMateria::operator=(obj);
	type_ = "ice";
	return (*this);
}

Ice::~Ice() {
}

AMateria *Ice::clone() const {
	AMateria *clone = new Ice(*this);
	return clone;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
