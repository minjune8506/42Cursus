#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(const Brain &obj) {
	std::cout << "Brain Copy Constructor Called" << std::endl;
	(*this) = obj;
}

Brain &Brain::operator=(const Brain &obj) {
	std::cout << "Brain Copy Assignment Operator Called" << std::endl;
	for (int i = 0 ; i < 100 ; i++) {
		ideas_[i] = obj.ideas_[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain Destructor Called" << std::endl;
}