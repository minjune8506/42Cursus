#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() {
	std::cout << "AMateria Constructor Called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type_(type) {
	std::cout << "AMateria Constructor Called" << std::endl;
}

AMateria::AMateria(const AMateria &obj) {
	std::cout << "AMateria Copy Constructor Called" << std::endl;
	(*this) = obj;
}

AMateria &AMateria::operator=(const AMateria &obj) {
	std::cout << "AMateria Copy Assignment Operator Called" << std::endl;
	type_ = obj.type_;
	return (*this);
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor Called" << std::endl;
}

std::string const &AMateria::getType() const {
	return type_;
}

void AMateria::use(ICharacter &target) {
	std::cout << "AMateria " << target.getName() << std::endl;
}
