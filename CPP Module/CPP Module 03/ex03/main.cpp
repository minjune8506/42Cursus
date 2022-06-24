#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap d("test");

	d.attack("Foo");
	d.whoAmI();
	d.guardGate();
	d.highFivesGuys();
	std::cout << d.getAttackDamage() << std::endl;
	d.beRepaired(10);
}