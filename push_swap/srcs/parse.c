#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static int
	get_array_size(char **av)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
			count += count_word(av[i], ' ');
		else
			count++;
		i++;
	}
	return (count);
}

static void
	to_array(char **av, int **arr)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	i = 1;
	k = 0;
	while (av[i])
	{
		if (ft_strchr(av[i], ' '))
		{
			j = 0;
			temp = ft_split(av[i], ' ');
			while (temp[j])
				(*arr)[k++] = ft_atoi(temp[j++]);
			split_free(temp);
		}
		else
			(*arr)[k++] = ft_atoi(av[i]);
		i++;
	}
}

static void
	array_to_stack(int *arr, t_stack **stack_a, int size)
{
	while (size > 0)
	{
		push((*stack_a), arr[size - 1]);
		size--;
	}
}

void
	parse(char **av, t_stack **stack_a)
{
	int	*arr;
	int	size;

	check_valid(av);
	check_range(av);
	size = get_array_size(av);
	arr = (int *)malloc(sizeof(int) * size);
	to_array(av, &arr);
	check_overlap(arr, size);
	array_to_stack(arr, stack_a, size);
	free(arr);
}
