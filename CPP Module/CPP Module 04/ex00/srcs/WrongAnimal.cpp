#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal Constructor Called" << std::endl;
	type_ = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
	(*this) = obj;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
	std::cout << "WrongAnimal Copy Assigment Operator Called" << std::endl;
	type_ = obj.type_;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type_;
}