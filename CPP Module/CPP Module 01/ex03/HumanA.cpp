#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : weapon_(weapon) {
	this->name = name;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon_.getType() << std::endl;
}