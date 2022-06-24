#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap x("Foo");
	ClapTrap y("Bar");
	ScavTrap z("FooBar");

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

	z.attack("Bar");
	y.takeDamage(z.getAttackDamage());

	z.guardGate();
}