#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), name_("noName") {
	ClapTrap::name_ = name_ + "_clap_name";
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 30;
	std::cout << "DiamondTrap " << name_ << " created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name_(name){
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 30;
	std::cout << "DiamondTrap " << name_ << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj) {
	(*this) = obj;
	std::cout << "DiamondTrap " << name_ << " created" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
	ClapTrap::operator=(obj);
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
