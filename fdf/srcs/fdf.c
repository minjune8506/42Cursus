#include "fdf.h"
#include "../minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int
	find_base(char target)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	while (ft_tolower(base[i]) != '\0')
	{
		if (target == ft_tolower(base[i]))
			return (i);
		i++;
	}
	return (-1);
}

int
	ft_atoi_base(char *nbr)
{
	unsigned int	result;

	result = 0;
	while (find_base(*nbr) != -1 && *nbr)
	{
		result *= 16;
		result += find_base(*nbr);
		nbr++;
	}
	return (result);
}

void
	parse_map(char *line, t_map **map)
{
	char	**split;
	int		i;
	int		color;
	int		z;

	split = ft_split(line, ' ');
	color = 0;
	i = 0;
	while (split[i])
	{
		z = ft_atoi(split[i]);
		split[i] = ft_strchr(split[i], ',');
		if (split[i] == NULL)
		{
			push(map, z, color);
			i++;
			continue ;
		}
		split[i]++;
		split[i] = ft_substr(split[i], 2, ft_strlen(split[i]) - 2);
		color = ft_atoi_base(split[i]);
		push(map, z, color);
		i++;
	}
}

int
	main(int ac, char **av)
{
	t_map	*map;
	int		fd;
	char	*line;

	map = NULL;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		parse_map(line, &map);
		free(line);
		line = NULL;
	}
	print_stack(&map);
	free(line);
}