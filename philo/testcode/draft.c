#include <stdio.h>
#include "./ft_atoi.c"

unsigned int	num_philo;
unsigned int	t_die;
unsigned int	t_eat;
unsigned int	t_sleep;
unsigned int	must_eat;

int		error_exit(char *str);
void	fill_data(char **av);

int		main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (error_exit("Invalid Input"));
	fill_data(av);
}

int		error_exit(char *str)
{
	printf("%s\n", str);
	return (0);
}

void	fill_data(char **av)
{
	num_philo = ft_atoi(av[1]);
	t_die = ft_atoi(av[2]);
	t_eat = ft_atoi(av[3]);
	t_sleep = ft_atoi(av[4]);
	if (av[5])
		must_eat = ft_atoi(av[5]);
	return ;
}
