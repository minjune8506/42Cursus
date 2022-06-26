#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name_("noName"), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
	std::cout << name_ << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
	std::cout << name_ << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
	(*this) = obj;
	std::cout << name_ << " created" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
	name_ = obj.name_;
	hitPoints_ = obj.hitPoints_;
	energyPoints_ = obj.energyPoints_;
	attackDamage_ = obj.attackDamage_;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << name_ << " destroyed" << std::endl;
}

void ClapTrap::setAttackDamage(int attackDamage) {
	attackDamage_ = attackDamage;
}

int ClapTrap::getAttackDamage() {
	return attackDamage_;
}

void ClapTrap::attack(const std::string &target) {
	if (energyPoints_ > 0 && hitPoints_ > 0) {
		energyPoints_--;
		std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << attackDamage_ << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints_ > 0) {
		std::cout << "ClapTrap " << name_ << " takes " << amount << " Damage." << std::endl;
		hitPoints_ -= amount;
		if (hitPoints_ <= 0) {
			std::cout << "ClapTrap " << name_ << " dead." << std::endl;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints_ > 0 && hitPoints_ > 0) {
		energyPoints_--;
		hitPoints_ += amount;
		std::cout << "ClapTrap " << name_ << " repairs " << amount << " hitPoints." << std::endl;
	}
}
