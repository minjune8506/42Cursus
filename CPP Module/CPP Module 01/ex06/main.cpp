#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage : ./harlFilter [level]" << std::endl;
		return (EXIT_SUCCESS);
	}
	Harl harl;
	harl.complain(av[1]);
	return (EXIT_SUCCESS);
}