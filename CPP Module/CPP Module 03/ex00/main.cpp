#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap x("Foo");
	ClapTrap y("Bar");

	x.setAttackDamage(3);
	y.setAttackDamage(5);

	x.attack("Bar");
	y.takeDamage(x.getAttackDamage()); // 7

	x.attack("Bar");
	y.takeDamage(x.getAttackDamage()); // 4

	y.beRepaired(3); // 7
	
	y.attack("Foo");
	x.takeDamage(y.getAttackDamage()); // 5

	y.attack("Foo");
	x.takeDamage(y.getAttackDamage()); // 0

	y.attack("Foo");
	x.takeDamage(y.getAttackDamage()); // -5

	y.attack("Foo");
	x.takeDamage(y.getAttackDamage()); // -10
}