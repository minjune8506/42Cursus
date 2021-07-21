/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:23:58 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/20 15:23:59 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

void
	init_dda(t_point point, t_dda *com)
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

void
	get_data(t_data **data, t_dda *com)
{
	com->z = (*data)->z_value[(int)com->y][(int)com->x];
	com->z1 = (*data)->z_value[(int)com->y1][(int)com->x1];
	com->color = (*data)->color[(int)com->y][(int)com->x];
	if (com->color == 0)
		com->color = 0xFFFFFF;
}

static void
	my_pixel_put(t_data **data, int x, int y, int color)
{
	char	*dst;

	dst = (*data)->img->addr + \
	(y * (*data)->img->line_size + x * (*data)->img->bps / 8);
	*(unsigned int *)dst = color;
}

static void
	dda(t_data **data, t_dda *com)
{
	int	i;

	i = 0;
	com->step = big(my_abs(com->x1 - com->x), my_abs(com->y1 - com->y));
	com->xinc = (com->x1 - com->x) / com->step;
	com->yinc = (com->y1 - com->y) / com->step;
	while (i <= com->step)
	{
		if (com->x >= 0 && com->x <= (*data)->win_width && \
		com->y >= 0 && com->y <= (*data)->win_height)
			my_pixel_put(data, com->x, com->y, com->color);
		com->x += com->xinc;
		com->y += com->yinc;
		i++;
	}
}

void
	draw(t_data **data)
{
	t_point	point;
	t_dda	com;

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
}
