#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define ESC 53

typedef struct s_data
{
	void *img;
	char *addr;
	int	bits_per_pixel;
	int	line_length;
	int endian;
}	t_data;

int	key_hook(int keycode, void *param)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void *mlx;
	void *win;
	void *param;
	t_data img;
	int x = 0;
	int color = 16711680;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("img.bits_per_pixel : %d\n", img.bits_per_pixel);
	printf("img.line_length : %d\n", img.line_length);
	printf("img.endian: %d\n", img.endian);
	int y = 0;
	mlx_string_put(mlx, win, x, y, color, "i'll kill you");
	while (x < 50)
	{
		int y = 0;		
		while (y < 50)
		{
			// my_mlx_pixel_put(&img, x, y, 0xFF0000);
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, win, img.img, 100, 100);
	mlx_key_hook(win, key_hook, param);
	mlx_loop(mlx);
}