/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:27:59 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/26 18:28:01 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>

int	check_ac(int ac);
int	check_av(char **av);
int	is_num(char *str);
int	ft_strlen(char *str);

int
	check_args(int ac, char **av)
{
	if (check_ac(ac) || check_av(av))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int
	check_ac(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Invalid Parameter\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int
	check_av(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_num(av[i]))
		{
			printf("Invalid Parameter\n");
			return (EXIT_FAILURE);
		}
		if (ft_atoi(av[i]) <= 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int
	is_num(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int
	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
