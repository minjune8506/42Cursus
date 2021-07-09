#include "fdf.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int
	get_width(char *map_name, t_data **data)
{
	char	*line;
	int		*width;
	int		fd;
	int		i;

	i = 0;
	line = NULL;
	width = (int *)malloc(sizeof(int) * (*data)->height);
	fd = open(map_name, O_RDONLY, 0);
	if (fd < 0)
		print_error("open");
	while (get_next_line(fd, &line) > 0)
	{
		width[i++] = count_word(line, ' ');
		free(line);
		line = NULL;
	}
	width[i] = count_word(line, ' ');
	free(line);
	line = NULL;
	close(fd);
	return (valid_width(width, data));
}

static int
	get_height(char *map_name)
{
	char	*line;
	int		fd;
	int		height;

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
	if (!height)
		print_error("No data found");
	if (*line)
		height++;
	free(line);
	line = NULL;
	close(fd);
	return (height);
}

static int
	**get_zvalue(char *map_name, t_data **data)
{
	char	*line;
	int		**value;
	int		fd;
	int		i;

	fd = open(map_name, O_RDONLY, 0);
	if (fd < 0)
		print_error("open");
	value = z_allocate(data);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_zvalue(line, &value[i++], data);
		free(line);
		line = NULL;
	}
	if (*line)
		fill_zvalue(line, &value[i], data);
	free(line);
	line = NULL;
	close(fd);
	return (value);
}

static unsigned int
	**get_color(char *map_name, t_data **data)
{
	char			*line;
	unsigned int	**color;
	int				fd;
	int				i;

	fd = open(map_name, O_RDONLY, 0);
	if (fd < 0)
		print_error("open");
	color = color_allocate(data);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_color(line, &color[i++]);
		free(line);
		line = NULL;
	}
	if (*line)
		fill_color(line, &color[i]);
	free(line);
	line = NULL;
	close(fd);
	return (color);
}

#include <stdio.h>

void
	read_map(char *map_name, t_data **data)
{
	(*data)->height = get_height(map_name);
	(*data)->width = get_width(map_name, data);
	(*data)->z_value = get_zvalue(map_name, data);
	(*data)->color = get_color(map_name, data);
	printf("data->width : %d\n", (*data)->width);
	printf("data->height : %d\n", (*data)->height);
	int i = 0;
	while (i < (*data)->height)
	{
		int j = 0;
		while (j < (*data)->width)
		{
			printf("%3d", (*data)->z_value[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("----------------------------------------\n");
	i = 0;
	while (i < (*data)->height)
	{
		int j = 0;
		while (j < (*data)->width)
		{
			printf("%d ", (*data)->color[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
