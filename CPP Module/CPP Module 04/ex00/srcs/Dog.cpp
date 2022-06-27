#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Dog Constructor Called" << std::endl;
	type_ = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj) {
	std::cout << "Dog Copy Constructor Called" << std::endl;
	(*this) = obj;
}

Dog &Dog::operator=(const Dog &obj) {
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	Animal::operator=(obj);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Bark..." << std::endl;
}