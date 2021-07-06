#ifndef FDF_H
# define FDF_H

typedef struct s_map
{
	int				z;
	unsigned int	color;
	struct s_map	*next;
}t_map;

int		is_empty(t_map **map);
void	push(t_map **map, int z, unsigned int color);
t_map	*pop(t_map **map);
void	print_stack(t_map **map);
int		get_next_line(int fd, char **line);
#endif