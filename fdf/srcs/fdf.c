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

void
	mlx(t_data **data)
{
	(*data)->mlx->mlx_ptr = mlx_init();
	if (!(*data)->mlx->mlx_ptr)
		print_error("mlx");
	(*data)->mlx->win_ptr = mlx_new_window((*data)->mlx->mlx_ptr, \
	(*data)->win_width, (*data)->win_height, "fdf");
	if (!(*data)->mlx->win_ptr)
		print_error("mlx");
	draw(data);
	mlx_key_hook((*data)->mlx->win_ptr, key_control, data);
	mlx_loop((*data)->mlx->mlx_ptr);
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
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			print_error("malloc");
		data->mlx = (t_mlx *)malloc(sizeof(t_mlx));
		if (!data->mlx)
			print_error("malloc");
		data->project = (t_projection *)malloc(sizeof(t_projection));
		if (!data->project)
			print_error("malloc");
		map_name = av[1];
		read_map(map_name, &data);
		init(&data);
		mlx(&data);
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
		print_error("mlx");
	}
	return (0);
}
/*
** free_int(data->z_value, data->height);
** free_uint(data->color, data->height);
** free(data->mlx);
** free(data->project);
** free(data);
*/
