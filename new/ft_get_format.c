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

void	get_per(t_format *format, const char *str)
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

void	get_flag(t_format *format, const char *str)
{
	while (str[format->index] == '-')
	{
		format->flag = 1;
		format->index++;
	}
	while (str[format->index] == '0')
	{
		format->flag = 2;
		format->index++;
	}
}

void	get_width(t_format *format, const char *str)
{
	if (!(ft_strchr("cspduxX%", str[format->index])) && is_digit(str, format))
	{
		format->width = ft_atoi(str, format);
	}
	else if (str[format->index] == '*')
	{
		format->width = va_arg(format->ap, int);
		if (format->width < 0)
		{
			format->flag = 1;
			format->width *= -1;
		}
		format->index++;
	}
}

void	get_prec(t_format *format, const char *str)
{
	check_dot(format, str);
	if (format->dot)
	{
		if (!(ft_strchr("cspdiuxX%", str[format->index])) && is_digit(str, format))
		{
			format->prec = ft_atoi(str, format);
		}
		else if (ft_strchr("cspdiuxX%", str[format->index]))
		{
			format->prec = 0;
		}
		else if (str[format->index] == '*')
		{
			format->prec = va_arg(format->ap, int);
			if (format->prec < 0)
				format->prec = -1;
			format->index++;
		}
	}
}