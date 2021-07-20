/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:24:20 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/20 15:24:20 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void
	initialize(t_data **data)
{
	(*data)->project->alpha = 0;
	(*data)->project->beta = 0;
	(*data)->project->gamma = 0;
	(*data)->project->zoom = 1;
	(*data)->project->shift_x = 0;
	(*data)->project->shift_y = 0;
	(*data)->project->iso = 1;
}

static void
	win_size_init(t_data **data)
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

void
	zoom_init(t_data **data)
{
	float	zoom_x;
	float	zoom_y;
	int		i;
	int		j;

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
		(*data)->project->zoom++;
	}
}

void
	shift_init(t_data **data)
{
	float	center_x;
	float	center_y;
	float	center_z;

	center_x = 0;
	center_y = (*data)->height - 1;
	center_z = (*data)->z_value[(int)center_y][(int)center_x];
	if ((*data)->project->iso)
		isometric(&center_x, &center_y, center_z);
	(*data)->project->shift_x = \
	(*data)->win_width / 2 - center_x * (*data)->project->zoom;
	(*data)->project->shift_y = \
	(*data)->win_height - center_y * (*data)->project->zoom;
}

void
	init(t_data **data)
{
	initialize(data);
	win_size_init(data);
	zoom_init(data);
	shift_init(data);
}
