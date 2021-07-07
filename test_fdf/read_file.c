#include "fdf.h"
#include <fcntl.h>

int		get_height(char *file_name)
{
	char *line;
	int fd;
	int height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	char *line;
	int fd;
	int width;

	fd = open(file_name, O_RDONLY, 0);
	width = 0;
	get_next_line(fd, &line);
	width = ft_split(line, ' ');
	free(line);
	close(fd);
	return (width);

}
void	read_file(t_fdf *data, char *file_name)
{
	data->height = get_height(file_name);
}