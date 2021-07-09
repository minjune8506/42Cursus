#ifndef FDF_H
# define FDF_H
# define ESC 53

typedef struct s_data
{
	int				height;
	int				width;
	int				**z_value;
	unsigned int	**color;
}t_data;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length; 
	int		endian;
}t_img;

void			read_map(char *map_name, t_data **data);
void			fill_zvalue(char *line, int **value, t_data **data);
void			fill_color(char *line, unsigned int **color);
int				valid_width(int *width, t_data **data);
unsigned int	**color_allocate(t_data **data);
int				**z_allocate(t_data **data);
void			free_int(int **value, int i);
void			free_uint(unsigned int **value, int i);
int				get_next_line(int fd, char **line);
char			*ft_strjoin_free(char *s1, char *s2);
unsigned int	ft_atoi_base(char *nbr);
void			print_error(char *error);
#endif