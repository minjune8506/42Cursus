#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Constructor Called" << std::endl;
}

Cure::Cure(const Cure &obj) : AMateria(obj) {
	std::cout << "Cure Copy Constructor Called" << std::endl;
}

Cure &Cure::operator=(const Cure &obj) {
	AMateria::operator=(obj);
	type_ = "cure";
	std::cout << "Cure Copy Assignment Constructor Called" << std::endl;
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
