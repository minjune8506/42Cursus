#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal::Animal(const Animal &obj) {
	std::cout << "Animal Copy Constructor Called" << std::endl;
	(*this) = obj;
}

Animal &Animal::operator=(const Animal &obj) {
	std::cout << "Animal Copy Assigment Operator Called" << std::endl;
	type_ = obj.type_;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal Destructor Called" << std::endl;
}

std::string Animal::getType() const {
	return type_;
}