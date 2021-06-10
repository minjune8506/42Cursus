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

void init_format(t_format *format)
{
	format->per = 0;
	format->width = 0;
	format->dot = 0;
	format->prec = -1;
	format->flag_minus = 0;
	format->flag_zero = 0;
	format->flag_plus = 0;
	format->flag_blank = 0;
	format->flag_sharp = 0;
}

void get_format(t_format *format, const char *str)
{
	get_per(format, str);
	get_flag(format, str);
	get_width(format, str);
	get_prec(format, str);
}

#include <stdio.h>

int ft_printf(const char *str, ...)
{
	t_format format;

	va_start(format.ap, str);
	format.ret = 0;
	format.index = 0;
	while (str[format.index])
	{
		init_format(&format);
		get_format(&format, str);
		if (str[format.index] == 'c')
			type_c(&format);
		else if (str[format.index] == 's')
			type_s(&format);
		else if (str[format.index] == 'd' || str[format.index] == 'i')
			type_d(&format);
		while (1)
		{
		
		}
	}
	// printf("format->per : %d\n", format.per);
	// printf("format->flag : %d\n", format.flag);
	// printf("format->width : %d\n", format.width);
	// printf("format->dot : %d\n", format.dot);
	// printf("format->precision : %d\n", format.prec);
	// printf("format->ret : %d\n", format.ret);
	return (format.ret);
}

int main(void)
{
	ft_printf("%+03.*d\n", -4, 0);
	printf("---------------\n");
	printf("%+03.*d\n",-4, 0);
}
// 	// ft_printf("-->|%-1.s|<--\n", -135);
	// ft_printf("-->|%-1.s|<--\n", -1);
	// ft_printf("-->|%-1.s|<--\n", 0);
	// ft_printf("-->|%-1.s|<--\n", 1);
	// ft_printf("-->|%-1.s|<--\n", 13);
	// ft_printf("-->|%-1.s|<--\n", 198);
	// printf("---------\n");
	// printf("-->|%-1.s|<--\n", -135);
	// printf("-->|%-1.s|<--\n", -1);
	// printf("-->|%-1.s|<--\n", 0);
	// printf("-->|%-1.s|<--\n", 1);
	// printf("-->|%-1.s|<--\n", 13);
	// printf("-->|%-1.s|<--\n", 198);
	// ft_printf("%s\n", "HELLO");
	// ft_printf("%6.s\n", "HELLO");
	// ft_printf("%3.s\n", "HELLO");
	// ft_printf("%4.2s\n", "HELLO");
	// ft_printf("%4.6s\n", "HELLO");
	// printf("------------\n");
	// printf("%s\n", "HELLO");
	// printf("%6.s\n", "HELLO");
	// printf("%3.s\n", "HELLO");
	// printf("%4.2s\n", "HELLO");
	// printf("%4.6s\n", "HELLO");
	// ft_printf("%.*s\n", -4, "HELLO");
	// printf("%.*s\n", -4, "HELLO");
	// ft_printf("-->|%-16.*s|<--\n", -4, "abc");
	// ft_printf("-->|%-16.*s|<--\n", -4, "");
	// printf("--------------\n");
	// printf("-->|%-16.*s|<--\n", -4, "abc");
	// printf("-->|%-16.*s|<--\n", -4, "");
	// printf("%d\n", 100);
// 	printf("%4.2d\n", -100);
// 	printf("%5.2d\n", -100);
// 	printf("%6.3d\n", -100);
// 	ft_printf("%s\n", NULL);
