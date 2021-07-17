#ifndef FDF_H
# define FDF_H
# define ESC 53
# define MINUS 27
# define PLUS 24
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define NUM1 18
# define NUM2 19
# define NUM3 20
# define NUM4 21
# define NUM5 23
# define NUM6 22

# define PI 3.141592

typedef struct s_data
{
	int				height;
	int				width;
	int				**z_value;
	unsigned int	**color;
	int				z_max;
	int				z_min;
	int				win_width;
	int				win_height;
	int				zoom;
	int				shift_x;
	int				shift_y;
	float				alpha;
	float				beta;
	float				gamma;
	struct s_projection *project;
	struct s_mlx	*mlx;
}t_data;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}t_mlx;

typedef struct s_projection
{
	int zoom;
	int shift_x;
	int shift_y;
	float alpha;
	float beta;
	float gamma;
}t_projection;

typedef struct s_point
{
	int x;
	int y;
	int flag;
}t_point;

typedef struct s_dda
{
	float x;
	float x1;
	float y;
	float y1;
	float step;
	float xinc;
	float yinc;
	int z;
	int z1;
	unsigned int color;
}t_dda;

void			read_map(char *map_name, t_data **data);
void			fill_zvalue(char *line, int **value, t_data **data);
void			fill_color(char *line, unsigned int **color);
unsigned int	**color_allocate(t_data **data);
int				**z_allocate(t_data **data);
void			free_int(int **value, int i);
void			free_uint(unsigned int **value, int i);
int				get_next_line(int fd, char **line);
char			*ft_strjoin_free(char *s1, char *s2);
unsigned int	ft_atoi_base(char *nbr);
void			print_error(char *error);
float			my_abs(float x);
float			big(float a, float b);
void			isometric(float *x, float *y, int z);
void			draw(t_data **data);
void			zoom(t_dda *com, t_data **data);
void			shift(int x_shift, int y_shift, t_dda *com);
#endif