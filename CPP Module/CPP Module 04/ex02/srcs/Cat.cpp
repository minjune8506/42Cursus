#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain_(new Brain()) {
	std::cout << "Cat Constructor Called" << std::endl;
	type_ = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj), brain_(new Brain(*obj.brain_)) {
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj) {
	Animal::operator=(obj);
	*brain_ = *obj.brain_;
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat Destructor Called" << std::endl;
	delete brain_;
}

void Cat::makeSound() const {
	std::cout << "Meow..." << std::endl;
}