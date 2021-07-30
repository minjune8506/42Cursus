#include "push_swap.h"
#include "libft.h"

void check_valid(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && !(av[i][j] == ' ') && !(av[i][j] == '-'))
				print_error();
			j++;
		}
		i++;
	}
}

void check_range(char **av)
{
	char **temp;
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
		{
			j = 0;
			temp = ft_split(av[i], ' ');
			while (temp[j])
			{
				if (ft_strlen(temp[j]) > 11 || ft_atoi_long(temp[j]) > 2147483647 || ft_atoi_long(temp[j]) < -2147483648)
					print_error();
				j++;
			}
			split_free(temp);
		}
		else
		{
			if (ft_strlen(av[i]) > 11 || ft_atoi_long(av[i]) > 2147483647 || ft_atoi_long(av[i]) < -2147483648)
				print_error();
		}
		i++;
	}
}

void	check_overlap(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				print_error();
			j++;
		}
		i++;
	}
}