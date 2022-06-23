#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name_(name) {
	weapon_ = NULL;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon_ = &weapon;
}

void HumanB::attack() {
	std::cout << this->name_ << " attacks with their " << weapon_->getType() << std::endl;
}