#include "philo.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);
int	is_num(char *str);
int	check_av(char **av);
int	check_ac(int ac);

int check_args(int ac, char **av)
{
	if (check_ac(ac) || check_av(av))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int check_ac(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Invalid Parameter\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int check_av(char **av)
{
	unsigned int i;

	i = 1;
	while (av[i])
	{
		if (!is_num(av[i]))
		{
			printf("Invalid Parameter\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int is_num(char *str)
{
	unsigned int i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int ft_strlen(char *str)
{
	unsigned int length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
