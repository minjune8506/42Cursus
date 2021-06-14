/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:52:52 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/09 15:28:32 by minjune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format(t_format *format)
{
	format->per = 0;
	format->flag_zero = 0;
	format->flag_plus = 0;
	format->flag_blank = 0;
	format->sharp = 0;
	format->flag_minus = 0;
	format->width = 0;
	format->dot = 0;
	format->prec = -1;
	format->type = ' ';
}

void	init_other(t_format *format)
{
	format->ret = 0;
	format->index = 0;
}

int		get_format(t_format *format, const char *str)
{
	get_per(format, str);
	get_flag(format, str);
	if (get_width(format, str) == -1)
		return (-1);
	if (get_prec(format, str) == -1)
		return (-1);
	get_type(format, str);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	t_format format;

	va_start(format.ap, str);
	init_other(&format);
	while (str[format.index])
	{
		init_format(&format);
		if (get_format(&format, str) == -1)
			return (-1);
		if (str[format.index] == 'c')
			type_c(&format);
		else if (str[format.index] == 's')
			type_s(&format);
		else if (str[format.index] == 'd' || str[format.index] == 'i')
			type_d(&format);
		else if (str[format.index] == 'u')
			type_u(&format);
		else if (str[format.index] == 'x' || str[format.index] == 'X')
			type_x(&format);
		else if (str[format.index] == 'p')
			type_p(&format);
		else if (format.type == '%')
			type_per(&format);
	}
	return (format.ret);
}
