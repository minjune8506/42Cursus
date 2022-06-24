#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {

}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	hitPoints_ = 100;
	energyPoints_ = 100; 
	attackDamage_ = 30;
	std::cout << "FragTrap " << name_ << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj) {
	(*this) = obj;
	std::cout << "FragTrap " << name_ << " created" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj) {
	ClapTrap::operator=(obj);
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name_ << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "positive high fives request" << std::endl;
}