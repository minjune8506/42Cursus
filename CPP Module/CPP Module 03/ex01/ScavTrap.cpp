#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap " << name_ << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout << "ScavTrap " << name_ << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj) {
	(*this) = obj;
	std::cout << "ScavTrap " << name_ << " created" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) {
	ClapTrap::operator=(obj);
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name_ << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (energyPoints_ > 0 && hitPoints_ > 0) {
		energyPoints_--;
		std::cout << "ScavTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}