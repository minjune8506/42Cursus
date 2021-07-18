#include "fdf.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void
	valid_width(char *map_name, t_data **data)
{
	int		fd;
	int		is_width;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		print_error("open");
	while (get_next_line(fd, &line) > 0)
	{
		is_width = count_word(line, ' ');
		free(line);
		if (is_width != (*data)->width)
			print_error("Found wrong line length, Exiting");
	}
	free(line);
	close(fd);
}

static void
	get_size(char *map_name, t_data **data)
{
	char	*line;
	int		fd;
	int		height;
	int		width;

	height = 0;
	fd = open(map_name, O_RDONLY, 0);
	if (fd < 0)
		print_error("open");
	while (get_next_line(fd, &line) > 0)
	{
		width = count_word(line, ' ');
		height++;
		free(line);
	}
	if (!height)
		print_error("No data found");
	if (*line)
		height++;
	free(line);
	line = NULL;
	close(fd);
	(*data)->height = height;
	(*data)->width = width;
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

void
	read_map(char *map_name, t_data **data)
{
	get_size(map_name, data);
	valid_width(map_name, data);
	(*data)->z_value = get_zvalue(map_name, data);
	(*data)->color = get_color(map_name, data);
	get_z_range(data);
}
