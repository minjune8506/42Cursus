/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:24:55 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/20 15:24:56 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_dda *com, t_data **data)
{
	com->x *= (*data)->project->zoom;
	com->y *= (*data)->project->zoom;
	com->x1 *= (*data)->project->zoom;
	com->y1 *= (*data)->project->zoom;
	com->z *= (*data)->project->zoom;
	com->z1 *= (*data)->project->zoom;
}

void	shift(t_data **data, t_dda *com)
{
	com->x += (*data)->project->shift_x;
	com->y += (*data)->project->shift_y;
	com->x1 += (*data)->project->shift_x;
	com->y1 += (*data)->project->shift_y;
}
