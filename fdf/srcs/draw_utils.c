/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:24:05 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/20 15:24:05 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	big(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	my_abs(float x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}
