/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:13:37 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/07 17:46:06 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

/*
malloc, free, write, va_start, va_arg, va_copy, va_end
1. parsing
	0. %
	1.플래그
	2.폭 -0.* field width
	3.정밀도
	4.길이
	5.서식지정자 cspdiuxX%
2. ar to create library.
*/
// %[flag][width][.precision][length]서식지정자

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

void	init_format(t_format *format)
{
	format->percentage = 0;
	format->index = 0;
	format->flag = 0;
	format->width = 0;
	format->result = 0;
	format->dot = 0;
}

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

int		ft_printf(const char *str, ...)
{
	t_format	format;

	va_start(format.ap, str);
	init_format(&format);
	while (str[format.index])
	{
		format.percentage = check_percentage(str, &format);
		handle_percentage(str, &format);
		check_flag(str, &format);
		check_width(str, &format);
		check_dot(str, &format);
		if (str[format.index] == 'c')
			print_type_c(&format);
		else if (str[format.index] == 's')
		{
			print_type_s(&format);
		}
	}
	va_end(format.ap);
	return (format.result);
}

// int	main(void)
// {
// 	ft_printf("%-1s\n", "abc");
// 	ft_printf("%-2s\n", "abc");
// 	ft_printf("%-3s\n", "abc");
// 	ft_printf("%-4s\n", "abc");
// 	ft_printf("%-5s\n", "abc");
// 	ft_printf("%-6s\n", "abc");
// 	printf("=====printf=====\n");
// 	printf("%-1s\n", "abc");
// 	printf("%-2s\n", "abc");
// 	printf("%-3s\n", "abc");
// 	printf("%-4s\n", "abc");
// 	printf("%-5s\n", "abc");
// 	printf("%-6s\n", "abc");
//  }