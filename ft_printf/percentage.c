/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:39:46 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/08 12:39:47 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_percentage(const char *str, t_format *format)
{
	if (str[format->index] == '%')
	{
		return (1);
	}
	return (0);
}

void	handle_percentage(const char *str, t_format *format)
{
	if (format->percentage)
		format->index++;
	else
	{
		while (str[format->index] != '%' && str[format->index])
		{
			ft_putchar(str[format->index]);
			format->index++;
			format->result++;
		}
	}
}
