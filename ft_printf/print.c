/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:42:06 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/08 12:42:07 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_type_c(t_format *format)
{
	if (format->flag == 1)
	{
		ft_putchar(va_arg(format->ap, int));
		align(format);
	}
	else if (format->flag == 0 || format->width != 0)
	{
		align(format);
		ft_putchar(va_arg(format->ap, int));
	}
	else
		ft_putchar(va_arg(format->ap, int));
	format->width = 0;
	format->flag = 0;
	format->index++;
	format->result++;
}

void	print_type_s(t_format *format)
{
	if (format->flag == 1)
	{
		ft_putstr(va_arg(format->ap, char *));
		align(format);
	}
	else if (format->flag == 0 || format->width != 0)
	{
		align(format);
		ft_putstr(va_arg(format->ap, char *));
	}
	format->width = 0;
	format->flag = 0;
	format->index++;
	format->result++;
}
