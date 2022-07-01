#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat Constructor Called" << std::endl;
	type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj) {
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
	(*this) = obj;
}

WrongCat &WrongCat::operator=(const WrongCat &obj) {
	WrongAnimal::operator=(obj);
	std::cout << "WrongCat Copy Assignment Operator Called" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "Meow..." << std::endl;
}