#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie *zombies;

	zombies = zombieHorde(10, "Foo");
	if (!zombies)
		return (EXIT_FAILURE);
	for (int i = 0 ; i < 10 ; i++) {
		zombies[i].announce();
	}
	delete [] zombies;
	return (EXIT_SUCCESS);
}