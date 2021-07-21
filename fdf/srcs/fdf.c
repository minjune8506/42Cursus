/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:24:10 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/20 15:24:11 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

static void
	img_init(t_data **data)
{
	(*data)->img->img_ptr = mlx_new_image((*data)->mlx->mlx_ptr, \
	(*data)->win_width, (*data)->win_height);
	(*data)->img->addr = mlx_get_data_addr((*data)->img->img_ptr, \
	&(*data)->img->bps, &(*data)->img->line_size, &(*data)->img->endian);
}

void
	menu(t_data **data)
{
	void	*mlx;
	void	*win;
	int		y;

	mlx = (*data)->mlx->mlx_ptr;
	win = (*data)->mlx->win_ptr;
	y = 0;
	mlx_string_put(mlx, win, 10, 0, 0xFFFFFF, "FDF - minjkim2");
	mlx_string_put(mlx, win, 10, y += 40, 0xA9BCF5, \
	"------ keyboard_menu ------");
	mlx_string_put(mlx, win, 10, y += 20, 0xA9BCF5, "exit : esc");
	mlx_string_put(mlx, win, 10, y += 20, 0xA9BCF5, \
	"zoom : - / +");
	mlx_string_put(mlx, win, 10, y += 20, 0xA9BCF5, \
	"move : up / down / left / right");
	mlx_string_put(mlx, win, 10, y += 20, 0xA9BCF5, "rotate_x : num1 / num2");
	mlx_string_put(mlx, win, 10, y += 20, 0xA9BCF5, "rotate_y : num3 / num4");
	mlx_string_put(mlx, win, 10, y += 20, 0xA9BCF5, "rotate_z : num5 / num6");
	mlx_string_put(mlx, win, 10, y += 20, 0xA9BCF5, "isometric : i");
	mlx_string_put(mlx, win, 10, y += 20, 0xA9BCF5, "parallel : p");
}

static void
	mlx(t_data **data)
{
	(*data)->mlx->mlx_ptr = mlx_init();
	if (!(*data)->mlx->mlx_ptr)
		print_error("mlx");
	(*data)->mlx->win_ptr = mlx_new_window((*data)->mlx->mlx_ptr, \
	(*data)->win_width, (*data)->win_height, "fdf");
	img_init(data);
	if (!(*data)->mlx->win_ptr)
		print_error("mlx");
	draw(data);
	mlx_put_image_to_window((*data)->mlx->mlx_ptr, \
	(*data)->mlx->win_ptr, (*data)->img->img_ptr, 0, 0);
	menu(data);
	mlx_key_hook((*data)->mlx->win_ptr, key_control, data);
	mlx_loop((*data)->mlx->mlx_ptr);
}

static void
	memory_allocate(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	(*data)->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	(*data)->project = (t_projection *)malloc(sizeof(t_projection));
	(*data)->img = (t_img *)malloc(sizeof(t_img));
	if (!(*data)->mlx || !(*data)->project || !(*data)->img)
		print_error("malloc error");
}

int
	main(int ac, char **av)
{
	t_data	*data;
	char	*map_name;

	if (ac != 2)
		print_error("Usage : ./fdf <filename> [ case_size z_size ]");
	else
	{
		memory_allocate(&data);
		map_name = av[1];
		read_map(map_name, &data);
		init(&data);
		mlx(&data);
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
		print_error("mlx");
	}
	return (0);
}
