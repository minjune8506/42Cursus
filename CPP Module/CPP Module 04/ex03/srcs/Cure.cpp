#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure &obj) : AMateria(obj) {
}

Cure &Cure::operator=(const Cure &obj) {
	AMateria::operator=(obj);
	type_ = "cure";
	return (*this);
}

Cure::~Cure() {
}

AMateria *Cure::clone() const {
	AMateria *clone = new Cure(*this);
	return clone;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s  wounds *" << std::endl;
}
