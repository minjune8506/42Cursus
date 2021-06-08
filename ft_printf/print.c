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
#include <stdarg.h>
#include <stdio.h>

void			print_type_c(t_format *format)
{
	if (format->flag == 1)
	{
		ft_putchar(va_arg(format->ap, int));
		align_c(format);
	}
	else if (format->flag == 0 || format->width != 0)
	{
		align_c(format);
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
	char *s_str;
	
	s_str = va_arg(format->ap, char *);
	format->str_len = ft_strlen(s_str);
	//왼쪽 정렬
	if (format->flag == 1)
	{
		ft_putstr_s(format, s_str);
	}
	if (format->width != 0)
		align_s(format);
	//오른쪽 정렬
	if (format->flag == 0)
	{
		ft_putstr_s(format, s_str);
	}
	format->width = 0;
	format->flag = 0;
	format->str_len = 0;
	format->index++;
	format->result++;
}

void	align_c(t_format *format)
{
	int i;

	i = 1;
	while (i < format->width)
	{
		ft_putchar(' ');
		i++;
		format->result++;
	}
}

void	align_s(t_format *format)
{
	int i;
	
	i = 0;
	if (format->precision >= format->str_len)
	{
		i = format->str_len;
		while (i < format->width)
		{
			ft_putchar(' ');
			i++;
			format->result++;
		}
	}
	if (format->precision < format->str_len)
	{
		i = format->width - format->precision;
		if (format->precision == -1)
			i = format->width - 0;
		while (i > 0)
		{
			ft_putchar(' ');
			format->result++;
			i--;
		}
	}
}

void	ft_putstr_s(t_format *format, const char *s_str)
{
	int i;

	i = 0;

	if (format->precision < format->str_len && format->dot == 1)
	{
		while (i < format->precision)
		{
			ft_putchar(s_str[i]);
			format->result++;
			i++;
		}
	}
	else if (format->precision >= format->str_len)
	{
		ft_putstr(s_str);
		format->result += format->str_len;
	}
}
/*
precision : 0 -> width값 만큼 빈칸 출력, 문자 출력 x
precision : 1 -> width -1 값만큼 빈칸 출력, 문자 출력 1
precision : 2 -> width -2 값만큼 빈칸 출력, 문자 출력 2
*/