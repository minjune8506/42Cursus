#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

#include <stdio.h>
// int	shutdown(int keycode, void *param)
// {
// 	param = NULL;
// 	if (keycode == ESC)
// 		exit(0);
// 	return (0);
// }

int	print_key(int keycode, void *param)
{
	param = NULL;
	printf("keycode : %d\n", keycode);
	return (0);
}

void	zoom_control(int keycode, t_mlx *mlx)
{
	if (keycode == MINUS)
		mlx->zoom--;
	else if (keycode == PLUS)
		mlx->zoom++;
}

int	key_control(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == MINUS || keycode == PLUS)
		zoom_control(keycode, mlx);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	zoom(t_dda *com, t_mlx mlx)
{
	if (mlx.screen_w <= 100)
		mlx.zoom = 5;
	else if (mlx.screen_w <= 500)
		mlx.zoom = 10;
	else if (mlx.screen_w <= 800)
		mlx.zoom = 30;
	else
		mlx.zoom = 5;
	com->x *= mlx.zoom;
	com->y *= mlx.zoom;
	com->x1 *= mlx.zoom;
	com->y1 *= mlx.zoom;
	com->z *= mlx.zoom;
	com->z1 *= mlx.zoom;
}

void	shift(int x_shift, int y_shift, t_mlx mlx, t_dda *com)
{
	com->x += x_shift;
	com->y += mlx.screen_h - y_shift;
	com->x1 += x_shift;
	com->y1 += mlx.screen_h - y_shift;
}

void	set_screen_size(t_data *data, t_mlx *mlx)
{
	if (data->width <= 30)
		mlx->screen_w = data->width * 30;
	else if (data->width <= 50)
		mlx->screen_w = data->width * 7;
	else
		mlx->screen_w = 1200;
	if (data -> height <= 50)
		mlx->screen_h = data->height * 30;
	else if (data->height <= 100)
		mlx->screen_h = data->height * 7;
	else
		mlx->screen_h = 800;
}

void	mlx(t_data *data)
{
	t_mlx	mlx;
	t_img	img;

	mlx.mlx_ptr = mlx_init();
	set_screen_size(data, &mlx);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.screen_w, mlx.screen_h, "fdf");
	img.img = mlx_new_image(mlx.mlx_ptr, mlx.screen_w, mlx.screen_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// printf("img.addr = %p\n", img.addr);
	// printf("img.bits_per_pixel : %d\n", img.bits_per_pixel);
	// printf("img.line_length : %d\n", img.line_length);
	// printf("img.endian: %d\n", img.endian);
	draw(data, mlx);
	mlx_key_hook(mlx.win_ptr, key_control, &mlx);
	// up : 126 / down : 125 / left : 123 / right : 124
	// - : 27 / + : 24
	mlx_loop(mlx.mlx_ptr);
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
		mlx(data);
		free_int(data->z_value, data->height);
		free_uint(data->color, data->height);
		free(data);
	}
	return (0);
}
