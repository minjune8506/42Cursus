#include "fdf.h"
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
	while (base[i] != '\0')
	{
		if (ft_tolower(target) == base[i])
			return (i);
		i++;
	}
	return (-1);
}

unsigned int
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

void	print_error(char *error)
{
	perror(error);
	exit(1);
}

static int		get_width(char *map_name)
{
	char	*line;
	int		fd;
	int		width;

	width = 0;
	line = NULL;
	fd = open(map_name, O_RDONLY, 0);
	if (fd < 0)
		print_error("open");
	while (get_next_line(fd, &line) > 0)
	{
		width = count_word(line, ' ');
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
	return (width);
}

static int		get_height(char *map_name)
{
	char	*line;
	int		fd;
	int		height;
	int		width;

	height = 0;
	line = NULL;
	fd = open(map_name, O_RDONLY, 0);
	if (fd < 0)
		print_error("open");
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
		line = NULL;
	}
	if (*line)
		height++;
	free(line);
	line = NULL;
	close(fd);
	return (height);
}

void	fill_zvalue(char *line, int **value, t_data **data)
{
	char **temp;
	int i;

	i = 0;
	temp = ft_split(line, ' ');
	while (i < (*data)->width)
	{
		(*value)[i] = ft_atoi(temp[i]);
		free(temp[i]);
		i++;
	}
	i = 0;
	free(temp);
}

static void	free_all(int **value, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(value[j++]);
	free(value);
}

static void	free_un(unsigned int **value, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(value[j++]);
	free(value);
}


static int		**get_zvalue(char *map_name, t_data **data)
{
	char	*line;
	int		**value;
	int		fd;
	int		i;

	fd = open(map_name, O_RDONLY, 0);
	if (fd < 0)
		print_error("open");
	value= (int **)malloc(sizeof(int *) * (*data)->height);
	if (!value)
		print_error("malloc");
	i = 0;
	while (i < (*data)->height)
	{
		value[i] = (int *)malloc(sizeof(int) * (*data)->width);
		if (!(value[i]))
		{
			free_all(value, i);
			print_error("malloc");
		}
		i++;
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_zvalue(line, &value[i], data);
		free(line);
		line = NULL;
		i++;
	}
	free(line);
	line = NULL;
	close(fd);
	return (value);
}

void	fill_color(char *line, unsigned int **color)
{
	char **temp;
	int i;
	int	j;

	temp = ft_split(line, ' ');
	i = 0;
	while (temp[i])
	{
		if (ft_strchr(temp[i], ',') > 0)
		{
			j = ft_strchr(temp[i], ',');
			// temp[i] = ft_substr(temp[i], 2, ft_strlen(temp[i]) - 2);
			(*color)[i] = ft_atoi_base(temp[i] + j + 3);
		}
		else
			(*color)[i] = 0; // DEFAULT COLOR
		free(temp[i]);
		i++;
	}
	free(temp);
}

unsigned int		**get_color(char *map_name, t_data **data)
{
	char	*line;
	unsigned int		**color;
	int		fd;
	int		i;

	fd = open(map_name, O_RDONLY,  0);
	if (fd < 0)
		print_error("open");
	color = (unsigned int **)malloc(sizeof(unsigned int *) * (*data)->height);
	if (!color)
		print_error("malloc");
	i = 0;
	while (i < (*data)->height)
	{
		color[i] = (unsigned int *)malloc(sizeof(unsigned int) * (*data)->width);
		if (!color[i])
		{
			free_un(color, i);
			print_error("malloc");
		}
		i++;
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_color(line, &color[i]);
		i++;
		free(line);
	}
	free(line);
	close(fd);
	return (color);
}

static void	read_map(char *map_name, t_data **data)
{
	(*data)->width= get_width(map_name);
	(*data)->height = get_height(map_name);
	printf("data->width : %d\n", (*data)->width);
	printf("data->height : %d\n", (*data)->height);
	(*data)->z_value = get_zvalue(map_name, data);
	printf("z_value clear\n");
	// int i = 0;
	// while (i < (*data)->height)
	// {
	// 	int j = 0;
	// 	while (j < (*data)->width)
	// 	{
	// 		printf("%3d", (*data)->z_value[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	(*data)->color = get_color(map_name, data);
	printf("color clear\n");
	// i = 0;
	// while (i < (*data)->height)
	// {
	// 	int j = 0;
	// 	while (j < (*data)->width)
	// 	{
	// 		printf("%d ", (*data)->color[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	*map_name;
	
	data = (t_data *)malloc(sizeof(t_data));
	map_name = av[1];
	read_map(map_name, &data);
	int i = 0;
	while(i < data->height)
	{
		free(data->z_value[i]);
		i++;
	}
	free(data->z_value);
	i = 0;
	while (i < data->height)
	{
		free(data->color[i]);
		i++;
	}
	free(data->color);
	free(data);
}