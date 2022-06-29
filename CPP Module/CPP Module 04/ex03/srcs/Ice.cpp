#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Constructor Called" << std::endl;
}

Ice::Ice(const Ice &obj) : AMateria(obj) {
	std::cout << "Ice Copy Constructor Called" << std::endl;
}

Ice &Ice::operator=(const Ice &obj) {
	AMateria::operator=(obj);
	type_ = "ice";
	std::cout << "Ice Copy Assignment Constructor Called" << std::endl;
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
