#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	std::cout << "Cat Constructor Called" << std::endl;
	type_ = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj) {
	std::cout << "Cat Copy Constructor Called" << std::endl;
	(*this) = obj;
}

Cat &Cat::operator=(const Cat &obj) {
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	Animal::operator=(obj);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow..." << std::endl;
}