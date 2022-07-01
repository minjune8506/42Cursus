#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() {
}

AMateria::AMateria(std::string const &type) : type_(type) {
}

AMateria::AMateria(const AMateria &obj) {
	(*this) = obj;
}

AMateria &AMateria::operator=(const AMateria &obj) {
	type_ = obj.type_;
	return (*this);
}

AMateria::~AMateria() {
}

std::string const &AMateria::getType() const {
	return type_;
}

void AMateria::use(ICharacter &target) {
	std::cout << "AMateria " << target.getName() << std::endl;
}
