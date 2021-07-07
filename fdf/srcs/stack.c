#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

int		is_empty(t_map **map)
{
	if (*map == NULL)
		return (1);
	return (0);
}

void	push(t_map **map, int z, unsigned int color, int count)
{
	t_map *new;

	new = (t_map *)malloc(sizeof(struct s_map));
	new->z = z;
	new->color = color;
	new->next = *map;
	*map = new;
}

t_map	*pop(t_map **map)
{
	t_map *temp;

	if (!is_empty(map))
	{
		temp = *map;
		*map = temp->next;
	}
	return (temp);
}

void	print_stack(t_map **map)
{
	t_map *temp;

	temp = *map;
	if (!is_empty(&temp))
	{
		while (temp)
		{
			temp = temp->next;
		}
	}
}