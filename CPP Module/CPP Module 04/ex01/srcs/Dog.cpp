#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), brain_(new Brain()) {
	std::cout << "Dog Constructor Called" << std::endl;
	type_ = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj), brain_(new Brain(*obj.brain_)){
	std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj) {
	Animal::operator=(obj);
	*brain_ = *obj.brain_;
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog Destructor Called" << std::endl;
	delete brain_;
}

void Dog::makeSound() const {
	std::cout << "Bark..." << std::endl;
}