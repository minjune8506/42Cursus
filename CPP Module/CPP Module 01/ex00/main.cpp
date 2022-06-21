#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;
	
	randomChump("Bar");
	zombie = newZombie("Foo");
	zombie->announce();
	delete zombie;
	return (0);
}