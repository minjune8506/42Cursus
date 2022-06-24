#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &obj);
	DiamondTrap &operator=(const DiamondTrap &obj);
	~DiamondTrap();
	void attack(const std::string &target);
	void whoAmI();
private:
	std::string name_;
};

#endif