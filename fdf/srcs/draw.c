#include "fdf.h"
#include "mlx.h"
#include <math.h>

static void	init_dda(t_point point, t_dda *com)
{
	com->x = point.x;
	com->y = point.y;
	if (point.flag == 1)
	{
		com->x1 = point.x + 1;
		com->y1 = point.y;
	}
	if (point.flag == 2)
	{
		com->x1 = point.x;
		com->y1 = point.y + 1;
	}
}

static void	get_data(t_data **data, t_dda *com)
{
	com->z = (*data)->z_value[(int)com->y][(int)com->x];
	com->z1 = (*data)->z_value[(int)com->y1][(int)com->x1];
	com->color = (*data)->color[(int)com->y][(int)com->x];
	if (com->color == 0)
	{
		if (com->z)
			com->color = 0xFFFFFF;
		else
			com->color = 0xFFFFFF;
	}
}

void	isometric(float *x, float *y, int z)
{
	float	pre_x;
	float	pre_y;

	pre_x = *x;
	pre_y = *y;
	// *x = pre_x * cos(PI / 6 * -1) - pre_y * sin(PI / 3 * -1);
	// *y = pre_x * sin(PI / 6 * -1) + pre_y * cos(PI / 3 * -1) - z;
	*x = pre_x * cos(0.4636 * -1) - pre_y * sin(1.1071 * -1);
	*y = pre_x * sin(0.4636 * -1) + pre_y * cos(1.1071 * -1) - z;
}


static void	dda(t_data **data, t_dda *com)
{
	int i;

	i = 0;
	// t_dda com;
	// init_dda(point, &com);
	// get_data(data, &com);
	// zoom(&com, data);
	// /*-----isometric-----*/
	// isometric(&com.x, &com.y, com.z);
	// isometric(&com.x1, &com.y1, com.z1);
	// /*-----shift-----*/
	// shift((*data)->shift_x, (*data)->shift_y, &com);
	com->step = big(my_abs(com->x1 - com->x), my_abs(com->y1 - com->y));
	com->xinc = (com->x1 - com->x) / com->step;
	com->yinc = (com->y1 - com->y) / com->step;
	while (i <= com->step)
	{
		mlx_pixel_put((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr, com->x, com->y, com->color);
		// my_mlx_pixel_put(img, com->x, com->y, com->color);
		com->x += com->xinc;
		com->y += com->yinc;
		i++;
	}
}

void	rotate_x(t_dda *com, t_data **data)
{
	float pre_y;
	float pre_y1;

	pre_y = com->y;
	pre_y1 = com->y1;
	com->y = cos((*data)->alpha) * pre_y - sin((*data)->alpha) * com->z;
	com->y1 = cos((*data)->alpha) * pre_y1 - sin((*data)->alpha) * com->z1;
	com->z = sin((*data)->alpha) * pre_y + cos((*data)->alpha) * com->z;
	com->z1 = sin((*data)->alpha) * pre_y1 + cos((*data)->alpha) * com->z1;
}

void	rotate_y(t_dda *com, t_data **data)
{
	float pre_x;
	float pre_x1;

	pre_x = com->x;
	pre_x1 = com->x1;
	com->x = pre_x * cos((*data)->beta) + com->z * sin((*data)->beta);
	com->z = -pre_x * sin((*data)->beta) + com->z * cos((*data)->beta);
	com->x1 = pre_x1 * cos((*data)->beta) + com->z1 * sin((*data)->beta);
	com->z1 = -pre_x1 * sin((*data)->beta) + com->z1 * cos((*data)->beta);
}

void	rotate_z(t_dda *com, t_data **data)
{
	float pre_x;
	float pre_x1;

	pre_x = com->x;
	pre_x1 = com->x1;

	com->x = pre_x * cos((*data)->gamma) - com->y * sin((*data)->gamma);
	com->y = pre_x * sin((*data)->gamma) + com->y * cos((*data)->gamma);
	com->x1 = pre_x1 * cos((*data)->gamma) - com->y1 * sin((*data)->gamma);
	com->y1 = pre_x1 * sin((*data)->gamma) + com->y1 * cos((*data)->gamma);
}
void	projection(t_point point, t_data ** data, t_dda *com)
{
	init_dda(point, com);
	get_data(data, com);
	zoom(com, data);
	rotate_x(com, data);
	rotate_y(com, data);
	rotate_z(com, data);
	/*-----isometric-----*/
	isometric(&com->x, &com->y, com->z);
	isometric(&com->x1, &com->y1, com->z1);
	/*-----shift-----*/
	shift((*data)->shift_x, (*data)->shift_y, com);
}

void	draw(t_data **data)
{
	t_point point;
	t_dda com;

	point.y = 0;
	while (point.y < (*data)->height)
	{
		point.x = 0;
		while (point.x < (*data)->width)
		{
				if (point.x + 1 < (*data)->width)
				{
					point.flag = 1;
					projection(point, data, &com);
					dda(data, &com);
				}
				if (point.y + 1 < (*data)->height)
				{
					point.flag = 2;
					projection(point, data, &com);
					dda(data, &com);
				}
			point.x++;
		}
		point.y++;
	}	
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img->img, 100, 100);
}