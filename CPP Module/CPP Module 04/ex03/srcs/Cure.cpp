#include "Cure.hpp"
#include <iostream>

Cure::Cure() {
	std::cout << "Cure Constructor Called" << std::endl;
	type_ = "cure";
}

Cure::Cure(const Cure &obj) {
	std::cout << "Cure Copy Constructor Called" << std::endl;
	type_ = obj.type_;
}

Cure &Cure::operator=(const Cure &obj) {
	std::cout << "Cure Copy Assignment Constructor Called" << std::endl;
	type_ = obj.type_;
	return (*this);
}

Cure::~Cure() {
	std::cout << "Cure Destructor Called" << std::endl;
}

AMateria *Cure::clone() const {
	AMateria *clone = new Cure(*this);
	return clone;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s  wounds *" << std::endl;
}
