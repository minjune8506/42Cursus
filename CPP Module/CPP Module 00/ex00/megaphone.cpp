#include <iostream>
#include <cctype>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac <= 1)
		std::cout << "* LOUD AND UNBLEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1 ; i < ac ; i++) {
			int length = strlen(av[i]);
			for (int j = 0 ; j < length ; j++) {
				if (isalpha(av[i][j]))
					av[i][j] = toupper(av[i][j]);
			}
			std::cout << av[i];
		}
	}
	std::cout << std::endl;
}
