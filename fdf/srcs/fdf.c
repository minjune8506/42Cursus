#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include <math.h>

#include <stdio.h>

int	print_key(int keycode, void *param)
{
	param = NULL;
	printf("keycode : %d\n", keycode);
	return (0);
}

int	zoom_control(int keycode, t_data **data)
{
	if (keycode == MINUS)
	{
		mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
		if ((*data)->zoom > 0)
			(*data)->zoom--;
		draw(data);
	}
	if (keycode == PLUS)
	{
		mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
			(*data)->zoom++;
		draw(data);
	}
	return (0);
}

int	lr_control(int keycode, t_data **data)
{
	if (keycode == LEFT)
	{
		mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
		if ((*data)->shift_x > 0)
			(*data)->shift_x -= 20;
		draw(data);
	}
	if (keycode == RIGHT)
	{
		mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
		if ((*data)->shift_x < (*data)->win_width - (*data)->width * (*data)->zoom)
			(*data)->shift_x += 20;
		draw(data);
	}
	return (0);
}

int	ud_control(int keycode, t_data **data)
{
	if (keycode == UP)
	{
		mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
		if ((*data)->shift_y > 0)
			(*data)->shift_y -= 20;
		draw(data);
	}
	if (keycode == DOWN)
	{
		mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
		if ((*data)->shift_y < (*data)->win_height)
			(*data)->shift_y += 20;
		draw(data);
	}
	return (0);
}

int	key_control(int keycode, t_data **data)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == MINUS || keycode == PLUS)
		zoom_control(keycode, data);
	if (keycode == LEFT || keycode == RIGHT)
		lr_control(keycode, data);
	if (keycode == UP || keycode == DOWN)
		ud_control(keycode, data);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	zoom(t_dda *com, t_data **data)
{
	com->x *= (*data)->zoom;
	com->y *= (*data)->zoom;
	com->x1 *= (*data)->zoom;
	com->y1 *= (*data)->zoom;
	com->z *= (*data)->zoom;
	com->z1 *= (*data)->zoom;
}


void	shift(int x_shift, int y_shift, t_dda *com)
{
	com->x += x_shift;
	com->y += y_shift;
	com->x1 += x_shift;
	com->y1 += y_shift;
}

void	get_z_range(t_data **data)
{
	int min;
	int max;
	int i;
	int j;

	min = 0;
	max = 0;
	i = 0;
	while (i < (*data)->height)
	{
		j = 0;
		while (j < (*data)->width)
		{
			if ((*data)->z_value[i][j] > max)
				max = (*data)->z_value[i][j];
			if ((*data)->z_value[i][j] < min)
				min = (*data)->z_value[i][j];
			j++;
		}
		i++;
	}
	(*data)->z_max = max;
	(*data)->z_min = min;
}

void	mlx(t_data **data)
{
	t_img	img;
	(*data)->mlx->mlx_ptr = mlx_init();
	get_z_range(data);
	(*data)->mlx->win_ptr = mlx_new_window((*data)->mlx->mlx_ptr, (*data)->win_width, (*data)->win_height, "fdf");
	img.img = mlx_new_image((*data)->mlx->mlx_ptr, (*data)->win_width, (*data)->win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw(data);
	mlx_key_hook((*data)->mlx->win_ptr, key_control, data);
	mlx_loop((*data)->mlx->mlx_ptr);
}

void	win_size_init(t_data **data)
{
	if ((*data)->width <= 11)
	{
		(*data)->win_width = 640;
		(*data)->win_height = 480;
	}
	else if ((*data)->width <= 100)
	{
		(*data)->win_width = 960;
		(*data)->win_height = 540;
	}
	else if ((*data)->width <= 200)
	{
		(*data)->win_width = 1280;
		(*data)->win_height = 720;
	}
	else
	{
		(*data)->win_width = 1440;
		(*data)->win_height = 900;
	}
	if ((*data)->z_max >= 30)
		(*data)->win_height = 900;
}

void	shift_init(t_data **data)
{
	(*data)->shift_x = 0;
	(*data)->shift_y = 0;
	float center_y = (*data)->height - 1;
	float center_x = 0;
	float center_z = (*data)->z_value[(int)center_y][(int)center_x];
	isometric(&center_x, &center_y, center_z);
	(*data)->shift_x = (*data)->win_width / 2 - center_x * (*data)->zoom;
	(*data)->shift_y = (*data)->win_height - center_y * (*data)->zoom;
	printf("shift_x : %d\n", (*data)->shift_x);
	printf("shift_y : %d\n", (*data)->shift_y);
	printf("sreen_width : %d\nscreen_height : %d\n", (*data)->win_width, (*data)->win_height);
}

void	zoom_init(t_data **data)
{
	float zoom_x;
	float zoom_y;
	int i;
	int j;

	(*data)->zoom = 1;
	zoom_x = (*data)->width;
	zoom_y = (*data)->height;
	if ((*data)->z_max - (*data)->z_min > zoom_y)
		zoom_y += (*data)->z_max;
	i = zoom_x;
	j = zoom_y;
	while (i < ((*data)->win_width / 2) && j < (*data)->win_height)
	{
		i += zoom_x;
		j += zoom_y;
		(*data)->zoom++;
	}
	printf("zoom : %d\n", (*data)->zoom);
}

void	win_size(t_data **data)
{
	get_z_range(data);
	win_size_init(data);
	zoom_init(data);	
	shift_init(data);
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	*map_name;

	if (ac != 2)
		print_error("Usage : ./fdf <filename> [ case_size z_size ]");
	else
	{
		data = (t_data *)malloc(sizeof(t_data));
		data->mlx = (t_mlx *)malloc(sizeof(t_mlx));
		map_name = av[1];
		read_map(map_name, &data);
		win_size(&data);
		mlx(&data);
		free_int(data->z_value, data->height);
		free_uint(data->color, data->height);
		free(data);
	}
	return (0);
}
