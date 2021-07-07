#ifndef FDF_H
# define FDF_H

#include "../fdf/srcs/libft/libft.h"
#include "../fdf/minilibx_macos/mlx.h"

typedef struct s_fdf
{
	int width;
	int height;
	int **z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
}t_fdf;
 
#endif