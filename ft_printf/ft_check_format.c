/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:14:43 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/08 20:14:44 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void check_per(t_format *format, const char *str)
{
	if (str[format->index] == '%')
		format->per = 1;
	else
		format->per = 0;
}

void	check_dot(t_format *format, const char *str)
{
	if (str[format->index] == '.')
	{
		format->dot = 1;
		format->index++;
	}
}