#include "Zombie.hpp"
#include <iostream>
#include <string>

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << name << "deleted" << std::endl;
}