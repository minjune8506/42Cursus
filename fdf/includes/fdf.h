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
# define ISO 34
# define PARALLEL 35
# define PI 3.141592

typedef struct s_data
{
	int					height;
	int					width;
	int					**z_value;
	unsigned int		**color;
	int					z_max;
	int					z_min;
	int					win_width;
	int					win_height;
	struct s_projection	*project;
	struct s_mlx		*mlx;
}t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}t_mlx;

typedef struct s_projection
{
	int		zoom;
	int		shift_x;
	int		shift_y;
	float	alpha;
	float	beta;
	float	gamma;
	int		iso;
}t_projection;

typedef struct s_point
{
	int	x;
	int	y;
	int	flag;
}t_point;

typedef struct s_dda
{
	float			x;
	float			x1;
	float			y;
	float			y1;
	float			step;
	float			xinc;
	float			yinc;
	int				z;
	int				z1;
	unsigned int	color;
}t_dda;

/*
** read_map.c
*/
void			read_map(char *map_name, t_data **data);
/*
** read_utils.c
*/
void			get_z_range(t_data **data);
void			fill_zvalue(char *line, int **value, t_data **data);
void			fill_color(char *line, unsigned int **color);
/*
** memory_utils.c
*/
void			free_int(int **value, int i);
void			free_uint(unsigned int **value, int i);
unsigned int	**color_allocate(t_data **data);
int				**z_allocate(t_data **data);
/*
** get_next_line.c
*/
int				get_next_line(int fd, char **line);
/*
** utils.c
*/
char			*ft_strjoin_free(char *s1, char *s2);
unsigned int	ft_atoi_base(char *nbr);
void			print_error(char *error);
/*
** control.c
*/
int				key_control(int keycode, t_data **data);
/*
** control_utils.c
*/
int				control_x(int keycode, t_data **data);
int				control_y(int keycode, t_data **data);
int				control_z(int keycode, t_data **data);
int				control_projection(int keycode, t_data **data);
/*
** init.c
*/
void			init(t_data **data);
void			zoom_init(t_data **data);
void			shift_init(t_data **data);
/*
** project.c
*/
void			projection(t_point point, t_data **data, t_dda *com);
/*
** draw.c
*/
void			init_dda(t_point point, t_dda *com);
void			get_data(t_data **data, t_dda *com);
void			isometric(float *x, float *y, int z);
void			draw(t_data **data);
/*
** draw_utils.c
*/
float			my_abs(float x);
float			big(float a, float b);
/*
** project_utils.c
*/
void			zoom(t_dda *com, t_data **data);
void			shift(t_data **data, t_dda *com);
#endif