/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:23:47 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/20 15:23:49 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

static int
	zoom_control(int keycode, t_data **data)
{
	if (keycode == MINUS)
	{
		if ((*data)->project->zoom > 0)
			(*data)->project->zoom--;
	}
	if (keycode == PLUS)
		(*data)->project->zoom++;
	return (1);
}

static int
	lr_control(int keycode, t_data **data)
{
	if (keycode == LEFT)
		(*data)->project->shift_x -= 20;
	if (keycode == RIGHT)
		(*data)->project->shift_x += 20;
	return (1);
}

static int
	ud_control(int keycode, t_data **data)
{
	if (keycode == UP)
		(*data)->project->shift_y -= 20;
	if (keycode == DOWN)
		(*data)->project->shift_y += 20;
	return (1);
}

static void
	redraw(t_data **data)
{
	mlx_clear_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr);
	ft_bzero((*data)->img->addr, (*data)->win_width * (*data)->win_height \
	* (*data)->img->bps / 8);
	draw(data);
	mlx_put_image_to_window((*data)->mlx->mlx_ptr, (*data)->mlx->win_ptr, \
	(*data)->img->img_ptr, 0, 0);
	menu(data);
}

int
	key_control(int keycode, t_data **data)
{
	int	ret;

	ret = 0;
	if (keycode == ESC)
		exit(0);
	if (keycode == MINUS || keycode == PLUS)
		ret = zoom_control(keycode, data);
	if (keycode == LEFT || keycode == RIGHT)
		ret = lr_control(keycode, data);
	if (keycode == UP || keycode == DOWN)
		ret = ud_control(keycode, data);
	if (keycode == NUM1 || keycode == NUM2)
		ret = control_x(keycode, data);
	if (keycode == NUM3 || keycode == NUM4)
		ret = control_y(keycode, data);
	if (keycode == NUM5 || keycode == NUM6)
		ret = control_z(keycode, data);
	if (keycode == ISO || keycode == PARALLEL)
		ret = control_projection(keycode, data);
	if (ret == 1)
		redraw(data);
	return (0);
}
