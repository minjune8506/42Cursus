/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:03:04 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/08 20:03:05 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	get_per(t_format *format, const char *str)
{
	check_per(format, str);
	if (format->per)
		format->index++;
	else
	{
		while (str[format->index] != '%' && str[format->index])
		{
			ft_putchar(str[format->index]);
			format->index++;
			format->ret++;
		}
	}
}

void
	get_flag(t_format *format, const char *str)
{
	while (ft_strchr("-+0 #", str[format->index]))
	{
		if (str[format->index] == '-')
			format->flag_minus = 1;
		else if (str[format->index] == '0')
			format->flag_zero = 1;
		else if (str[format->index] == '+')
			format->flag_plus = 1;
		else if (str[format->index] == '#')
			format->sharp = 1;
		else if (str[format->index] == ' ')
			format->flag_blank = 1;
		format->index++;
	}
}

int
	get_width(t_format *format, const char *str)
{
	if (!(ft_strchr("cspdiuxX%", str[format->index])) && is_digit(str, format))
	{
		format->width = ft_atoi(str, format);
	}
	else if (str[format->index] == '*')
	{
		format->width = va_arg(format->ap, int);
		if (format->width < 0)
		{
			format->flag_minus = 1;
			format->width *= -1;
		}
		format->index++;
	}
	if (format->width > 2147483646)
		return (-1);
	return (0);
}

int
	get_prec(t_format *format, const char *str)
{
	check_dot(format, str);
	if (format->dot)
	{
		if (!(ft_strchr("cspdiuxX%", str[format->index]))
			&& is_digit(str, format))
			format->prec = ft_atoi(str, format);
		else if (ft_strchr("cspdiuxX%", str[format->index]))
			format->prec = 0;
		else if (str[format->index] == '*')
		{
			format->prec = va_arg(format->ap, int);
			if (format->prec < 0)
				format->prec = -1;
			format->index++;
		}
	}
	if (format->prec > 2147483646)
		return (-1);
	return (0);
}

void
	get_type(t_format *format, const char *str)
{
	if (format->per == 1)
		format->type = str[format->index];
}
