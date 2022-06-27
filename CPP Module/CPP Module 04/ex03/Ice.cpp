#include "Ice.hpp"
#include <iostream>

Ice::Ice() {
	std::cout << "Ice Constructor Called" << std::endl;
	type_ = "ice";
}

Ice::Ice(const Ice &obj) {

}

Ice &Ice::operator=(const Ice &obj) {

}

Ice::~Ice() {

}

AMateria *Ice::clone() const {

}

void Ice::use(ICharacter &target) {
	std::cout << type_ << " shoots an ice bolt at " << target.getName() << std::endl;
}