#include "fdf.h"
#include <stdlib.h>
#include "mlx.h"
#include <math.h>
#include <stdio.h>

int	key_hook(int keycode, void *param)
{
	param = NULL;
	if (keycode == ESC)
		exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		MAX(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		MOD(float x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void drawline(int x, int y, int x1, int y1, t_mlx mlx)
{
    int dx, dy, p;
	
	x *= 20;
	y *= 20;
	x1 *= 20;
	y1 *= 20;

	dx = x1 - x;
	dy = y1 - y;
	p = 2 * (dy - dx);
	while (x < x1)
	{
		if (p >= 0)
		{
			//  my_mlx_pixel_put(img->img, x, y, 0xFF0000);
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, 0xff0000);
			y++;
			p = p + 2 * (dy - dx);
		}
		else
		{
			//  my_mlx_pixel_put(img->img, x, y, 0xFF0000);
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, 0xff0000);
			p = p + 2 * dy;
		}
		x++;
	}
}

void	drawtest(int x, int y, int x1, int y1, t_mlx mlx)
{
	int dx;
	int dy;

	x *= 20;
	y *= 20;
	x1 *= 20;
	y1 *= 20;

	dx = x1 - x;
	dy = y1 - y;
	if (dx > 0)
		while (x < x1)
		{
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, 0xff0000);
			x++;
		}
	else
		while (y < y1)
		{
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, 0xff0000);
			y++;
		}
}

void	bresenham(float x, float y, float x1, float y1, t_mlx mlx)
{
	float	delta_x;
	float	delta_y;
	int		big;

	x *= 20;
	y *= 20;
	x1 *= 20;
	y1 *= 20;

	delta_x = x1 - x;
	delta_y = y1 - y;

	big = MAX(MOD(delta_x), MOD(delta_y));
	delta_x /= big;
	delta_y /= big;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, 0xff0000);
		x += delta_x;
		y += delta_y;
	}

}

void	draw(t_data *data, t_mlx mlx)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			// bresenham(x, y, x + 1, y, mlx);
			// bresenham(x, y, x, y + 1, mlx);
			drawtest(x, y, x + 1, y, mlx);
			drawtest(x, y, x, y + 1, mlx);
			x++;
		}
		y++;
	}
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img->img, 100, 100);
}

void	mlx(t_data *data)
{
	t_mlx	mlx;
	t_img	img;
	void	*param;

	param = NULL;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 800, 600, "fdf");
	img.img = mlx_new_image(mlx.mlx_ptr, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("img.bits_per_pixel : %d\n", img.bits_per_pixel);
	printf("img.line_length : %d\n", img.line_length);
	printf("img.endian: %d\n", img.endian);
	draw(data, mlx);
	mlx_key_hook(mlx.win_ptr, key_hook, param);
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
		map_name = av[1];
		read_map(map_name, &data);
		mlx(data);
		free_int(data->z_value, data->height);
		free_uint(data->color, data->height);
		free(data);
	}
	return (0);
}
