/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:44:28 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/08 09:44:29 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_dot(const char *str, t_format *format)
{
	if (str[format->index] == '.')
	{
		format->dot = 1;
		format->index++;
	}
}

void	check_precision(const char *str, t_format *format)
{
	if (!ft_strchr("cspduxX%", str[format->index] && is_digit(str, format) && format->dot == 1))
	{
		format->precision = ft_atoi(str, format);
	}
}