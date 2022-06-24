#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(), name_("noName") {
	std::cout << "DiamondTrap " << name_ << " created" << std::endl;
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 30;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name), name_(name){
	std::cout << "DiamondTrap " << name_ << " created" << std::endl;
	ClapTrap::name_ = name + "_clap_name";
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : FragTrap(obj), ScavTrap(obj) {
	(*this) = obj;
	std::cout << "DiamondTrap " << name_ << " created" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
	FragTrap::operator=(obj);
	ScavTrap::operator=(obj);
	name_ = obj.name_;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name_ << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << name_ << std::endl;
	std::cout << ClapTrap::name_ << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}