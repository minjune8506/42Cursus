#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon_ = NULL;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon_ = &weapon;
}

void HumanB::attack() {
	std::cout << this->name << " attacks with their " << weapon_->getType() << std::endl;
}