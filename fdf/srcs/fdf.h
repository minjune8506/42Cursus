#ifndef FDF_H
# define FDF_H

typedef struct s_data
{
	int	height;
	int	width;
	int	**z_value;
	unsigned int **color;
}t_data;

int		get_next_line(int fd, char **line);
#endif