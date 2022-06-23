#include "Zombie.hpp"
#include <cstdlib>

int main(void)
{
	Zombie *zombie;
	
	randomChump("Bar");
	zombie = newZombie("Foo");
	if (!zombie)
		return (EXIT_FAILURE);
	zombie->announce();
	delete zombie;
	return (EXIT_SUCCESS);
}